# Vecalculator
[![wakatime](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340.svg)](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340)

## Sobre el proyecto
Como grupo pensamos en este proyecto, ya que a la hora de enfrentarnos a la todo lo que engloba el
calculo de vectores en 2 y 3 dimensiones, nos resulta bastante complicado lograr trabajar con
ellos de manera correcta, además pensando en nuestro futuro con los diversos ramos de 
física que tendremos durante nuestra vida universitaria.

En las primeras instancias de creación del código, trabajamos en la creación de funciones básicas del calculo de vectores, tales como: Suma, Resta, Multiplicación y división, durante el proceso de creación de estas empezamos a trabajar en funciones que requerían mayor dedicación, como por ejemplo: Modulo, Producto punto, Producto Cruz y Angulo.
Además mientras trabajábamos en la elaboración del código, íbamos depurando el código poco a poco, para hacerlo mas comprimido y efectivo

Lo que nosotros esperamos lograr en las fases finales de nuestro proyecto, hacer que nuestra calculadora sea funcional y viable en su totalidad, lograr que la interfaz grafica, sea amigable al usuario promedio y expandirlo en otros de los muchos horizontes pertenecientes a las ramas de la física.
Por ultimo como grupo esperamos que el proyecto, sea de gran ayuda a las futuras generaciones de estudiantes universitarios.
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
    - crear interfaz gráfica para la calculadora
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
