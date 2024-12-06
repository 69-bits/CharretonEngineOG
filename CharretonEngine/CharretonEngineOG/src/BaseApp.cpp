#include "BaseApp.h"
#include "NotifySingleton.h"
#include "ResourceManager.h"

// Inicializa la instancia estática del singleton NotifySingleton
NotifySingleton* NotifySingleton::m_instance = nullptr;

int 
BaseApp::run() {
  NotifySingleton* noty = NotifySingleton::getInstance();

  if (!initialize()) {
    noty->addMessage(ConsoleErrorType::ERROR, "Initializes result on a false statement, check method validations");
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
  ResourceManager& resourcemanager = ResourceManager::getInstance();
  // Configura la ventana principal
  m_window = new Window(1920, 1080, "Charreton Engine OG");
  if (!m_window) {
    noty->addMessage(ConsoleErrorType::ERROR, "initialize, Error on window creation, var is null");
    return false;
  }

  shape = new sf::CircleShape(10.0f);
  if (!shape) {
    noty->addMessage(ConsoleErrorType::ERROR, "initialize, Error on shape creation, var is null");
    return false;
  }

  // Inicializa el actor Circuit
  Circuit = EngineUtilities::MakeShared<Actor>("Circuit");
  if (!Circuit.isNull()) {
    Circuit->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

    Circuit->getComponent<Transform>()->setTransform(Vector2(10.0f, 10.0f),
      Vector2(0.0f, 0.0f), Vector2(5.0f, 10.0f));

   
   
    if (!resourcemanager.loadTExture("Circuit", "png")) {
      noty->addMessage(ConsoleErrorType::ERROR, "Esa textura no existe: Circuit");
    }

    EngineUtilities::TSharedPointer<Texture> trackTexture = resourcemanager.getTExture("Circuit");
    if (trackTexture) {
      Circuit->getComponent<ShapeFactory>()->getShape()->setTexture(&trackTexture->getTexture());
    } 
    m_actors.push_back(Circuit);
  }

  // Inicializa el actor Circle
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

    Circle->getComponent<Transform>()->setTransform(Vector2(280.0f, 460.0f),
      Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));



    if (!resourcemanager.loadTExture("tile012", "png")) {
      noty->addMessage(ConsoleErrorType::ERROR, "Esa textura no existe: Circle");
    }

    EngineUtilities::TSharedPointer<Texture> trackTexture = resourcemanager.getTExture("tile012");
    if (trackTexture) {
      Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&trackTexture->getTexture());
    }
    m_actors.push_back(Circle);
  }


  // Inicializa el actor Triangle
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
  }

  // Inicializa el actor Circle
  Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
  if (!Triangle.isNull()) {
    Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);

    Triangle->getComponent<Transform>()->setTransform(Vector2(280.0f, 460.0f),
      Vector2(0.0f, 0.0f), Vector2(1.0f, 1.0f));
    m_actors.push_back(Triangle);
  }

  return true;
}

void 
BaseApp::update() {
  m_window->update();

  for (auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->update(m_window->deltaTime.asSeconds());
    }
  }

}

void 
BaseApp::render() {
  NotifySingleton* noty = NotifySingleton::getInstance();

  m_window->clear();
  //m_window->draw(*shape);

  for (const auto& actor : m_actors) {
    if (!actor.isNull()) {
      actor->render(*m_window);
    }
  }

  m_window->renderToTexture();
  m_window->showInImGui();
  m_GUI.console(noty->showNotification());
  m_GUI.hierarchy(m_actors);
  //m_GUI.actor(m_actors);
  m_GUI.inspector(m_actors);
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

  Vector2 targetPos = waypoints[currentPoint];
  transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

  Vector2 currentPos = transform->getPosition();
  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    currentPoint = (currentPoint + 1) % waypoints.size();
  }
}
