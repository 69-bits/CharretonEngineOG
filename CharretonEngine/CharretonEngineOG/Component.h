#pragma once
class Window;

enum ComponentType{
	EMPTY = 0,
	TRANSFORM = 1,
	SPRITE = 2,
	RENDERER = 3,
	PHYSICS = 4,
	AUDIOSOURCE = 5,
	SHAPE = 6
};

class 
Component{

public:
	Component() = default;

	Component(const ComponentType type) : m_type(type){}
	

	virtual 
	~Component() = default;

	virtual void 
	update(float deltatime) = 0;

	virtual void 
	render(Window window) = 0;

	ComponentType
		getType() const { return m_type; }

protected:
	ComponentType m_type; //Tipo de componente
};