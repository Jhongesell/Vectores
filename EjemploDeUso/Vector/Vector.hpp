//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con vectores de punto flotante                                    //
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


#ifndef __Vector__
#define __Vector__

#include "Definiciones.hpp"
#include "Vector_Base.hpp"





///  Clase para el trabajar con vectores de punto flotante
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class Vector: public Vector_Base
{
protected:


   /// Puntero al contenido del Vector
   ldouble *V;

   /// Solicita la memoria necesaria para contener los valores del vector
   /** @param col N�mero de columnas del vector
       @param val Valor por omision para inicializar el vector */
   void solicitaMemoria(const int col, const ldouble val);


   /// Libera la memoria solicitada dinamicamente
   /** @param tp Distinto de cero libera toda la memoria */
   void liberaMemoria(int tp)
   {
      delete []V;
      V = NULL;
      if (tp)
      {
         delete []Nmb;
         Nmb = NULL;
      }
   }

public:

   /// Constructor de la clase
   Vector(void) : Vector_Base()
   {
      solicitaMemoria(1,0);
      asignaNombre("Sin Nombre");
   }

   /// Constructor de la clase
   /** Genera un Vector a partir de los datos de otro
       @param vec Vector del cual se hara una copia  */
   Vector(Vector &vec) : Vector_Base()
   {
      solicitaMemoria(vec.columnas(),0);
      asignaNombre(vec.nombre());
      for (int i = 0; i < Col; i++) V[i] = vec.retorna(i);
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n a cero.
      @param col N�mero de columnas del vector  */
   Vector(const int col) : Vector_Base()
   {
      solicitaMemoria(col,0.0);
      asignaNombre(" ");
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n al valor val.
      @param col N�mero de columnas del vector
      @param val Valor por omisi�n para inicializar el vector */
   Vector(const int col, const ldouble val)  : Vector_Base()
   {
      solicitaMemoria(col, val);
      asignaNombre(" ");
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n al valor val.
      @param col N�mero de columnas del vector
      @param val Valor por omisi�n para inicializar el vector
      @param nmb Nombre del vector */
   Vector(const int col, const ldouble val, const char *nmb)  : Vector_Base()
   {
      solicitaMemoria(col, val);
      asignaNombre(nmb);
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n a cero.
       @param col Numero de columnas del vector
       @param nmb Nombre del vector  */
   Vector(const int col, const char *nmb) : Vector_Base()
   {
      solicitaMemoria(col,0.0);
      asignaNombre(nmb);
   }

   /// Destructor de la clase
   ~Vector()
   {
      liberaMemoria(1);
   }

   /// Redimensiona el tama�o del vector
   /** @param ncol Nuevo n�mero de columnas */
   void redimensiona(int ncol)
   {
      liberaMemoria(0);
      solicitaMemoria(ncol,0.0);
   }


   /// Inicializa el vector al valor val indicado
   /** @param val Valor por omisi�n para inicializar el vector */
   void inicializa(const ldouble val);


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


#ifdef DEPURAR
   /// Asigna el valor val a la columna col
   /** @param col Columna
       @param val Valor */
   inline void asigna(const int col, const ldouble val)
   {
      if (col < 0 || col >= Col)
      {
         visualizaInformacion();
         printf("Error indice desbordado (%d)\n",col);
         exit(1);
      }
      V[col] = val;
   }


   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline ldouble retorna(const int col)
   {
      if (col < 0 || col >= Col)
      {
         visualizaInformacion();
         printf("Error indice desbordado (%d)\n", col);
         exit(1);
      }
      return V[col];
   }

#else
   /// Asigna el valor val a la columna col
   /** @param col Columna
       @param val Valor */
   inline void asigna(const int col, const ldouble val)
   {
      V[col] = val;
   }


   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline ldouble retorna(const int col)
   {
      return V[col];
   }
#endif

   /// Visualiza el vector
   /** @param tp (1) Se visualiza el vector de en formato de notaci�n cient�fica, (0) formato notaci�n de punto flotante
       @param nl (1) Visualiza el vector en forma renglones, (0) en forma de columnas
       @param num (1) Numera las componentes del vector, (0) no lo hace */
   void visualiza(const int tp, int nl = 0, int num = 0);

   /// Copia el contenido del vector al vector a
   /** @param a Puntero a un vector */
   void copia(Vector *a);

   /// Convierte el contenido del arreglo a de tama�o tam a vector
   /** @param a Arreglo de tipo ldouble
       @param tam Tama�o del arreglo */
   void convierte(ldouble *a, int tam);

   /// Suma los vectores a y b
   /** @param a Puntero a un vector
       @param b Puntero a un vector */
   void suma(Vector *a, Vector *b);

   /// Suma al vector a
   /** @param a Puntero a un vector */
   void suma(Vector *a);

   /// Resta los vectores a menos b
   /** @param a Puntero a un vector
       @param b Puntero a un vector */
   void resta(Vector *a, Vector *b);

   /// Resta el vector a
   /** @param a Puntero a un vector */
   void resta(Vector *a);

   /// Multiplica el vector por el escalar esc
   /** @param esc Valor escalar */
   void multiplica(ldouble esc);

   /// Calcula la norma infinito
   /** @return Valor del la norma infinita */
   ldouble normaInf(void);

   /// Calcula el producto punto
   /** @return Valor del producto punto */
   ldouble productoPunto(void);

   /// Calcula el producto punto
   /** @param a Puntero a un vector
       @return Valor del producto punto */
   ldouble productoPunto(Vector *a);

   /// Es el vector cero
   /** @return (1) si es el vector cero, (0)en caso contrario */
   int esVectorCero(void);

   /// Es el vector en todas sus componentes m�s peque�o que eps
   /** @param eps Tolerancia
       @return (1) si todas las componentes son m�s peque�as que eps, (0) en caso contrario */
   int esCadaEntradaMasPequeno(double eps);

   /// Tama�o del vector (aproximado) en Kb
   /** @return Tama�o del vector en Kb */
   inline ldouble tamano(void)
   {
      ldouble t = (((long) sizeof(V) * Col) / 1024.0);
      return t;
   }

   /// Visualiza informaci�n general del vector
   inline void visualizaInformacion(void)
   {
      printf("\nVector \"%s\" de dimensi�n: %d \n",Nmb,Col);
   }

};

/**
Esta clase implementa los comportamientos m�s comunes para el trabajar con vectores de punto flotante
@example EjemploVector.cpp */

#endif
