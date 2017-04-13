//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con vectores de punto foltante que extiende a un vector existente //
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


#ifndef __VectorExtendido__
#define __VectorExtendido__

#include "Vector.hpp"


/// Clase para el trabajar con vectores de punto foltante que extiende a un vector existente
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class VectorExtendido : public Vector_Base
{
protected:

   /// Tama�o extendido
   int TE;

   /// Tama�o vector original
   int TO;

   /// Numero de valores adicionados
   int Num;

   /// Puntero al vector original
   Vector *V1;

   /// Puntero al vector aumentado
   Vector *V2;

   /// Puntero a los indices
   int *Ind;

   /// Solicita la memoria necesaria para contener los valores del vector extendido
   void solicitaMemoria(void);


public:



   /// Constructor de la clase
   /** Genera un vector extendido a partir del vector v de tama�o expecificado por el n�mero de columnas
       @param col N�mero de columnas del vector
       @param v Puntero a vector
       @param nmb Nombre del vector extendido */
   VectorExtendido(const int col, Vector *v, const char *nmb) : Vector_Base()
   {
      Col = col;
      Num = 0;
      if (v)
      {
         V1 = v;
         TO = V1->columnas();
         TE = Col - V1->columnas();
      }
      else
      {
         V1 = NULL;
         TO = 0;
         TE = Col;
      }
      solicitaMemoria();
      asignaNombre(nmb);
   }


   /// Destructor de la clase
   ~VectorExtendido()
   {
      delete V2;
      V2 = NULL;

      delete []Ind;
      Ind = NULL;
   }



   /// Inicializa la columna del vector extendido con el valor
   /** @param col Columna
       @param val Valor */
   void inicializa(const int col, const ldouble val);

   /// Inicializa la columna del vector extendido con el indice del vector original
   /** @param col Columna
       @param ind Indice del vector original */
   void inicializa(const int col, const int ind);

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline ldouble operator [] (size_t col)
   {
      return retorna(col);
   }

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline ldouble operator () (size_t col)
   {
      return retorna(col);
   }


   /// Asigna el valor val a la columna col
   /** @param col Columna
       @param val Valor */
   void asigna(const int col, const ldouble val);

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   ldouble retorna(const int col);

   /// Visualiza el vector
   /** @param tp (1) Se visualiza el vector de en formato de notaci�n cient�fica, (0) formato notaci�n de punto flotante
       @param nl (1) Visualiza el vector en forma renglones, (0) en forma de columnas
       @param num (1) Numera las componentes del vector, (0) no lo hace */
   void visualiza(const int tp, int nl = 0, int num = 0);

   /// Copia el contenido del vector al vector a
   /** @param a Puntero a un vector */
   void copia(Vector *a);

   /// Visualiza informaci�n general del vector
   inline void visualizaInformacion(void)
   {
      V1->visualizaInformacion();
      V2->visualizaInformacion();
      printf("\nVector extendido \"%s\" de dimensi�n: %d \n",Nmb,Col);
   }

};

/**
Esta clase implementa los comportamientos m�s comunes para el trabajar con vectores de punto foltante que extiende a un vector existente
@example EjemploVectorExtendido.cpp */

#endif
