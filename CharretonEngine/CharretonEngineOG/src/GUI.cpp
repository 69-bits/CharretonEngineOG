#include "GUI.h"
#include "Window.h"
#include "NotifySingleton.h"
#include "imgui_internal.h"



void 
GUI::init() {
  setupGUIStyle();
}

void 
GUI::update() {
}

void 
GUI::render() {
}

void 
GUI::destroy() {
}

void 
GUI::setupGUIStyle() {
  ImGuiStyle& style = ImGui::GetStyle();

  style.FrameBorderSize = 1.0f;
  style.WindowBorderSize = 1.0f;

  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.1f, 1.0f); // Fondo oscuro
  colors[ImGuiCol_Border] = ImVec4(0.9f, 0.7f, 0.0f, 1.0f);   // Color del borde
  colors[ImGuiCol_TitleBg] = ImVec4(0.8f, 0.4f, 0.0f, 1.0f);  // Fondo del título
  colors[ImGuiCol_TitleBgActive] = ImVec4(0.9f, 0.5f, 0.0f, 1.0f); // Fondo del título activo
}

void 
GUI::hierarchy(const std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actores) {
  ImGui::Begin("Hierarchy");

  ImGui::TextColored(ImVec4(1, 0, 1, 1), "%s", "Objetos creados en escena:\n");

  for (size_t i = 0; i < m_actores.size(); ++i) {
    const auto& actor = m_actores[i];
    if (actor) {
      if (ImGui::Selectable(actor->m_name.c_str(), selectedActorIndex == static_cast<int>(i))) {
        selectedActorIndex = static_cast<int>(i);
      }
    }
  }
  ImGui::End();
}

void 
GUI::console(std::map<ConsoleErrorType, std::vector<std::string>> m_programMessage) {
  ImGui::Begin("Console");

  for (const auto& message : m_programMessage) {
    for (const std::string& msg : message.second) {
      std::string formattedMessage;
      switch (message.first) {
      case ConsoleErrorType::NORMAL:
        formattedMessage = "[NORMAL]: " + msg;
        ImGui::TextColored(ImVec4(0, 1, 0, 1), "%s", formattedMessage.c_str());
        break;
      case ConsoleErrorType::WARNING:
        formattedMessage = "[WARNING]: " + msg;
        ImGui::TextColored(ImVec4(1, 0.5f, 0, 1), "%s", formattedMessage.c_str());
        break;
      case ConsoleErrorType::ERROR:
        formattedMessage = "[ERROR]: " + msg;
        ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", formattedMessage.c_str());
        break;
      }
    }
  }

  ImGui::End();
}

#include "NotifySingleton.h"

void
GUI::actor(std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actores) {
  ImGui::Begin("Actor Generator");

  // Obtener la instancia del NotifySingleton
  NotifySingleton* noty = NotifySingleton::getInstance();

  static int circleCount = 0;
  static int rectangleCount = 0;
  static int triangleCount = 0;

  ImGui::PushID("Button1");
  if (ImGui::Button("Create Circle Actor")) {
    std::string actorName = "Circle_" + std::to_string(++circleCount);
    auto DAm = EngineUtilities::MakeShared<Actor>(actorName);

    if (!DAm.isNull()) {
      DAm->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
      DAm->getComponent<ShapeFactory>()->setFillColor(sf::Color::Magenta);

      DAm->getComponent<Transform>()->setPosition(Vector2(280.0f, 460.0f));
      DAm->getComponent<Transform>()->setRotation(Vector2(0.0f, 0.0f));
      DAm->getComponent<Transform>()->setScale(Vector2(1.0f, 1.0f));

      m_actores.push_back(DAm);
      std::cout << "Actor creado: " << actorName << ", total de actores en m_actors: " << m_actores.size() << std::endl;

      // Agregar mensaje de notificación
      noty->addMessage(ConsoleErrorType::NORMAL, "Circle Actor created with name: " + actorName);
    }
  }
  ImGui::PopID();
  ImGui::Separator();

  ImGui::PushID("Button2");
  if (ImGui::Button("Create Rectangle Actor")) {
    std::string actorName = "Rectangle_" + std::to_string(++rectangleCount);
    auto DAm = EngineUtilities::MakeShared<Actor>(actorName);

    if (!DAm.isNull()) {
      DAm->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);
      DAm->getComponent<ShapeFactory>()->setFillColor(sf::Color::Magenta);

      DAm->getComponent<Transform>()->setPosition(Vector2(280.0f, 460.0f));
      DAm->getComponent<Transform>()->setRotation(Vector2(0.0f, 0.0f));
      DAm->getComponent<Transform>()->setScale(Vector2(1.0f, 1.0f));

      m_actores.push_back(DAm);
      std::cout << "Actor creado: " << actorName << ", total de actores en m_actors: " << m_actores.size() << std::endl;

      // Agregar mensaje de notificación
      noty->addMessage(ConsoleErrorType::NORMAL, "Rectangle Actor created with name: " + actorName);
    }
  }
  ImGui::PopID();
  ImGui::Separator();

  ImGui::PushID("Button3");
  if (ImGui::Button("Create Triangle Actor")) {
    std::string actorName = "Triangle_" + std::to_string(++triangleCount);
    auto DAm = EngineUtilities::MakeShared<Actor>(actorName);

    if (!DAm.isNull()) {
      DAm->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
      DAm->getComponent<ShapeFactory>()->setFillColor(sf::Color::Magenta);

      DAm->getComponent<Transform>()->setPosition(Vector2(280.0f, 460.0f));
      DAm->getComponent<Transform>()->setRotation(Vector2(0.0f, 0.0f));
      DAm->getComponent<Transform>()->setScale(Vector2(1.0f, 1.0f));

      m_actores.push_back(DAm);
      std::cout << "Actor creado: " << actorName << ", total de actores en m_actors: " << m_actores.size() << std::endl;

      // Agregar mensaje de notificación
      noty->addMessage(ConsoleErrorType::NORMAL, "Triangle Actor created with name: " + actorName);
    }
  }
  ImGui::PopID();
  ImGui::End();
}

void GUI::vec3Control(const std::string& label, float* values, float resetValue, float columnWidth) {
  ImGuiIO& io = ImGui::GetIO();
  auto boldFont = io.Fonts->Fonts[0];

  ImGui::PushID(label.c_str());

  ImGui::Columns(2);
  ImGui::SetColumnWidth(0, columnWidth);
  ImGui::Text(label.c_str());
  ImGui::NextColumn();

  ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
  ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

  float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
  ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
  ImGui::PushFont(boldFont);
  if (ImGui::Button("X", buttonSize)) values[0] = resetValue;
  ImGui::PopFont();
  ImGui::PopStyleColor(3);

  ImGui::SameLine();
  ImGui::DragFloat("##X", &values[0], 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
  ImGui::PushFont(boldFont);
  if (ImGui::Button("Y", buttonSize)) values[1] = resetValue;
  ImGui::PopFont();
  ImGui::PopStyleColor(3);

  ImGui::SameLine();
  ImGui::DragFloat("##Y", &values[1], 0.1f, 0.0f, 0.0f, "%.2f");
  ImGui::PopItemWidth();
  ImGui::SameLine();

  ImGui::PopStyleVar();
  ImGui::Columns(1);

  ImGui::PopID();
}

void GUI::inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& m_actores) {
  ImGui::Begin("Inspector");

  if (selectedActorIndex >= 0 && selectedActorIndex < static_cast<int>(m_actores.size())) {
    auto& selectedActor = m_actores[selectedActorIndex];
    if (selectedActor) {
      ImGui::Separator();
      ImGui::Text("Propiedades del Actor seleccionado:");

      // Modificación de posición y escala
      Vector2 position = selectedActor->getComponent<Transform>()->getPosition();
      if (ImGui::DragFloat2("Position", reinterpret_cast<float*>(&position), 1.0f)) {
        selectedActor->getComponent<Transform>()->setPosition(position);
      }
      Vector2 scale = selectedActor->getComponent<Transform>()->getScale();
      if (ImGui::DragFloat2("Scale", reinterpret_cast<float*>(&scale), 1.0f)) {
        selectedActor->getComponent<Transform>()->setScale(scale);
      }

      Vector2 rotation = selectedActor->getComponent<Transform>()->getRotation();
      if (ImGui::DragFloat2("Rotation", reinterpret_cast<float*>(&rotation), 1.0f)) {
        selectedActor->getComponent<Transform>()->setRotation(rotation);
      }

      static int currentShapeTypeIndex = 0;
      const char* shapeTypes[] = { "EMPTY", "CIRCLE", "RECTANGLE", "TRIANGLE" };

      if (ImGui::Combo("Shape Type", &currentShapeTypeIndex, shapeTypes, IM_ARRAYSIZE(shapeTypes))) {
        ShapeType selectedShapeType = static_cast<ShapeType>(currentShapeTypeIndex);
        selectedActor->getComponent<ShapeFactory>()->createShape(selectedShapeType);
      }
    }
  }
  ImGui::End();
}
