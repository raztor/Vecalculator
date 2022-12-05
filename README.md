# Vecalculator
[![wakatime](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340.svg)](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340)

09/12/2022

## Sobre el proyecto
Introducción: Lo que nos llevó como grupo a pensar en la elaboración de una calculadora de vectores y todo lo que esto englobe principalmente fueron 2 razones, como una de las principales es hacer que la tarea del cálculo de vectores deje de ser un proceso tan engorroso además de enredado para muchos y convertirlo en algo más mecanizado de fácil uso y por último pensando tanto como en nosotros como alumnos a los cuales se nos complicó mucho nuestro primer acercamiento a la física de la educación superior, además como factor agregado creemos que nuestro proyecto en un futuro puede ser de gran ayuda para la comunidad universitaria que componemos.

Desarrollo: En las fases iniciales del trabajo en Vecalculator 8001 existieron pequeños problemas relacionados con la modularización y depuración de nuestro código, afortunadamente se pudieron sortearlos en su totalidad, para que a día de hoy poder tener un código más compacto y efectivo. A día de hoy, y casi habiendo terminado el desarrollo para la entrega el hito 2, aún se mantienen los principales objetivos del proyecto como meta, los cuales fueron mencionados anteriormente. En lo que es pertinente a la documentación y recursos que se han ido utilizando en nuestro trabajo, existieron pequeños inconvenientes que, hemos surcado de manera rápida y eficaz. Aunque se hizo énfasis antes, a la hora de trabajar, siempre se ha priorizado los objetivos que se han propuesto al principio, en el caso de la documentación se ha puesto énfasis en anotar todo, para que le resulte amigable al usuario promedio.

Conclusión: En conclusión, durante toda la realización de nuestro proyecto, sentimos que nuestro crecimiento como grupo fue bastante grande, además de aunque aún no este listo en su totalidad el proyecto con todo el trabajo que llevamos en la actualidad. Creemos que nuestro enfoque y objetivos principales a la hora de la realización de nuestra calculadora de vectores, ha sido llevado en su totalidad y nos encontramos bastante realizados con nuestros resultados actuales.
Además, sentimos y esperamos que nuestro trabajo resulte de gran ayuda y soporte para las generaciones futuras a la hora de afrontar los problemas que nosotros supimos enfrentar.


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
    - Añadidas operaciones Ascii (Ahora puedes sumar, restar,etc. con los valores de cáracteres Ascii)



    Por hacer:
    - Crear interfaz gráfica para la calculadora
    - Implementar auto reconociemiento de dim
    - Implementar angulo 3D
    - Implementar modelado 3D
    - Añadir opción de descarga de gráfico
    - más

    
    Descartado:
    - Agregar la opción para operar con mas de 2 vectores.
    - Limpiar previamente los comandos en consola antes del lanzamiento

### Sobre la visualización 3D:
    Nos hubiese encantado como grupo poder haber añadido la visualización de vectores en 3D, pero
    pero debido a problemas relacionados a una migración de SSD fallida perdimos parte del código
    en proceso de implementación y dejó a la persona a cargo del 3D sin poder finalizarlo.
# Requisitos
    Para poder ejecutar el programa se debe tener instalada una versión de Cmake >= 3.23, junto con las siguientes librerias de QT5:
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

    Para utilizar este programa se necesita una instalacion de qt5, junto con CMake.

    Para ejecutar este programa se debe compilar usando
    el archivo de configuración de cmakelist.txt. Si se esta usando qt creator es importante comprobar que el proyecto se inicie en modo cmake y no qmake, ya que de lo contrario, este no compilará. 

    PARA ABRIR EL PROYECTO EN QT CREATOR SE DEBE SELECCIONAR EL ARCHIVO CMAKELIST.TXT

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
