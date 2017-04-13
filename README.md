Clases para manipular geometrias en 1D, 2D y 3D


Geometria en 1D es sobre intervalos del tipo [a,b] los cuales pueden ser con
geometria homogenea o heterogenea del tipo:
   #define DOMINIO_NM     1   // Dominio/(n^m) 
   #define DOMINIO_LOGe   2   // Dominio/Loge
   #define DIMINIO_LOG10  3   // Dominio/Log10

Geometria en 2D es sobre intervalos del tipo [a,b]x[c,d] tanto para rectangulos 
como para triangulos (rectangulos partidos en 2).

Geometria en 3D es sobre intervalos del tipo [a,b]x[c,d]x[e,f] para ortoedros


Las coordenadas de los nodos de las geometrias en 1D, 2D y 3D se guardan en 
vectores (uno por cada dimension) que contienen las coordenadas para cada eje,
i.e. el primer vector guarda las coordenadas del intervalo [a,b] partido en n
pedazos, el segundo vector guarda las coordenadas del intervalo [c,d] partido
en m pedazos y asi sucesivamente.

