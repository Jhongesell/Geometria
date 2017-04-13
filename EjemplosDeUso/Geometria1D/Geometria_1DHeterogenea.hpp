//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para generar una geometr�a heterog�nea en una dimensi�n                            //
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


#ifndef __Geometria_1DHeterogenea__
#define __Geometria_1DHeterogenea__


#include "Geometria_1D.hpp"


/// Tipo de justificaci�n de la malla
#define IZQUIERDA  -1
#define CENTRADA    0
#define DERECHA     1


/// Tipo de Malla
#define DOMINIO_NM     1   // Dominio/(n^m) 
#define DOMINIO_LOGe   2   // Dominio/Loge
#define DIMINIO_LOG10  3   // Dominio/Log10



/// Clase para generar una geometr�a heterog�nea en una dimensi�n
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
    @todo Implementar diversos tipos de geometr�a no homog�nea
*/
class Geometria_1DHeterogenea : public Geometria_1D
{
private:

   /// Tipo de geometr�a
   int Tipo;
   /// Indica el tipo de justificaci�n de la geometr�a
   int Centrada;
   /// Exponente para geometr�as del tipo 1/2^M
   int M;

   /// Dominio del tipo 1/N^M
   void dominioNM(void);

   /// Dominio del logar�tmico
   void dominioLOGe(void);

   /// Dominio del logar�tmico
   void dominioLOG10(void);


public:

   /** @param xi Coordena inicial del dominio de la partici�n
       @param xf Coordena final del dominio de la partici�n
       @param part Tama�o de la partici�n
       @param tp Tipo de partici�n
       @param cen Partici�n centrada en el punto indicado */
   Geometria_1DHeterogenea(ldouble xi, ldouble xf, int part, int tp, double cen=0.0) : Geometria_1D()
   {
      Dominio.asigna(0,0,xi);
      Dominio.asigna(1,0,xf);

      Particion.asigna(0,part);

      N_N = part;
      N_E = part - 1;

      Tipo = tp;
      Centrada = cen;
      M = 2;

      generaGeometria();
   }

   /// Constructor de la clase
   /** @param dom Dominio de la particion
       @param part Tama�o de la partici�n
       @param tp Tipo de partici�n
       @param cen Partici�n centrada en el punto indicado */
   Geometria_1DHeterogenea(MatrizDensa *dom, int part, int tp, double cen=0.0) : Geometria_1D()
   {
      dom->copia(&Dominio);

      Particion.asigna(0,part);

      N_N = part;
      N_E = part - 1;

      Tipo = tp;
      Centrada = cen;

      generaGeometria();
   }


   /// Constructor de la clase
   /** @param arch Nombre del archivo que contiene la geometria */
   Geometria_1DHeterogenea(char *arch) : Geometria_1D()
   {
      leeGeometria(arch);
   }


   /// Genera la geometria
   void generaGeometria(void);



};

/**
Esta clase implementa los componentes para el trabajar con una geometr�a heterog�nea en una dimensi�n
@example EjemploGeometria1D.cpp */

#endif
