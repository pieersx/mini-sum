# Proyecto algoritmica I

Implementación del Sistema Único de Matrícula ([SUM](https://sum.unmsm.edu.pe/portal.htm)) de la Universidad Nacional Mayor de San Marcos.

Contiene funciones principales que se utilizan más en la plataforma tanto para estudiante y profesor, funciones CRUD de base de datos con manejos de archivos.

# Compilación 
Recursos que necesitaremos para la clonar el repositorio [git](https://git-scm.com/downloads)

## Windows con MinGW
En cualquier terminal o consola preferido, el compilador [MinGW](https://nuwen.net/mingw.html) y git debe estar vinculado en el path

### Clonar el Repositorio
* ```bash
    git clone https://github.com/pieersx/mini-sum.git
    ```
* ```bash
    cd mini-sum
    ``` 

### Compilación con MinGW
* ```bash
    gcc -o nobuild nob.c
    ``` 
Ejecute la compilación
* ```bash
    .\nobuild
    ``` 
Entramos a la carpeta build que fue creado por la ejecución de la compilación anterior
* ```bash
    cd build
    ```
Ejecutamos el main en la carpeta build
* ```bash
    .\main.exe
    ```  

## Sistemas POSIX
Cualquier terminal o consola de su distribución

### Clonar el Repositorio
* ```bash
    git clone https://github.com/pieersx/mini-sum.git
    ```
* ```bash
    cd mini-sum
    ``` 

### Compilación en Sistemas POSIX
* ```bash
    cc nob.c -o nobuild
    ``` 
Ejecute la compilación
* ```bash
    ./nobuild
    ```
Entramos a la carpeta build que fue creado por la ejecución de la compilación anterior
* ```bash
    cd build
    ```
Ejecutamos el main en la carpeta build
* ```bash
    ./main
    ```  