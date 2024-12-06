#pragma once
#include "Prerequisites.h"
#include "Texture.h"

// La clase ResourceManager gestiona los recursos de texturas dentro de la aplicación.
class ResourceManager
{
public:
  // Constructor por defecto.
  ResourceManager() = default;

  // Destructor por defecto.
  ~ResourceManager() = default;

  // Intenta cargar una textura desde un archivo. Si la textura ya está cargada, evita recargarla.
  // @param filename: El nombre del archivo sin la extensión.
  // @param extension: La extensión del archivo.
  // @return True si la textura ya está cargada o se carga correctamente, False en caso contrario.
  bool 
  loadTExture(const std::string& filename, const std::string& extension) {
    // Verifica si la textura ya está cargada
    if (m_textures.find(filename) != m_textures.end())
    {
      return true;
    }
    // Crea un nuevo puntero compartido a una Textura
    EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>(filename, extension);
    // Almacena la textura en el mapa
    m_textures[filename] = texture;
  }

  // Obtiene un puntero compartido a una textura.
  // @param filename: El nombre de la textura que se desea recuperar.
  // @return Un puntero compartido a la Textura si se encuentra, o un puntero compartido vacío si no se encuentra.
  EngineUtilities::TSharedPointer<Texture>
    getTExture(const std::string& filename) {
    auto it = m_textures.find(filename);
    if (it != m_textures.end()) {
      return it->second;
    }

    return EngineUtilities::TSharedPointer<Texture>();
  }

  // Devuelve una referencia a la instancia única de ResourceManager.
  static 
  ResourceManager& getInstance() {
    static ResourceManager instance;
    return instance;
  }

private:
  // El constructor de copia está eliminado para prevenir la duplicación de la instancia singleton.
  ResourceManager(const ResourceManager&) = delete;

  // El operador de asignación de copia está eliminado para prevenir la duplicación de la instancia singleton.
  ResourceManager& operator*(const ResourceManager&) = delete;

  // Mapa que almacena las texturas, donde las claves son los nombres de archivo y los valores son punteros compartidos a objetos Texture.
  std::unordered_map<std::string, EngineUtilities::TSharedPointer<Texture>> m_textures;
};
