#include "ShapeFactory.h"


sf::Shape* ShapeFactory::createShape(ShapeType shapeType) {
  m_shapeType = shapeType;
  switch (shapeType) {
  case NONE: // No crea ninguna forma
    return nullptr;

  case CIRCLE: { // Círculo con radio de 10
    sf::CircleShape* circle = new sf::CircleShape(10.0f);
    circle->setFillColor(sf::Color::White);
    m_shape = circle;
    return circle;
  }

  case RECTANGLE: { // Rectángulo de tamaño 100x50
    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f));
    rectangle->setFillColor(sf::Color::White);
    m_shape = rectangle;
    return rectangle;
  }

  case TRIANGLE: { // Triángulo (círculo de 3 lados)
    sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3);
    triangle->setFillColor(sf::Color::White);
    m_shape = triangle;
    return triangle;
  }

  default: // Tipo de forma no reconocido
    return nullptr;
  }
}

void 
ShapeFactory::setPosition(float x, float y) {
  if (m_shape) {
    m_shape->setPosition(x, y);
  }
}

void 
ShapeFactory::setRotation(float angle) {
  if (m_shape) {
    m_shape->setRotation(angle);
  }
}

void 
ShapeFactory::setScale(const Vector2& scl) {
  if (m_shape) {
    m_shape->setScale(scl.x, scl.y); // Conversión explícita
  }
}

void 
ShapeFactory::setFillColor(const sf::Color& color) {
  if (m_shape) {
    m_shape->setFillColor(color);
  }
}

void
ShapeFactory::setPosition(const Vector2& position) {
  if (m_shape) {
    m_shape->setPosition(position.x, position.y);
  }
}

