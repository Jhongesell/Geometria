//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para generar una geometria en dos dimensiones con tri�ngulos                    //
//                                                                                          //
// An�lisis y Dise�o y Programaci�n:                                                        //
//                                                                                          //
// Nombre:   Antonio Carrillo Ledesma                                                       //
// E-mail:   acl@www.mmc.igeofcu.unam.mx                                                    //
// P�gina:   http://www.mmc.igeofcu.unam.mx/acl                                             //
//                                                                                          //
//                                                                                          //
// Este programa es software libre. Puede redistribuirlo y/o modificarlo                    //
// bajo los t�rminos de la Licencia P�blica General de GNU seg�n es                         //
// publicada por la Free Software Foundation, bien de la versi�n 2 de                       //
// dicha Licencia o bien (seg�n su elecci�n) de cualquier versi�n                           //
// posterior.                                                                               //
//                                                                                          //
// Este programa se distribuye con la esperanza de que sea �til, pero SIN                   //
// NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin                      //
// garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la                        //
// Licencia P�blica General de GNU para m�s detalles.                                       //
//                                                                                          //
// Deber�a haber recibido una copia de la Licencia P�blica General junto                    //
// con este programa. Si no ha sido as�, escriba a la Free Software                         //
// Foundation, Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU.                            //
//                                                                                          //
//                                                                                          //
//////////////////////////////////////////////////////////////////////////////////////////////




#include "Geometria_2DTriangulos.hpp"

 // Funcion Principal ....
int main(void)
{
   int i,arr[100], num = 0;
   printf("\nParticiona el dominio\n");
   Geometria_2DTriangulos A(0.0,0.0,1.0,1.0,2,2);
   A.visualizaCoordenadasDominio();
   A.visualizaElementos();
   A.visualizaNodos();
   
   //~ A.grabaGeometria("MiGeometria.dat");
   
   
   //~ Geometria_2DTriangulos B("MiGeometria.dat");
   //~ B.visualizaCoordenadasDominio();
   //~ B.visualizaElementos();
   //~ B.visualizaNodos();
   
   //~ printf("\nVisualiza los nodos que la primera coordenada sea 0.0\n\n");
   //~ B.marcaNodosSatisfagan(0.0, 0, -1);
   //~ B.visualizaElementos();
   //~ B.visualizaNodos();
   //~ num = B.regresaNodosSatisfagan(0.0, 0, arr,100);
   //~ printf("\nVisualiza los nodos marcados\n");
   //~ for (i = 0; i < num; i++) {
      //~ printf("Nodo: %d\n",arr[i]);
   //~ }
   //~ B.generaSoporteNodos();
   //~ B.visualizaSoporteNodos();

}


