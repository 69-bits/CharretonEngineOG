#include "GUI.h"
#include "Window.h"
void
GUI::init() {
	// Setup GUI Style
	setupGUIStyle();
}
void GUI::update()
{
}
void GUI::render()
{
}
void
GUI::destroy() {
}
void
GUI::setupGUIStyle() {
  ImGuiStyle& style = ImGui::GetStyle();

  // Estilo de borde
  style.FrameBorderSize = 1.0f;
  style.WindowBorderSize = 1.0f;

  // Colores personalizados
  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // Fondo oscuro
  colors[ImGuiCol_Border] = ImVec4(0.9f, 0.7f, 0.0f, 1.0f);   // Color del borde
  colors[ImGuiCol_TitleBg] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f);  // Fondo del título (naranja)
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.9f, 0.5f, 0.0f, 1.0f); // Fondo del título activo (naranja más brillante)
}

void 
GUI::console(std::map<ConsoleErrorType, std::string> m_programMessage) {
  ImGui::Begin("console");
  for (auto itr = m_programMessage.begin(); itr != m_programMessage.end(); itr++) {
    // Convierte el tipo a string antes de imprimir
  
    ImGui::Text("%s: %s", itr->second.c_str());
  }
  ImGui::End();
}

//std::string GUI::errorManagement(ConsoleErrorType type)
//{
//  switch (type) {
//  case ConsoleErrorType::NORMAL:
//    return "[NORMAL]: ";
//    break;
//  case ConsoleErrorType::WARNING:
//    std::cout << "[WARNING]: ";
//    break;
//  case ConsoleErrorType::ERROR:
//    std::cout << "[ERROR]: ";
//    break;
//  }
//}

