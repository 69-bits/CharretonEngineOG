#pragma once
#include "Prerequisites.h"
class Window;

class
	GUI {
public:
	GUI() = default;
	~GUI() = default;
	void
		init();
	void
		update();
	void
		render();
	void
		destroy();
	void
		setupGUIStyle();
	void
	console(std::map<ConsoleErrorType, std::string> m_programMessage);
	//void
	//	errorManagement(ConsoleErrorType type);
private:
};