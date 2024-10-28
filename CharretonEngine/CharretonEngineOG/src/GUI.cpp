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

//void GUI::console(ConsoleErrorType msgType, const std::string& _msg)
//{
//  ImGui::Begin("console");
//  switch (msgType) {
//      case ConsoleErrorType::NORMAL:
//        return ImGui::TextColored(ImVec4(1, 1, 1, 1), "[NORMAL]: %s", _msg.second.c_str());
//        break;
//      case ConsoleErrorType::WARNING:
//        std::cout << "[WARNING]: ";
//        break;
//      case ConsoleErrorType::ERROR:
//        std::cout << "[ERROR]: ";
//        break;
//      }
//  ImGui::End();
//}

void 
GUI::console(std::map<ConsoleErrorType, std::string> m_programMessage) {
  ImGui::Begin("console");

  for (auto itr = m_programMessage.begin(); itr != m_programMessage.end(); itr++) {
    switch (itr->first) {
    case ConsoleErrorType::NORMAL:
      ImGui::TextColored(ImVec4(0, 1, 0, 1), "[NORMAL]: %s", itr->second.c_str()); // Color verde
      break;
    case ConsoleErrorType::WARNING:
      ImGui::TextColored(ImVec4(1, 1, 0, 1), "[WARNING]: %s", itr->second.c_str()); // Color amarillo
      break;
    case ConsoleErrorType::ERROR:
      ImGui::TextColored(ImVec4(1, 0, 0, 1), "[ERROR]: %s", itr->second.c_str()); // Color rojo
      break;
    }
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

