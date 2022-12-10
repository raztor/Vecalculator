# Como configurar el path de Cmake en Windows

    Para poder configurar el path, se debe saber la ubicación de Cmake, para esto debes ir a la ubicación
    en donde esta ubicado QT e ir al directorio de graficos que uses, la ruta completa hasta esta carpetas
    la debes copiar y pegar reemplazando la línea que dice "set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/")"
    en CmakeList.txt
    
    if (WIN32)
    set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/") ---> set(CMAKE_PREFIX_PATH "RUTA COMPLETA")
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(DEBUG_SUFFIX)

# Qt instalado en carpeta personalizada (Linux)

    En caso de que se haya cambiado la ubicación de instalación de Qt (generalmente por medio del 
    instalador gráfico y no admin de paquetes) se debe especificar la ruta al archivo en donde se ubique Cmake y sus
    carpetas de configuración (Qt5Config.cmake,Qt5ModuleLocation.cmake, etc).
    
    estos archivos se deberían encontrar en
    /DirectorioPersonalizadp/Qt/5.15.2/gcc_64/lib/cmake/Qt5.
    
    Luego se debe agregar la siguiente línea al archivo CMakeList.txt:
    set(CMAKE_PREFIX_PATH "/personalizado/ejemplo/Qt/5.15.2/gcc_64/lib/cmake") en caso de que la versión y ruta de
    instalación sea la misma que la anterior.