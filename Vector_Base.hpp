//////////////////////////////////////////////////////////////////////////////////////////////
// Clase base para el trabajar con vectores                                                 //
//                                                                                          //
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


#ifndef __Vector_Base__
#define __Vector_Base__


#include <stdlib.h>
#include <string.h>
#include <stdio.h>





///  Clase base para el trabajar con vectores
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class Vector_Base
{
protected:

   /// N�mero de columnas del vector
   int Col;

   /// Nombre del vector
   char *Nmb;



public:


   /// Constructor de la clase
   Vector_Base(void)
   {
      Col = 0;
      Nmb = NULL;
   }

   /// Destructor de la clase
   ~Vector_Base()
   {
      delete []Nmb;
      Nmb = NULL;
   }

   /// Asigna nombre al vector
   /** @param nmb Nombre del vector */
   void asignaNombre(const char *nmb)
   {
      delete []Nmb;
      Nmb = NULL;
      Nmb = new char[strlen(nmb)+2];
#ifdef DEPURAR
      if (!Nmb)
      {
         printf("\nError no hay memoria para el nombre del vector\n");
         exit(1);
      }
#endif
      strcpy(Nmb, nmb);
   }


   /// Retorna el nombre del vector
   /** @return Regresa un puntero al nombre del vector */
   inline char *nombre(void)
   {
      return Nmb;
   }

   /// Retorna el n�mero de columnas del vector
   /** @return Regresa el n�mero de columnas del vector */
   inline int columnas(void)
   {
      return Col;
   }


   /// Visualiza informaci�n general del vector
   virtual void visualizaInformacion(void) = 0;

};

#endif
