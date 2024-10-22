#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "Actor.h"

class
  BaseApp {
public:
  //Constructor
  BaseApp() = default;

  //Destructor
  ~BaseApp() = default;

  // Funcion encargada de ejecutar la aplicacion en main
  int
    run();

  // Funcion de inicializacion
  bool
    initialize();

  // Funcion que se actualiza por frame
  void
    update();

  // Funcion de renderizado
  void
    render();
  //Funcion de liberacion de memoria
  void
    cleanup();
  //Funcion para el patron de patrullaje que se le asigna a una figura
  void
    patrolPattern(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:

  sf::Texture texture;

  std::vector<sf::Vector2f> waypoints = {
        sf::Vector2f(280.0f, 460.0f),
        sf::Vector2f(350.0f, 460.0f),
        sf::Vector2f(400.0f, 50.0f),
        sf::Vector2f(100.0f, 70.0f),
        sf::Vector2f(220.0f, 220.0f),
        sf::Vector2f(50.0f, 460.0f)
  };
  int currentPoint = 0;

  Window* m_window;
  sf::CircleShape* shape;
  EngineUtilities::TSharedPointer<Actor> Triangle;
  EngineUtilities::TSharedPointer<Actor> Circle;
  EngineUtilities::TSharedPointer<Actor> Circuit;
};