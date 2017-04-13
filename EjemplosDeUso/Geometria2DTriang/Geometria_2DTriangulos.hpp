//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para generar una geometr�a homog�nea en dos dimensiones usando tri�ngulos          //
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


#ifndef __Geometria_2DTriangulos__
#define __Geometria_2DTriangulos__

#include "Geometria_2D.hpp"


/// Clase para generar una geometr�a homog�nea en dos dimensiones usando tri�ngulos
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class Geometria_2DTriangulos : public Geometria_2D
{
public:


   /// Constructor de la clase
   /** @param x1 Coordenada X del inicio del dominio
       @param y1 Coordenada Y del inicio del dominio
       @param x2 Coordenada X del fin del dominio
       @param y2 Coordenada Y del fin del dominio
       @param part_hor Partici�n en X
       @param part_ver Partici�n en Y */
   Geometria_2DTriangulos(ldouble x1, ldouble y1, ldouble x2, ldouble y2, int part_hor, int part_ver) : Geometria_2D()
   {
      inicializa(x1,y1,x2,y2,part_hor,part_ver);
   }

   /// Constructor de la clase
   /** @param arch Nombre del archivo que contiene la geometria */
   Geometria_2DTriangulos(const char *arch) : Geometria_2D()
   {
      // Dimension 1D
      DIM = 2;
      // Numero de nodos por elemento
      NNE = 3;
      // Numero m�ximo de elementos que son soporte de un nodo
      NMESN = 6;

      leeGeometria(arch);
   }

   /// Constructor de la clase
   Geometria_2DTriangulos(void) : Geometria_2D()
   {
      // Dimension 1D
      DIM = 2;
      // Numero de nodos por elemento
      NNE = 3;
      // Numero m�ximo de elementos que son soporte de un nodo
      NMESN = 6;
   }

   /// Inicializa los datos de la geometr�a
   /** @param x1 Coordenada X del inicio del dominio
       @param y1 Coordenada Y del inicio del dominio
       @param x2 Coordenada X del fin del dominio
       @param y2 Coordenada Y del fin del dominio
       @param part_hor Partici�n en X
       @param part_ver Partici�n en Y */
   void inicializa(ldouble x1, ldouble y1, ldouble x2, ldouble y2, int part_hor, int part_ver)
   {
      // Dimension
      DIM = 2;
      // Numero de nodos por elemento
      NNE = 3;
      // Numero m�ximo de elementos que son soporte de un nodo
      NMESN = 6;
      // Numero de tringulos
      N_E = (part_hor * part_ver) * 2;
      // Numero de nodos
      N_N = (part_hor + 1) * (part_ver +1);

      // Almacena valores
      Dominio.asigna(0,0,x1);
      Dominio.asigna(0,1,y1);
      Dominio.asigna(1,0,x2);
      Dominio.asigna(1,1,y2);

      Particion.asigna(0,part_hor);
      Particion.asigna(1,part_ver);

      generaGeometria();
   }

   /// Inicializa los datos de la geometr�a
   /** @param dm Dominio
       @param part_hor Partici�n en X
       @param part_ver Partici�n en Y */
   void inicializa(MatrizDensa *dm, int part_hor, int part_ver)
   {
      // Dimension
      DIM = 2;
      // Numero de nodos por elemento
      NNE = 3;
      // Numero m�ximo de elementos que son soporte de un nodo
      NMESN = 6;
      // Numero de tringulos
      N_E = (part_hor * part_ver) * 2;
      // Numero de nodos
      N_N = (part_hor + 1) * (part_ver +1);

      // Almacena valores
      dm->copia(&Dominio);

      Particion.asigna(0,part_hor);
      Particion.asigna(1,part_ver);

      generaGeometria();
   }


   /// Genera la geometria
   void generaGeometria(void);


   /// Regresa el valor del �rea del elemento
   /** @return Area del elemento */
   ldouble areaElemento(int el);

};

/**
Esta clase implementa los componentes para el trabajar con una geometr�a homog�nea en dos dimensiones usando tri�ngulos
@example EjemploGeometria2DTriangulos.cpp */

#endif
