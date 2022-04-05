Como añadir un icono a un ejecutable escrito en C/C++ en Windows
Publicado: 26 agosto, 2011 en C/C++, comandos, programación
Etiquetas:C/C++, Icono a ejecutables Windows, windres0
Una cosa que siempre me ha llamado la atención es como se inserta un icono a un ejecutable en su compilación. Pero no fue hasta por necesidades y exigencias del trabajo que no me puse a investigar sobre el tema.

En los sistemas operativos tipo Windows es muy sencillo:

1. Necesitamos un fichero de recurso

Un archivo que se nombrará como: resource.rc  y cuyo contenido es el siguiente:

MAINICON ICON "icono.ico"
icono.ico es el icono que se incrustará en el ejecutable.

2. A partir del resource.rc se crea resource.o

Para hacer del recurso un objeto utilizamos el siguiente comando, el cual forma  parte de GNU Binutils:

 windres resource.rc resource.o
3. Compilar el programa con el resource.o

Una vez que se ha generado el fichero objeto se añade al ejecutable.

 g++ -o ejemplo.exe main.cpp resource.o
El ejecutable ahora se visualiza en el escritorio con el icono que hemos seleccionado.