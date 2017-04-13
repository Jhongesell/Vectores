//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con vectores enteros                                              //
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



#ifndef __VectorInt__
#define __VectorInt__

#include "Definiciones.hpp"
#include "Vector_Base.hpp"



/// Clase para el trabajar con vectores con valores enteros
/** @author Antonio Carrillo Ledesma
    @date primavera 2009
    @version 1.0.1
    @bug No hay errores conocidos
*/
class VectorInt : public Vector_Base
{
private:

   /// Puntero al contenido del Vector
   int *V;

   /// Solicita la memoria necesaria para contener los valores del vector
   /** @param col N�mero de columnas del vector
       @param val Valor por omision para inicializar el vector */
   void solicitaMemoria(const int col, const int val);

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
   VectorInt(void) : Vector_Base()
   {
      solicitaMemoria(1,0);
      asignaNombre("Sin Nombre");
   }

   /// Constructor de la clase
   /** Genera un Vector a partir de los datos de otro
       @param vec Vector del cual se hara una copia  */
   VectorInt(VectorInt &vec) : Vector_Base()
   {
      solicitaMemoria(vec.columnas(),0);
      asignaNombre(vec.nombre());
      for (int i = 0; i < Col; i++) V[i] = vec.retorna(i);
   }


   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n a cero.
       @param col N�mero de columnas del vector  */
   VectorInt(const int col) : Vector_Base()
   {
      solicitaMemoria(col,0);
      asignaNombre("Sin Nombre");
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n al valor val.
       @param col N�mero de columnas del vector
       @param val Valor por omisi�n para inicializar el vector */
   VectorInt(const int col, int val) : Vector_Base()
   {
      solicitaMemoria(col,val);
      asignaNombre("Sin Nombre");
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n al valor val.
       @param col N�mero de columnas del vector
       @param val Valor por omisi�n para inicializar el vector
       @param nmb Nombre del vector  */
   VectorInt(const int col, const int val, const char *nmb) : Vector_Base()
   {
      solicitaMemoria(col,val);
      asignaNombre(nmb);
   }

   /// Constructor de la clase
   /** Genera un Vector del tama�o expecificado por el n�mero de columnas e inicializado por omisi�n a cero.
       @param col Numero de columnas del vector
       @param nmb Nombre del vector  */
   VectorInt(const int col, const char *nmb) : Vector_Base()
   {
      solicitaMemoria(col,0);
      asignaNombre(nmb);
   }

   /// Destructor de la clase
   ~VectorInt()
   {
      liberaMemoria(1);
   }

   /// Redimensiona el tama�o del vector
   /** @param ncol Nuevo n�mero de columnas */
   void redimensiona(int ncol)
   {
      liberaMemoria(0);
      solicitaMemoria(ncol,0);
   }

   /// Inicializa el vector al valor val indicado
   /** @param val Valor por omisi�n para inicializar el vector */
   void inicializa(const int val);

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline int operator [] (size_t col)
   {
      return retorna(col);
   }

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline int operator () (size_t col)
   {
      return retorna(col);
   }


#ifdef DEPURAR
   /// Asigna el valor val a la columna col
   /** @param col Columna
       @param val Valor */
   void asigna(const int col, const int val)
   {
      if (col < 0 || col >= Col)
      {
         printf("Error indices desbordados (%d)\n", col);
         visualizaInformacion();
         exit(1);
      }
      V[col] = val;
   }


   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   int retorna(const int col)
   {
      if (col < 0 || col >= Col)
      {

         printf("Error indices desbordados (%d)\n", col);
         visualizaInformacion();
         exit(1);
      }
      return V[col];
   }

#else
   /// Asigna el valor val a la columna col
   /** @param col Columna
       @param val Valor */
   inline void asigna(const int col, const int val)
   {
      V[col] = val;
   }

   /// Retorna el valor de la columna col
   /** @param col Columna
       @return Valor */
   inline int retorna(const int col)
   {
      return V[col];
   }
#endif

   /// Copia el contenido del vector al vector a
   /** @param a Puntero a un vector */
   void copia(VectorInt *a);

   /// Visualiza el vector
   /** @param nl (1) Visualiza el vector en forma renglones, (0) en forma de columnas
       @param num (1) Numera las componentes del vector, (0) no lo hace */
   void visualiza(int nl = 0, int num = 0);

   /// Tama�o del vector (aproximado) en Kb
   /** @return tama�o del vector en Kb */
   inline ldouble tamano(void)
   {
      ldouble t = (((unsigned long) sizeof(V) * Col) / 1024.0);
      return t;
   }

   /// Visualiza informaci�n general del vector
   inline void visualizaInformacion(void)
   {
      printf("\nVector entero \"%s\" de dimensi�n: %d \n",Nmb,Col);
   }
};

/**
Esta clase implementa los comportamientos m�s comunes para el trabajar con vectores de valor entero
@example EjemploVectorInt.cpp */

#endif
