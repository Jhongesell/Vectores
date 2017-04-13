//////////////////////////////////////////////////////////////////////////////////////////////
// Clase base para trabajar con matrices bandadas y dispersas                               //
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



#ifndef __MatrizBandDisp__
#define __MatrizBandDisp__


#include "Matriz.hpp"


/// Clase base para trabajar con matrices bandadas y dispersas
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class MatrizBandDisp : public Matriz
{
private:

   /// Solicita la memoria necesaria para contener los valores de la matriz
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas de la matriz
       @param ban Tama�o de la banda  */
   virtual void solicitaMemoria(const int ren, const int col, const int ban) = 0;


public:

   /// Constructor de la clase
   MatrizBandDisp(void) : Matriz()
   {
   }


   /// Retorna el tama�o de la banda
   /** @return Tama�o de la banda */
   inline int tamanoBanda(void)
   {
      return Ban;
   }


   /// Multiplica la matriz por el escalar pasado como parametro
   /** @param esc Escalar */
   virtual void multiplica(ldouble esc) = 0;


   /// Multiplica la matriz por el vector B dejando el Resultado en R
   /** @param b Puntero a un Vector
       @param r Puntero a un Vector */
   virtual void multiplica(Vector *b, Vector *r) = 0;


   /// Visualiza las matrices internas usadas para soportar a las matrices bandadas
   virtual void visualizaMatricesInternas(void) = 0;

};


/**
Esta clase implementa los componentes para el trabajar con matrices dispersas de punto flotante
@example EjemploMatrizDispersa.cpp */

#endif
