#pragma once
#include "Prerequisites.h"
#include "GUI.h"

class NotifySingleton {
public:
  // Constructor privado para evitar instanciaci?n directa
  NotifySingleton() {};

  // M?todo est?tico para obtener la instancia ?nica del RegistroActividad
  static 
  NotifySingleton* getInstance() {
    if (m_instance != nullptr) {
      return m_instance;
    }
    else {
      m_instance = new NotifySingleton;
    }
    return m_instance;
  }

  // Destructor por defecto
  ~NotifySingleton() = default;

  // M?todo para registrar una actividad en el registro
  void 
  addMessage(ConsoleErrorType msgType, const std::string& _msg) {
    m_programMessage.insert(make_pair(msgType, _msg));
  }

  void 
  notify(ConsoleErrorType msgType, const std::string& _msg) {
 
    GUI* gui;
    gui->console(m_programMessage);
  }

  // M?todo para obtener y mostrar las mensajes registrados
  /*void 
  getMessage() {
  }*/

  std::map<ConsoleErrorType, std::string> showNotification() {
    return m_programMessage;
  }

private:
  static NotifySingleton* m_instance; // Instancia Unica
  std::map<ConsoleErrorType, std::string> m_programMessage; // Mapa para almacenar las actividades registradas
};