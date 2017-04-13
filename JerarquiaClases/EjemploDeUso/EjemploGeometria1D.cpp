//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para generar una geometria en una dimensi�n                                     //
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



#include "Geometria_1DHomogenea.hpp"
#include "Geometria_1DLeerArchivo.hpp"
#include "Geometria_1DHeterogenea.hpp"


 // Funcion Principal ....
int main(void)
{
   // Primer ejemplo
   printf("\nGenera partici�n del dominio\n");
   Geometria_1DHomogenea C(0.0,1.0,10);
   C.visualizaCoordenadasDominio();
   C.visualizaElementos();
   C.visualizaNodos();
   printf("\nVisualiza los elementos que contienen al nodo 2\n\n");
   C.visualizaElementosContienenNodo(2);



   // Segundo ejemplo
   Geometria_1D *arr[2];
   Geometria_1DHeterogenea *A = new Geometria_1DHeterogenea(0.0,2.0,10,DOMINIO_NM,IZQUIERDA);
   Geometria_1DHeterogenea *B = new Geometria_1DHeterogenea(0.0,2.0,10,DOMINIO_NM,DERECHA);
   
   arr[0] = A;
   arr[1] = B;
   
   for (int i = 0; i < 2; i++)
   {
      arr[i]->visualizaCoordenadasDominio();
      arr[i]->visualizaElementos();
      arr[i]->visualizaNodos();
      printf("\nVisualiza los elementos que contienen al nodo 2\n\n");
      arr[i]->visualizaElementosContienenNodo(2);
      arr[i]->generaSoporteNodos();
      arr[i]->visualizaSoporteNodos();
   }
   
   delete A;
   delete B;
   arr[0] = NULL;
   arr[1] = NULL;
}
