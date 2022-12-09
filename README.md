# Vecalculator
[![wakatime](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340.svg)](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340)

09/12/2022

## Sobre el proyecto
Introducción: El cálculo de vectores ha sido considerada por muchos algunas veces complicada, siendo un problema para constante para varios estudiantes de ingeniería o carreras que requieran estos cálculos. Es por esto que Vecalculator 8001, correspondiente al proyecto realizado en el curso Seminario de programación, busca como objetivo principal, facilitar la tarea del cálculo de vectores. Se plantearon también tres objetivos específicos: calcular operaciones a través de un compilador, graficar los resultados a través de QT y finalmente, mostrar todo a través de la interfaz gráfica de QT, sin necesidad de utilizar el compilador. A lo largo de este informe se revisará el recorrido de Vecalculator 8001 para lograr sus objetivos.

Desarrollo: Este trabajo fue dividido en tres etapas diferentes, es por esto que fueron tres los objetivos específicos, cumpliendo uno en cada una de ellas. En la primera etapa, se buscó calcular las operaciones con vectores en segunda y tercera dimensión a través del compilador. Para esto se utilizó el lenguaje de programación C++, además de libros como referencia para establecer las distintas operaciones. En la segunda etapa del proyecto, se utilizó QT para graficar los resultados de las operaciones, sin embargo en esta etapa el usuario debía usar el compilador para ingresar los datos de sus vectores. Por último, en la tercera y última etapa, gracias a QT se pudo prescindir del compilador, ya que todos los datos necesarios eran pedidos a través de la interfaz, para después mostrar el gráfico final. 

En cada etapa se presentaron distintas complicaciones, una de las más importantes fue el limitar los datos que puede ingresar el usuario, para evitar que el programa permitiera leer letras u otros caracteres no válidos para las operaciones. En la tercera etapa se presentó un inconveniente que provocó la modificación de objetivos del proyecto, ya que la graficación de vectores en tres dimensiones no pudo ser completada debido a la dificultad de su código. Sin embargo, la calculadora funciona perfectamente para ángulos en dos dimensiones, pudiendo elegir entre calcular los vectores de forma gráfica o analítica. 


Conclusión:Por lo revisado anteriormente, Vecalculator 8001 cumple con su propósito de ser una calculadora de vectores en segunda dimensión, cambiando el foco inicial del proyecto de poder graficar en dos y tres dimensiones. El desarrollo de este proyecto fue satisfactorio. 

Se espera que pueda ser una herramienta provechosa para las y los estudiantes de la UTFSM y facilitar su tarea de calcular vectores a lo largo de los ramos que lo necesiten. 



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
<summary>Diagrama Resumido (formato solicitado)</summary>
<br>
<img src="https://gitlab.com/Raztor/vecalculator/-/raw/main/media/img.png" alt="Diagrama UML">
</details>
