#include "BaseApp.h"

int
BaseApp::run() {
  if (!initialize()) {
    ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
  }
  while (m_window->isOpen()) {
    m_window->handleEvents();
    deltaTime = clock.restart();
    update();
    render();
  }

  cleanup();
  return 0;
}

bool
BaseApp::initialize() {
  m_window = new Window(800, 600, "Galvan Engine");
  if (!m_window) {
    ERROR("BaseApp", "initialize", "Error on window creation, var is null");
    return false;
  }
  shape = new sf::CircleShape(10.0f);

  if (!shape) {
    ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
    return false;
  }


  // Triangle Actor
  Circle = EngineUtilities::MakeShared<Actor>("Circle");
  if (!Circle.isNull()) {
    Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
    Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);

    Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
    Circle->getComponent<Transform>()->setRotation(sf::Vector2f(200.0f, 200.0f));
    Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
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

  /*sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
  sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
    static_cast<float>(mousePosition.y));*/


  if (!Circle.isNull()) {
    Circle->update(deltaTime.asSeconds());
    patrolPattern(deltaTime.asSeconds(), Circle);
  }
}

void
BaseApp::render() {
  m_window->clear();
  m_window->draw(*shape);
  if (!Triangle.isNull()) {
    Triangle->render(*m_window);
  }
  if (!Circle.isNull()) {
    Circle->render(*m_window);
  }

  m_window->display();
}

void
BaseApp::cleanup() {
  m_window->destroy();
  delete m_window;
  delete shape;
}

void
BaseApp::patrolPattern(float deltaTime, EngineUtilities::TSharedPointer<Actor> circulo) {

  if (!circulo || circulo.isNull()) return;

  sf::Vector2f targetPos = waypoints[currentPoint];

  circulo->getComponent<ShapeFactory>()->Seek(targetPos, 200.0f, deltaTime, 10.0f);

  sf::Vector2f currentPos = circulo->getComponent<ShapeFactory>()->getShape()->getPosition();

  float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

  if (distanceToTarget < 10.0f) {
    currentPoint = (currentPoint + 1) % waypoints.size();
  }
}