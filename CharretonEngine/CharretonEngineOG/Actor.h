#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"

class Actor : Entity {
public:

	Actor() = default;

	Actor(std::string actorName);

	virtual ~Actor() = default;

	void update(float deltaTime) override;

	void render(Window& window) override; // @param window Contexto del dispositivo para operaciones gr?ficas.

	void destroy(); // @brief Destruye el actor y libera los recursos asociados.

	// @brief Obtiene un componente espec?fico del actor.
	// @param T Tipo del componente que se va a obtener.
	// @return Puntero compartido al componente, o nullptr si no se encuentra.
	template <typename T>
	EngineUtilities::TSharedPointer<T>
		getComponent(); //Llamar una funcion InLine :p

private:
	std::string m_name = "Actor"; //Nombre del actor


};
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
	for (auto& component : components) {
		EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
		if (specificComponent) {
			return specificComponent;
		}
	}
	// Devuelve un TSharedPointer vac?o si no se encuentra el componente
	return EngineUtilities::TSharedPointer<T>();
}