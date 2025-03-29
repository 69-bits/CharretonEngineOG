# Motor de Videojuegos 2D - Proyecto de Gráficas

Este repositorio contiene el desarrollo de un motor de videojuegos 3D, implementado para gestionar y renderizar entidades y componentes mediante un sistema ECS (Entity Component System). Este proyecto incluye una interfaz de usuario personalizada utilizando **ImGui** y cuenta con funcionalidades para manipular y observar actores en un entorno 2D.

## Características Principales

### 1. Sistema ECS (Entity Component System)
   - **Clase `Actor` y Componentes**:
     - Los actores (`Actor`) son las entidades principales dentro del motor, y se les pueden añadir componentes para dotarlos de distintas funcionalidades.
     - Los componentes se encargan de gestionar propiedades específicas de cada actor, como posición, rotación, y visualización.
     - Este sistema facilita la organización y escalabilidad, al permitir agregar o modificar funcionalidades de manera dinámica.

### 2. Interfaz de Usuario - `UserInterface`
   - La interfaz de usuario fue desarrollada utilizando **ImGui**, proporcionando herramientas esenciales para la creación y manipulación de actores en el motor.
   - **Funciones de la Interfaz**:
     - **Consola**: Permite ver mensajes de estado, advertencias y errores generados en el motor, facilitando la depuración en tiempo real.
     - **Jerarquía**: Muestra una lista de todos los actores en la escena, organizados en una estructura jerárquica. Esta ventana permite seleccionar y modificar actores específicos.
     - **Place Actors**: Herramienta para añadir nuevos actores a la escena. Los actores pueden configurarse con distintos componentes desde el momento de su creación.
     - **Render Texture**: Muestra una vista en tiempo real de la escena renderizada, permitiendo observar los cambios y transformaciones aplicados en el entorno 3D.
     - **Inspector Básico**: Al seleccionar un actor en la jerarquía, esta herramienta permite ajustar sus propiedades, como posición, escala y rotación, así como añadir o eliminar componentes.

### 3. Movimiento de Actores
   - **Movimiento en 4 Puntos**:
     - Implementa un sistema de movimiento en el que un actor se desplaza a través de cuatro puntos predeterminados en el espacio 2D.
     - Este movimiento puede utilizarse para pruebas de animación, control de actores, y otras mecánicas de juego que requieran desplazamiento automático o guiado.
     - Este comportamiento de movimiento es configurable y se puede adaptar para distintos patrones.
