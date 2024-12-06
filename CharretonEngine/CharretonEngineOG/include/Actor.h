#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"
#include "Transform.h"
#include "Window.h"

/**
 * @class Actor
 * @brief Representa un actor en la escena, hereda de la clase Entity y contiene componentes como ShapeFactory y Transform.
 */
class Actor : public Entity {
public:
  /**
   * @brief Constructor por defecto.
   */
  Actor() = default;

  /**
   * @brief Constructor que inicializa el actor con un nombre específico.
   * @param actorName Nombre del actor.
   */
  Actor(std::string actorName);

  /**
   * @brief Destructor virtual de Actor.
   */
  virtual 
  ~Actor() = default;

  /**
   * @brief Actualiza el estado del actor.
   * @param deltaTime Tiempo transcurrido desde la última actualización.
   */
  void 
  update(float deltaTime) override;

  /**
   * @brief Renderiza el actor en el contexto de la ventana.
   * @param window Referencia a la ventana donde se realizan las operaciones gráficas.
   */
  void 
  render(Window& window) override;

  /**
   * @brief Destruye el actor y libera los recursos asociados.
   */
  void 
  destroy();

  /**
  * @brief Función para obtener únicamente el nombre del actor
  */
  std::string
    getName() const;

  /**
   * @brief Permite la modificación del nombre del actor
   */
  void
    setName(const std::string& newName);

  /**
   * @brief Obtiene un componente específico del actor, basado en el tipo T.
   *
   * Esta función utiliza el tipo de dato especificado como parámetro para buscar
   * entre los componentes del actor y devolver el componente solicitado, si existe.
   *
   * @tparam T Tipo del componente que se desea obtener.
   * @return EngineUtilities::TSharedPointer<T> Puntero compartido al componente, o un TSharedPointer vacío si no se encuentra.
   */
  template <typename T>
  EngineUtilities::TSharedPointer<T> getComponent();

   std::string m_name = "Actor"; ///< Nombre del actor.

private:
 
};


template<typename T>
inline EngineUtilities::TSharedPointer<T> Actor::getComponent() {
  for (auto& component : components) {
    EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
    if (specificComponent) {
      return specificComponent;
    }
  }
  // Devuelve un TSharedPointer vacío si no se encuentra el componente
  return EngineUtilities::TSharedPointer<T>();
}
