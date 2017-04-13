//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para generar una geometria en 3D usando Ortoedros                               //
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



#include "Geometria_3DOrtoedros.hpp"


 // Funcion Principal ....
int main(void)
{
   printf("\nGenera partici�n del dominio\n");
   Geometria_3DOrtoedros A(0.0,0.0,0.0,1.0,1.0,1.0,3,3,3);
   A.visualizaCoordenadasDominio();
   A.visualizaElementos();
   A.visualizaNodos();
   //~ A.grabaGeometria("MiGeometria.dat");
   
   //~ printf("\nLee partici�n del dominio\n");
   //~ Geometria_3DOrtoedros *B = new Geometria_3DOrtoedros("MiGeometria.dat");
   //~ Geometria *C = B;
   
   //~ C->visualizaCoordenadasDominio();
   //~ C->visualizaElementos();
   //~ C->visualizaNodos();
   
   //~ delete B;
}

