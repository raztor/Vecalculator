# Vecalculator
[![wakatime](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340.svg)](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340)

## Sobre el proyecto
Introducción: Lo que nos llevó como grupo a pensar en la elaboración de una calculadora de vectores y todo lo que esto englobe principalmente fueron 2 razones, como una de las principales es hacer que la tarea del cálculo de vectores deje de ser un proceso tan engorroso además de enredado para muchos y convertirlo en algo más mecanizado de fácil uso y por último pensando tanto como en nosotros como alumnos a los cuales se nos complicó mucho nuestro primer acercamiento a la física de la educación superior, además como factor agregado creemos que nuestro proyecto en un futuro puede ser de gran ayuda para la comunidad universitaria que componemos.

Desarrollo: En las fases iniciales del trabajo en nuestro proyecto nos vimos enfrentados a pequeños problemas relacionados con la modularización y depuración de nuestro código, afortunadamente supimos sortearlos en su totalidad, para que a día de hoy poder tener un código más compacto y efectivo. A día de hoy, y casi habiendo terminado el desarrollo para la entrega el hito 2, creemos que aún mantenemos los principales objetivos del proyecto como meta, los cuales fueron mencionados anteriormente. En lo que pertenece a la documentación y recursos que hemos ido utilizando en nuestro trabajo, nos hemos visto enfrentados a pequeños inconvenientes que, hemos surcado de manera rápida y eficaz. Aunque como hice énfasis antes, a la hora de trabajar, siempre hemos priorizado los objetivos que nos propusimos al principio, en el caso de la documentación nos hemos esforzado en anotar todo, para que le resulte amigable al usuario promedio.

Lo que nosotros esperamos lograr en las fases finales de nuestro proyecto, hacer que nuestra calculadora sea funcional y viable en su totalidad, lograr que la interfaz grafica, sea amigable al usuario promedio y expandirlo en otros de los muchos horizontes pertenecientes a las ramas de la física.

# Version: 2.0.0

    Date: 2022-09-28
    License: GNU AGPLv3
    
    Cambios:
    - Lanzamiento 2.0
    - Añadimos calculo de componentes vectoriales 
    - Añadimos producto cruz de vectores 2D
    - Reestructuración del código
    - Añadida salida gráfica
    - Cambios del readme
    - Implementado filtro de char en input
    - Nuevas funciones de graficación
    - Cambios menores

    
    Por hacer:
    - Crear interfaz gráfica para la calculadora
    - Implementar auto reconociemiento de dim
    - Implementar angulo 3D
    - Añadir opción de descarga de gráfico
    - más
# Requisitos
    Para poder ejecutar el programa se debe tener instalada una versión de Cmake >= 3.23, junto con las siguientes librerias de QT6:
        Core
        Gui
        Widgets
        Charts
        REQUIRED
        PrintSupport
    El programa solo ha sido testeado en Linux y de momento es incompatible con Windows.
    Cualquier duda sobre las librerias, la lista completa se encuentra en el archivo CMakeLists.txt


# Instalación
    El progama fue testeado en linux, asi que no deberia haber mayores problemas con la mayoria de sistemas operativos
    
    Para utilizar este programa se necesita una instalacion de qt6, junto con CMake.

    Para ejecutar este programa se debe compilar usando
    el archivo de configuración de cmakelist.txt. Si se esta usando qt creator es importante comprobar que el proyecto se inicie en modo cmake y no qmake, ya que de lo contrario, este no compilará. 

    El programa de momento no es compatible con Windows pero se planea implementar en un futuro cercano.

# Uso
    Para usar el programa solo se deben seguir las indicaciones, seleccionar dimension, seleccionar operacion
    e introducir los datos solicitados. Para cerrar el grafico se puede tanto usar la x de la ventana como el botón cerrar.


### Integrantes:
* Joaquín Leiva
  * Gitlab: [@genericusernameuwu](https://gitlab.com/genericusernameuwu)
  * GitHub: [@genericusernameuwu](https://github.com/genericusernameuwu)
  * rol: 202229836-7


* Andrea Alfonzo
  * Gitlab: [@andreavalfonzo](https://gitlab.com/andreavalfonzo)
  * GitHub: [@andreavalfonzo](https://github.com/andreavalfonzo)
   * rol: 202230524-k


* Benjamín Muñoz
  * Gitlab: [@raztor](https://gitlab.com/raztor)
  * GitHub: [@raztor](https://github.com/Raztor)
  * rol: 202230546-0

## Referencias:
    Laroze Barrios, L. (2018). Conceptos y magnitudes en física (2018.a ed.). Nicolás Porras.

<details>
<summary>Diagrama Completo</summary>
<br>
<img src="https://gitlab.com/Raztor/vecalculator/-/raw/main/media/diagrama.png" alt="Diagrama UML">
</details>
<details>
<summary>Diagrama Resumido (formato solicitado)</summary>
<br>
<img src="https://gitlab.com/Raztor/vecalculator/-/raw/main/media/img.png" alt="Diagrama UML">
</details>
