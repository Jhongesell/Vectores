//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para resolver un sistema lineal                                                    //
// Revisi�n: 1 de Junio del 2006                                                            //
//                                                                                          //
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



#ifndef __ResuelveSistemaLineal__
#define __ResuelveSistemaLineal__


#include <stdlib.h>
#include <stdio.h>
#include "Matriz.hpp"

// M�todo num�rico
#define CGM            0
#define FACT_LU        1
#define GAUSSSEIDEL    2
#define INVERSA        3
#define JACOBI         4
#define TRIDIAGONAL    5
#define FACT_CHOLESKI  6


// Nombre del m�todo
static const char Nmb[][50]= {"CGM","Factorizaci�n LU","Gauss-Seidel","Inversa","Jacobi","Tridiagonal","Choleski"};

// Requiere matriz del tipo Bandada, Dispersa, Densa
#define REQUIERE_MAT_BAND   0
#define REQUIERE_MAT_DISP   1
#define REQUIERE_MAT_DENS   2


/// Clase para resoluci�n del sistema lineal
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class ResuelveSistemaLineal
{
protected:

   /// Indica si el m�todo num�rico modifica la matriz
   bool MetodoModificaMatriz;
   /// Numero de iteraciones en la resoluci�n del sistema lineal
   int NumIteraciones;
   /// M�todo Numerico
   int MetodoNumerico;
   /// Requiere matriz del tipo Bandada, Dispersa, Densa
   int RequiereMatriz;

   /// Vector soluci�n
   Vector *X;
   /// Vactor lado derecho
   Vector *B;
   /// Matriz
   Matriz *M;

   /// Visualiza el error indicado y termina el programa
   /** @param txt Puntero al mensaje de error */
   void error(const char *txt)
   {
      printf("\nError resolver el sistema Lineal: %s\n\n",txt);
      exit(1);
   }


public:

   /// Resuelve el sistema lineal
   /** @param m Puntero a la matriz del sistema lineal
        @param b Puntero a un vector, lado derecho del sistema lineal
        @param x Puntero a un vector, soluci�n del sistema lineal */
   void inicializa(Matriz *m, Vector *b, Vector *x)
   {
      M = m;
      X = x;
      B = b;
   }

   /// Constructor de la clase
   ResuelveSistemaLineal(void)
   {
      NumIteraciones = 0;
   }

   /// Resuelve el sistema lineal
   virtual void resuelve(void) = 0;

   /// Resuelve el sistema lineal
   /** @param b Puntero a un vector, lado derecho del sistema lineal
       @param x Puntero a un vector, soluci�n del sistema lineal */
   virtual void resuelve(Vector *b, Vector *x) = 0;
   
   
   /// Retorna el n�mero de iteraciones en la resoluci�n del sistema lineal
   /** @return N�mero de iteraciones */
   int retornaNumeroIteraciones(void)
   {
      return NumIteraciones;
   }

   /// Indica si el m�todo num�rico modifica la matriz
   /** @return (true) si el m�todo num�rico modifica la matriz, (false) en caso contrario */
   bool elMetodoModificaMatriz(void)
   {
      return MetodoModificaMatriz;
   }

   /// Retorna el m�todo num�rico
   /** @return Retorna el m�todo num�rico CGM, FACT_LU, GAUSSSEIDEL, INVERSA, JACOBI, TRIDIAGONAL, etc  */
   int retornaMetodoNumerico(void)
   {
      return MetodoNumerico;
   }

   /// Retorna el tipo de matriz que requiere el m�todo
   /** @return Retorna el tipo de matriz Bandada, Dispersa, Densa  */
   int retornaRequiereMatriz(void)
   {
      return RequiereMatriz;
   }

   /// Visualiza la informaci�n del m�todo
   void informacionMetodo(void)
   {
      if (MetodoModificaMatriz) printf("\nM�todo %s para resolver el sistema lineal\n",Nmb[MetodoNumerico]);
      else printf("\nM�todo %s, iteraciones para resolver el sistema lineal %d\n",Nmb[MetodoNumerico],NumIteraciones);
   }


};

#endif
