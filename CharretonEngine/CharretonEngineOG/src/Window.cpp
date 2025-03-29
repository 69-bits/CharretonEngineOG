#include "Window.h"

Window::Window(int width, int height, const std::string& title) {
  m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

  if (!m_window) {
    ERROR("Window", "RenderTexture", "CHECK CREATION");
  }
  else {
    MESSAGE("Window", "Window", "OK");
  }

  ImGui::SFML::Init(*m_window); // Inicializar ImGui

  // Crear RenderTexture con las mismas dimensiones que la ventana
  if (!m_renderTexture.create(width, height)) {
    ERROR("Window", "RenderTexture", "CHECK CREATION");
  }
}

Window::~Window() {
  ImGui::SFML::Shutdown();
  delete m_window;
}

void 
Window::renderToTexture() {
  m_renderTexture.display();
}


void 
Window::showInImGui() {

  const sf::Texture& texture = m_renderTexture.getTexture();
  ImVec2 size(texture.getSize().x, texture.getSize().y);

  ImGui::Begin("Scene");
  ImGui::Image((void*)(intptr_t)texture.getNativeHandle(), size, ImVec2(0, 1), ImVec2(1, 0));
  ImGui::End();
}


void 
Window::handleEvents() {
  sf::Event event;
  while (m_window->pollEvent(event)) {
    ImGui::SFML::ProcessEvent(event);
    switch (event.type) {
    case sf::Event::Closed:
      m_window->close();
      break;
    case sf::Event::Resized:
      unsigned int width = event.size.width;
      unsigned int height = event.size.height;

      m_view = m_window->getView();
      m_view.setSize(static_cast<float>(width), static_cast<float>(height));
      m_window->setView(m_view);

      m_renderTexture.create(width, height);
      break;
    }
  }
}

void 
Window::clear() {
  if (m_window != nullptr) {
    m_window->clear();
  }
  else {
    ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA");
  }
}

void 
Window::display() {
  if (m_window != nullptr) {
    m_window->display();
  }
  else {
    ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA");
  }
}


bool 
Window::isOpen() const {
  if (m_window != nullptr) {
    return m_window->isOpen();
  }
  else {
    ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA");
    return false;
  }
}


void 
Window::draw(const sf::Drawable& drawable) {
  if (m_renderTexture.getSize().x > 0 && m_renderTexture.getSize().y > 0) {
    m_renderTexture.draw(drawable);
  }
}


sf::RenderWindow* 
Window::getWindow() {
  if (m_window != nullptr) {
    return m_window;
  }
  else {
    ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA");
    return nullptr;
  }
}


void 
Window::update() {
  deltaTime = clock.restart();
  ImGui::SFML::Update(*m_window, deltaTime);
}

void 
Window::render() {
  ImGui::SFML::Render(*m_window);
}

void 
Window::destroy() {
  ImGui::SFML::Shutdown();
  SAFE_PTR_RELEASE(m_window);
}
