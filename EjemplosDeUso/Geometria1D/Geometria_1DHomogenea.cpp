//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para generar una geometr�a homog�nea en una dimensi�n                              //
//                                                                                          //
// An�lisis y Dise�o y Programaci�n:                                                        //
//                                                                                          //
// Nombre:   Antonio Carrillo Ledesma                                                       //
// E-mail:   acl@www.mmc.geofisica.unam.mx                                                  //
// P�gina:   http://www.mmc.geofisica.unam.mx/acl                                           //
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


// Genera la geometria
void Geometria_1DHomogenea::generaGeometria(void)
{
   EL = new MatrizInt(N_E,NNE,"Nodos que conforman a los elementos",-1);
   if (!EL) errorSolicitudMemoria("Elementos Geometria_1D");

   int col[] = {N_N};
   ND = new MatrizTamanoVariable(DIM,col,"Coordenadas de Nodos");
   if (!ND) errorSolicitudMemoria("Coordenadas Geometria_1D");

   NN = new VectorInt(N_N,"Numeracion de nodos");
   if (!NN) errorSolicitudMemoria("Nodos Geometria_1D");

   int i,j;

   ldouble inc = (Dominio.retorna(1,0)  - Dominio.retorna(0,0)) / (Particion.retorna(0)-1);

   // Almacenamiento de los elementos
   for (i = 0; i < N_E; i++)
   {
      EL->asigna(i,0,i);
      EL->asigna(i,1,i+1);
   }

   // Almacenamiento de las coordenadas de los nodos
   for (i = 0; i <= N_E; i++)
   {
      ND->asigna(0,i,Dominio.retorna(0,0) + inc * i);
   }


   // Numeraci�n de los nodos
   j = 0;
   for (i = 0; i <  N_N; i++)
   {
      if (retornaNumeracionNodo(i) != -1)
      {
         estableceNumeroNodo(i,j);
         j++;
      }
   }
}

