#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class
  ShapeFactory : public Component {
public:

  //Constructor
  ShapeFactory() = default;

  //Destructor
  virtual
    ~ShapeFactory() = default;

  ShapeFactory(ShapeType shapeType) :
    m_shape(nullptr), m_shapeType(ShapeType::NONE), Component(ComponentType::SHAPE) {}

  sf::Shape*
    createShape(ShapeType shapeType);


  //Actualiza el componente de malla.
  void
    update(float detlatime) override {}


  void
    setPosition(float x, float y);

  void
    setRotation(float angle);

  void
    setScale(const sf::Vector2f& scl);

  void
    setFillColor(const sf::Color& color);


  void
    setPosition(const sf::Vector2f& position);

  /*void
    Seek(const sf::Vector2f& targetPosition,
      float speed,
      float deltaTime,
      float range);*/


  //Renderiza el componente de malla.
  void
    render(Window window) override {}


  sf::Shape*
    getShape() {
    return m_shape;
  }

private:
  ShapeType m_shapeType;
public:
  sf::Shape* m_shape;
};