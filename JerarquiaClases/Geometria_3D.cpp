//////////////////////////////////////////////////////////////////////////////////////////////
// Clase base para generar una geometr�a en tres dimensiones                                //
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


#include <math.h>
#include "Geometria_3D.hpp"
#include "Ctrl_vis.hpp"





// Retorna el numero de nodo que tiene coordenadas Coor, si no pertenece -1
// @param x Coordenada X
// @param y Coordenada Y
// @param z Coordenada Z
// @return retorna el numero de nodo o (-1) si no es encontrado
int Geometria_3D::retornaNodoCoord(ldouble x, ldouble y, ldouble z)
{
   int i;
   ldouble x1, y1, z1;

#ifdef DEPURAR
   // Revisa que el nodo solicitado este en el dominio
   if (!coordenadasDentroDominio(x,y,z)) return -1;
#endif

   for (i = 0; i <  N_N; i++)
   {
      coordenadasNodo(i, x1, y1, z1);
#ifdef __Double__
      if ( fabs(x1 - x) < TOLERANCIA_NODO && fabs(y1 - y) < TOLERANCIA_NODO && fabs(z1 - z) < TOLERANCIA_NODO) return i;
#else
      if ( fabsl(x1 - x) < TOLERANCIA_NODO && fabsl(y1 - y) < TOLERANCIA_NODO && fabsl(z1 - z) < TOLERANCIA_NODO) return i;
#endif
   }
   // Nodo no encontrado
   return -1;
}


// Regresa las coordenadas del elemento
// @param el N�mero de elemento
// @param x Puntero a las coordenada X
// @param y Puntero a las coordenada Y
// @param z Puntero a las coordenada Z
void Geometria_3D::coordenadasElemento(int el, ldouble *x, ldouble *y, ldouble *z)
{
   int i, xnd;
   for (i = 0; i < NNE; i++)
   {
      xnd = EL->retorna(el-1,i);
      x[i] = ND->retorna(xnd,0);
      y[i] = ND->retorna(xnd,1);
      z[i] = ND->retorna(xnd,2);
   }
}

