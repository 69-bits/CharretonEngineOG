#include "BaseApp.h"

/**
 * @brief Punto de entrada principal de la aplicación.
 *
 * La función `main` crea una instancia de `BaseApp` y llama a su método `run` para
 * iniciar el bucle principal de la aplicación.
 *
 * @return Código de retorno de la aplicación, donde 0 indica que terminó correctamente.
 */
int 
main() {
  BaseApp app;
  return app.run();
}
