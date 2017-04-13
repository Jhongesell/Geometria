//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para generar una geometr�a en dos dimensiones usando tri�ngulos                   //
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

// Genera la geometria
void Geometria_2DTriangulos::generaGeometria(void)
{
   int i, j, t, n;


   // Solicita la memoria necesaria
   EL = new MatrizInt(N_E,NNE,"Nodos que conforman a los elementos",-1);
   if (!EL) errorSolicitudMemoria("Geometria Triangulos");
   int col[]= {Particion.retorna(0)+1,Particion.retorna(1)+1};
   ND = new MatrizTamanoVariable(DIM,col,"Coordenadas de Nodos");
   if (!ND) errorSolicitudMemoria("Coordenadas Geometria Triangulos");
   NN = new VectorInt(N_N,"Coordenadas de Nodos");
   if (!NN) errorSolicitudMemoria("Geometria Triangulos");


   // Calcula los tama�os de las particiones horizontales como verticales
   ldouble Ic_H = (Dominio.retorna(1,0) - Dominio.retorna(0,0)) / Particion.retorna(0);
   ldouble Ic_V = (Dominio.retorna(1,1) - Dominio.retorna(0,1)) / Particion.retorna(1);


   for (i = 0; i < Particion.retorna(1); i++)
   {
      ND->asigna(1,i,Dominio.retorna(0,1) + Ic_V * i);
      for (j = 0; j < Particion.retorna(0); j++)
      {
         ND->asigna(0,j,Dominio.retorna(0,0) + Ic_H * j);
         t = (i * Particion.retorna(0) * 2) + (j * 2);

         // Triangulo inferior
         n = (i * Particion.retorna(0)) + j + i;
         EL->asigna(t,0,n);

         n = (i * Particion.retorna(0)) + j + 1 + i;
         EL->asigna(t,1,n);

         n = ((i + 1) * Particion.retorna(0)) + j + 1 + i;
         EL->asigna(t,2,n);

         t ++;
         // Tringulo superior
         n = (i * Particion.retorna(0)) + j + 1 + i;
         EL->asigna(t,0,n);

         n = ((i + 1) * Particion.retorna(0)) + j + i + 2;
         EL->asigna(t,1,n);

         n = ((i + 1) * Particion.retorna(0)) + j + 1 + i;
         EL->asigna(t,2,n);
      }
      ND->asigna(0,j,Dominio.retorna(0,0) + Ic_H * j);
   }
   ND->asigna(1,i,Dominio.retorna(0,1) + Ic_V * i);
}



// Regresa el valor del �rea del elemento
// @return Area del elemento
ldouble Geometria_2DTriangulos::areaElemento(int el)
{
   ldouble x[3];
   ldouble y[3];
   coordenadasElemento(el, x, y);
   return ((x[1]*y[2]-x[2]*y[1]) - (x[0]*(y[2]-y[1])) + (y[0]*(x[2]-x[1]))) / 2.0;
}





