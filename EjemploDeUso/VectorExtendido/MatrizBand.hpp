//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con matrices bandadas de punto flotante                           //
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



#ifndef __MatrizBand__
#define __MatrizBand__


#include "MatrizBandDisp.hpp"


/// Clase para el trabajar con matrices bandadas de punto flotante basada en el algoritmo Compressed Diagonal Storage (CDS)
/// El algoritmo esta optimizado para hacer producto matriz vector
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
    @todo Hacer comportamiento para cambiar tama�o de banda
    @todo Multiplicaci�n de matrices
*/
class MatrizBand : public MatrizBandDisp
{
private:

   /// Solicita la memoria necesaria para contener los valores de la matriz
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas de la matriz
       @param ban Tama�o de la banda  */
   void solicitaMemoria(const int ren, const int col, const int ban);

   /// Puntero a la matriz de datos
   ldouble **M;
   /// Arreglo que contiene los columnas de la matriz
   int *J;


public:

   /// Constructor de la clase
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas de la matriz
       @param ban Tama�o de la banda   */
   MatrizBand(const int ren, const int col, const int ban) : MatrizBandDisp()
   {
      solicitaMemoria(ren, col, ban);
      asignaNombre("SinNombre");
   }

   /// Constructor de la clase
   /** @param ren N�mero de renglones de la matriz
       @param col N�mero de columnas de la matriz
       @param ban Tama�o de la banda
       @param nmb Nombre de la matriz */
   MatrizBand(const int ren, const int col, const int ban, const char *nmb) : MatrizBandDisp()
   {
      solicitaMemoria(ren, col, ban);
      asignaNombre(nmb);
   }

   ~MatrizBand()
   {
      liberaMemoria();
   }

   /// Libera la memoria solicitada para la matriz
   void liberaMemoria(void);

   /// Inicializa la matriz al valor indicado
   /** @param val Valor por omisi�n para inicializar la matriz */
   void inicializa(ldouble val)
   {
      printf("\nFuncion no implementada en esta clase\n");
   }

   /// Asigna el valor indicado en el renglo y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @param val Valor */
   void asigna(const int ren, const int col, const ldouble val);

   /// Retorna el valor del renglon y columna solicitado
   /** @param ren Renglon
       @param col Columna
       @return Valor */
   ldouble retorna(const int ren, const int col);

   /// Retorna el n�mero de columnas de la banda para el renglon indicado
   /** @param ren N�mero de renglon
       @return N�mero de columnas de la banda para el renglon solicitado  */
   int retornaNumeroColumnasBanda(int ren);

   /// Retorna el n�mero de columna cuando se para en el renglon e indice de la banda
   /** @param ren N�mero de renglon
       @param ind N�mero de indice
       @return N�mero de columna cuando se para en el renglon e indice de la banda  */
   int retornaNumeroColumna(int ren, int ind);

   /// Retorna el valor de la columna cuando se para en el renglon e indice de la banda
   /** @param ren N�mero de renglon
       @param ind N�mero de indice
       @return Valor de la columna cuando se para en el renglon e indice de la banda  */
   inline double retornaValorColumna(int ren, int ind)
   {
      return (M[ren][ind]);
   }

   /// Multiplica la matriz por el escalar pasado como parametro
   /** @param esc Escalar */
   void multiplica(ldouble esc);

   /// Multiplica la matriz A por la matriz B
   /** @param a Puntero a matriz densa
       @param b Puntero a matriz densa  */
   void multiplica(MatrizBand *a, MatrizBand *b);

   /// Multiplica la matriz por el vector B dejando el Resultado en R
   /** @param b Puntero a un Vector
       @param r Puntero a un Vector */
   void multiplica(Vector *b, Vector *r);

   /// Visualiza las matrices internas usadas para soportar a las matrices bandadas
   void visualizaMatricesInternas(void);

};


/**
Esta clase implementa los componentes para el trabajar con matrices bandadas de punto flotante
@example EjemploMatrizBand.cpp */

#endif
