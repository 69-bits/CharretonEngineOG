#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"
#include "Vector2.h"

/**
 * @class Transform
 * @brief Componente de transformación que gestiona la posición, rotación y escala de una entidad.
 *
 * La clase `Transform` permite manipular la posición, rotación y escala de una entidad en la escena.
 * Además, proporciona un método de movimiento que permite al objeto dirigirse a una posición objetivo.
 */
class Transform : public Component {
public:
  /**
   * @brief Constructor por defecto que inicializa la posición en (0,0), la rotación en (0,0) y la escala en (1,1).
   */
  Transform() : position(0.0f, 0.0f),
    rotation(0.0f, 0.0f),
    scale(1.0f, 1.0f),
    Component(ComponentType::TRANSFORM) {}

  /**
   * @brief Destructor virtual por defecto.
   */
  virtual
  ~Transform() = default;

  /**
   * @brief Actualiza el componente de transformación.
   *
   * Este método se llama cada frame, pero en este caso no tiene implementación específica.
   * @param deltaTime Tiempo transcurrido desde el último frame.
   */
  void
  update(float deltaTime) override {}

  /**
   * @brief Renderiza el componente de transformación.
   *
   * No tiene implementación específica en este caso.
   * @param window Ventana donde se renderizaría la transformación.
   */
  void
  render(Window window) override {}

  /**
   * @brief Libera recursos asociados al componente de transformación.
   */
  void
  destroy();

  /**
   * @brief Establece la posición del objeto.
   * @param _position Nueva posición en la escena.
   */
  void
  setPosition(const Vector2& _position) {
    position = _position;
  }

  /**
   * @brief Establece la rotación del objeto.
   * @param _rotation Nueva rotación en la escena.
   */
  void
  setRotation(const Vector2& _rotation) {
    rotation = _rotation;
  }

  /**
   * @brief Establece la escala del objeto.
   * @param _scale Nueva escala en la escena.
   */
  void
  setScale(const Vector2& _scale) {
    scale = _scale;
  }

  /**
   * @brief Mueve el objeto hacia una posición objetivo.
   *
   * Este método ajusta la posición del objeto en dirección a una posición de destino.
   * Solo se mueve si la distancia al objetivo es mayor que el rango especificado.
   *
   * @param targetPosition Posición objetivo hacia la que moverse.
   * @param speed Velocidad de movimiento.
   * @param deltaTime Tiempo transcurrido desde el último frame.
   * @param range Distancia mínima a la posición objetivo antes de detenerse.
   */
  void
  Seek(const Vector2& targetPosition,
      float speed,
      float deltaTime,
      float range) {
    Vector2 direction = (targetPosition)-position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length > range) {
      direction /= length;  // Normaliza el vector
      position += direction * speed * deltaTime;
    }
  }

  /**
   * @brief Obtiene la posición actual del objeto.
   * @return Referencia a la posición actual (`sf::Vector2f`).
   */
  Vector2&
  getPosition() {
    return position;
  }

  /**
   * @brief Obtiene la rotación actual del objeto.
   * @return Referencia a la rotación actual (`sf::Vector2f`).
   */
  Vector2&
  getRotation() {
    return rotation;
  }

  /**
   * @brief Obtiene la escala actual del objeto.
   * @return Referencia a la escala actual (`Vector2`).
   */
   /**
  * @brief Obtiene un puntero a la información de rotación.
  *
  * Esta función devuelve un puntero al primer elemento de la variable que almacena
  * la rotación en el eje x. Esto puede ser útil para operaciones que requieren acceso directo
  * a la memoria de la rotación, como la manipulación directa o el paso de datos a APIs
  * gráficas de bajo nivel que requieren punteros.
  *
  * @return float* Un puntero al primer componente de la rotación (eje x).
  */
  float*
  getRotationData() {
    return &rotation.x;
  }

  /**
   * @brief Obtiene un puntero a la información de escala.
   *
   * Similar a getRotationData, esta función devuelve un puntero al primer elemento de la
   * variable que almacena la escala en el eje x. Es útil para casos donde se necesita
   * manipulación directa o envío de esta parte de la información de transformación a otras
   * funciones o sistemas que operan a un nivel más bajo.
   *
   * @return float* Un puntero al primer componente de la escala (eje x).
   */
  float*
  getScaleData() {
    return &scale.x;
  }

  /**
   * @brief Establece los valores de transformación para un objeto.
   *
   * Esta función actualiza la posición, rotación y escala del objeto basándose en los
   * vectores proporcionados. Es útil para establecer todas las propiedades de transformación
   * de una vez, asegurando que todas las actualizaciones de estado se manejen juntas.
   *
   * @param pos Vector2 que representa la nueva posición.
   * @param rot Vector2 que representa la nueva rotación.
   * @param scl Vector2 que representa la nueva escala.
   */
  void
  setTransform(const Vector2& pos, const Vector2& rot, const Vector2& scl) {
    position = pos;
    rotation = rot;
    scale = scl;
  }


private:
  ShapeFactory* m_shape; ///< Puntero a un componente de `ShapeFactory` asociado (opcional).
  Vector2 position; ///< Posición del objeto en la escena.
  Vector2 rotation; ///< Rotación del objeto en la escena.
  Vector2 scale; ///< Escala del objeto en la escena.
};
