#include "BaseApp.h"
#include "NotifySingleton.h"

NotifySingleton* NotifySingleton::m_instance = nullptr;

int
BaseApp::run() {
  NotifySingleton* noty = NotifySingleton::getInstance();

  if (!initialize()) {
    /*ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");*/
    noty->addMessage(ConsoleErrorType::ERROR,"Initializes result on a false statemente, check method validations");
  }
  m_GUI.init();
  while (m_window->isOpen()) {
    m_window->handleEvents();
    update();
    render();
  }

  cleanup();
  return 0;
}

bool
BaseApp::initialize() {
  NotifySingleton* noty = NotifySingleton::getInstance();
  m_window = new Window(1920, 1080, "Charreton Engine OG");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  shape = new sf::CircleShape(10.0f);

  if (!shape) {
    ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
    return false;
  }

  // Circuit Actor
  Circuit = EngineUtilities::MakeShared<Actor>("Circuit");
  if (!Circuit.isNull()) {
    Circuit->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
    //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

    Circuit->getComponent<Transform>()->setPosition(sf::Vector2f(10, 10.0f));
    Circuit->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Circuit->getComponent<Transform>()->setScale(sf::Vector2f(5.0f, 10.0f));

    if (!texture.loadFromFile("pingui.png")) {
      noty->addMessage(ConsoleErrorType::WARNING, "Esa textura no existe");
      return -1; //Manejar error de carga
    }

    Circuit->getComponent<ShapeFactory>()->getShape()->setTexture(&texture);
  }


  // Circle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
    //Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Magenta);

    Circle->getComponent<Transform>()->setPosition(sf::Vector2f(280.0f, 460.0f));
    Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
    Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));

    if (!shyGuy.loadFromFile("sprites/tile016.png")) {
      std::cout << "Error de carga de textura" << std::endl;
      return -1; //Manejar error de carga
    }

    Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&shyGuy);
  }

  // Triangle Actor
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
  }
  return true;
}

void
BaseApp::update() {

  //Update window method
  m_window->update();

  /*sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
    static_cast<float>(mousePosition.y));*/

  if (!Circuit.isNull()) {
    Circuit->update(m_window->deltaTime.asSeconds());
  }

  if (!Circle.isNull()) {
    Circle->update(m_window->deltaTime.asSeconds());
    patrolPattern(m_window->deltaTime.asSeconds(), Circle);
  }
}

void
BaseApp::render() {
  NotifySingleton* noty = NotifySingleton::getInstance();
  m_window->clear();
  m_window->draw(*shape);
  if (!Triangle.isNull()) {
    Triangle->render(*m_window);
  }
  if (!Circuit.isNull()) {
    Circuit->render(*m_window);
  }
  if (!Circle.isNull()) {
    Circle->render(*m_window);
  }
  // Mostrar el render en ImGui
  m_window->renderToTexture();  // Finaliza el render a la textura
  m_window->showInImGui();      // Muestra la textura en ImGui
  m_GUI.console(noty->showNotification());
  m_window->render();
  m_window->display();
}

void
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
}

void
BaseApp::patrolPattern(float deltaTime, EngineUtilities::TSharedPointer<Actor> circulo) {

  if (!circulo || circulo.isNull()) {
    return;
  }

  auto transform = circulo->getComponent<Transform>();
  if (transform.isNull()) {
    return;
  }

  sf::Vector2f targetPos = waypoints[currentPoint];

  transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

  sf::Vector2f currentPos = transform->getPosition();

  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    currentPoint = (currentPoint + 1) % waypoints.size();
  }
}