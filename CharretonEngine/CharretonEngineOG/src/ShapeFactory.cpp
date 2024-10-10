#include "ShapeFactory.h"

sf::Shape* ShapeFactory::
createShape(ShapeType shapeType) {
  m_shapeType = shapeType;
  switch (shapeType) {
  case NONE: // Caso para "NONE", no hace nada y sigue adelante
    return nullptr;

  case CIRCLE: { // Caso para c?rculo
    sf::CircleShape* circle = new sf::CircleShape(10.0f); // C?rculo con radio de 10
    circle->setFillColor(sf::Color::White); // Color blanco
    m_shape = circle;
    return circle;
  }

  case RECTANGLE: { // Caso para rect?ngulo
    sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2f(100.0f, 50.0f)); // Tama?o 100x50
    rectangle->setFillColor(sf::Color::White); // Color blanco
    m_shape = rectangle;
    return rectangle;
  }

  case TRIANGLE: { // Caso para tri?ngulo
    sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // C?rculo de 3 lados (tri?ngulo)
    triangle->setFillColor(sf::Color::White); // Color blanco
    m_shape = triangle;
    return triangle;
  }

  default: // Caso por defecto si el tipo de forma no coincide con ninguno de los anteriores
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
ShapeFactory::setRotation(float angle){
  if (m_shape) {
    m_shape->setRotation(angle);
  }
}

void 
ShapeFactory::setScale(const sf::Vector2f& scl){
  if (m_shape) {
    m_shape->setScale(scl);
  }
}

void
ShapeFactory::setFillColor(const sf::Color& color) {
  m_shape->setFillColor(color);

}
void
ShapeFactory::setPosition(const sf::Vector2f& position) {
  if (m_shape) {
      m_shape->setPosition(position);
  }
  
}
/*
void
ShapeFactory::Seek(const sf::Vector2f& targetPosition,
  float speed,
  float deltaTime,
  float range) {

  //obtener la posicion actual de la shape sea la que sea
  sf::Vector2f shapePosition = m_shape->getPosition();


  //Calcular la direccion desde el circulo hacia el objetivo
  sf::Vector2f direction = targetPosition - shapePosition;


  //Calcular distacnia al objectivo
  float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

  //Si la distancia es mayor al rango, mover la shape al objetivo
  if (length > range) {
    direction /= length;
    m_shape->move(direction * speed * deltaTime);
  }
}*/

