# Vecalculator
[![wakatime](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340.svg)](https://wakatime.com/badge/user/5be7d1e2-7411-4f5d-9f82-c9a643da22e2/project/9aafb881-995a-4634-9ffa-40e64411f340)


## Sobre el proyecto
### 09/12/2022
### Introducción
El cálculo de vectores ha sido considerada por muchos algunas veces complicada, siendo un problema para constante para varios estudiantes de ingeniería o carreras que requieran estos cálculos. Es por esto que Vecalculator 8001, correspondiente al proyecto realizado en el curso Seminario de programación, busca como objetivo principal, facilitar la tarea del cálculo de vectores.

### Objetivos
El objetivo general, como fue ya mencionado, es facilitar la tarea del cálculo de vectores. Este proyecto también cuenta con 3 objetivos específicos: calcular operaciones de vectores a través del compilador, graficar los resultados de las operaciones con vectores a través de la interfaz QT, y finalmente, mostrar toda la calculadora a través de QT sin necesidad de utilizar el compilador.

### Desarrollo
Este trabajo fue dividido en tres etapas diferentes, es por esto que fueron tres los objetivos específicos, cumpliendo uno en cada una de ellas. En la primera etapa, se buscó calcular las operaciones con vectores en segunda y tercera dimensión a través del compilador. Para esto se utilizó el lenguaje de programación C++, además de libros como referencia para establecer las distintas operaciones. En la segunda etapa del proyecto, se utilizó QT para graficar los resultados de las operaciones, sin embargo en esta etapa el usuario debía usar el compilador para ingresar los datos de sus vectores. Por último, en la tercera y última etapa, gracias a QT se pudo prescindir del compilador, ya que todos los datos necesarios eran pedidos a través de la interfaz, para después mostrar el gráfico final. 

En cada etapa se presentaron distintas complicaciones, una de las más importantes fue el limitar los datos que puede ingresar el usuario, para evitar que el programa permitiera leer letras u otros caracteres no válidos para las operaciones. Por otro lado, el agregar un plano cartesiano a la gráfica para que no fuera solamente un cuadrante también fue una complicación resuelta a lo largo del proyecto.


### Conclusión
Por lo revisado anteriormente, Vecalculator 8001 cumple completamente con su propósito inicial, siendo una calculadora de vectores útil y funcional. Los resultados de este proyecto fueron satisfactorios.

Se espera que pueda ser una herramienta provechosa para las y los estudiantes de la UTFSM y facilitar su tarea de calcular vectores a lo largo de los ramos que lo necesiten. 



# Version: 3.0.0

    Date: 2022-10-12
    License: GNU AGPLv3

    Cambios:
    - Lanzamiento 3.0
    - Añadida interfaz gráfica completa 
    - Añadido filtro de capas en QCustomPlot
    - Uso de clases para el manejo de vectores
    - Re-estructuración completa de código
    - Cambios del readme
    - Nuevas funciones de graficación
    - Cambios menores
    - Añadida opción para copiar gráfico al portapapeles

    Descartado:
    - Implementación de Gráfico 3D (problemas de rendimiento y poco tiempo para probar código)


# Requisitos
    Para poder ejecutar el programa se debe tener instalada una versión de Cmake >= 3.23, junto con las siguientes librerias de QT5:

        Core
        Gui
        Widgets
        PrintSupport
        QcustomPlot ---> Incluido en src (no se debe instalar)


    El programa solo ha sido testeado en Linux y de momento es incompatible con Windows.
    Cualquier duda sobre las librerias, la lista completa se encuentra en el archivo CMakeLists.txt


# Instalación
    El programa en su versión 3.0 es compatible tanto con Windows como con linux, en el caso de Windows
    se debe seleccionar el directorio de Cmake dentro de la carpeta de instalación de QT5
    (más infromación sobre ambos SO, en config-cmake.md)

    Para ejecutar este programa se debe compilar usando
    el archivo de configuración de cmakelist.txt. Si se esta usando qt creator es importante comprobar que el proyecto 
    se inicie en modo cmake y no qmake, ya que de lo contrario, este no compilará. 

    PARA ABRIR EL PROYECTO EN QT CREATOR SE DEBE SELECCIONAR EL ARCHIVO CMAKELIST.TXT

    El programa de momento no es compatible con Windows pero se planea implementar en un futuro cercano.

# Uso
    Para usar el programa solo se deben seguir las indicaciones, seleccionar operacion, seleccionar dimension
    e introducir los datos solicitados.


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
