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


#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Vector.hpp"
#include "Ctrl_vis.hpp"



// Solicita la memoria necesaria para contener los valores del vector
// @param col N�mero de columnas del vector
// @param val Valor por omision para inicializar el vector
void Vector::solicitaMemoria(const int col, const ldouble val)
{
   V = new ldouble[col];
   if (!V)
   {
      visualizaInformacion();
      exit(1);
   }
   Col = col;
   for (int i = 0; i < Col; i++) V[i] = val;
}

// Inicializa el vector al valor val indicado
// @param val Valor por omisi�n para inicializar el vector
void Vector::inicializa(const ldouble val)
{
   for (int i = 0; i < Col; i++) V[i] = val;
}



// Visualiza el vector
// @param tp (1) Se visualiza el vector de en formato de notaci�n cient�fica, (0) formato notaci�n de punto flotante
// @param nl (1) Visualiza el vector en forma renglones, (0) en forma de columnas
// @param num (1) Numera las componentes del vector, (0) no lo hace
void Vector::visualiza(const int tp, int nl, int num)
{
   int i;
   Ctrl_visualizacion cv;

   visualizaInformacion();
   if (tp)
   {
      for (i = 0; i < Col; i++)
      {
         // Visualiza el n�mero de elemento
         if (num) printf("%d: ",i);
         // Visualiza el elemenento
         cv.visualiza_e(V[i]);
         // Cambia de linea
         if (nl) printf("\n");
      }
   }
   else
   {
      for (i = 0; i < Col; i++)
      {
         // Visualiza el numero de elemento
         if (num) printf("%d: ",i);
         // Visualiza el elemenento
         cv.visualiza_n(V[i]);
         // Cambia de linea
         if (nl) printf("\n");
      }
   }
   printf("\n");
}



// Copia el contenido del vector al vector a
// @param col Columna
// @param val Valor
void Vector::copia(Vector *a)
{
#ifdef DEPURAR
   if (columnas() != a->columnas())
   {
      printf("Error en dimensi�n de los vectores al copiar\n");
      visualizaInformacion();
      a->visualizaInformacion();
      exit(1);
   }
#endif
   int i;
   for (i = 0; i < Col; i++) a->asigna(i,V[i]);
}


// Convierte el contenido del arreglo a de tama�o tam a vector
// @param a Arreglo de tipo ldouble
// @param tam Tama�o del arreglo
void Vector::convierte(ldouble *a, int tam)
{
   int i;
   for (i = 0; i < tam; i++) asigna(i,a[i]);
}



// Suma los vectores a y b
// @param a Puntero a un vector
// @param b Puntero a un vector
void Vector::suma(Vector *a, Vector *b)
{
#ifdef DEPURAR
   if (columnas() != a->columnas() || columnas() != b->columnas())
   {
      printf("Error en dimensi�n de los vectores al sumar\n");
      visualizaInformacion();
      a->visualizaInformacion();
      b->visualizaInformacion();
      exit(1);
   }
#endif
   int i;
   for (i = 0; i < Col; i++) V[i] = a->retorna(i) + b->retorna(i);
}

// Suma al vector a
// @param a Puntero a un vector
void Vector::suma(Vector *a)
{
#ifdef DEPURAR
   if (columnas() != a->columnas())
   {
      printf("Error en dimensi�n de los vectores al sumar\n");
      visualizaInformacion();
      a->visualizaInformacion();
      exit(1);
   }
#endif
   int i;
   for (i = 0; i < Col; i++) V[i] += a->retorna(i);
}

// Resta los vectores a menos b
// @param a Puntero a un vector
// @param b Puntero a un vector
void Vector::resta(Vector *a, Vector *b)
{
#ifdef DEPURAR
   if (columnas() != a->columnas() || columnas() != b->columnas())
   {
      printf("Error en dimensi�n de los vectores al restar\n");
      visualizaInformacion();
      a->visualizaInformacion();
      b->visualizaInformacion();
      exit(1);
   }
#endif

   int i;
   for (i = 0; i < Col; i++) V[i] = a->retorna(i) - b->retorna(i);
}

// Resta el vector a
// @param a Puntero a un vector
void Vector::resta(Vector *a)
{
#ifdef DEPURAR
   if (columnas() != a->columnas())
   {
      printf("Error en dimensi�n de los vectores al restar\n");
      visualizaInformacion();
      a->visualizaInformacion();
      exit(1);
   }
#endif

   int i;
   for (i = 0; i < Col; i++) V[i] -= a->retorna(i);
}

// Multiplica el vector por el escalar ESC
// @param esc Valor escalar
void Vector::multiplica(ldouble esc)
{
   int i;
   for (i = 0; i < Col; i++) V[i] *= esc;
}


// Calcula la norma infinito
// @return Valor del la norma infinita
ldouble Vector::normaInf(void)
{
   ldouble max = 0.0;
   int i;
   for (i = 0; i < Col; i++)
   {
#ifdef __Double__
      if (fabs(V[i]) > max) max = fabs(V[i]);
#else
      if (fabsl(V[i]) > max) max = fabsl(V[i]);
#endif

   }

   return max;
}


// Calcula el producto punto
// @return Valor del producto punto
ldouble Vector::productoPunto(void)
{
   int i;
   ldouble val = 0.0;
   for (i = 0; i < Col; i++) val += V[i] * V[i];

   return val;
}

// Calcula el producto punto
// @param a Puntero a un vector
// @return Valor del producto punto
ldouble Vector::productoPunto(Vector *a)
{
   int i;
   ldouble val = 0.0;
   for (i = 0; i < Col; i++) val += V[i] * a->retorna(i);

   return val;
}

// Es el vector en todas sus componentes m�s peque�o que eps
// @return (1) si es el vector cero, (0)en caso contrario
int Vector::esVectorCero(void)
{
   int i;
   for (i = 0; i < Col; i++)
   {

      if (V[i] != 0.0) return 0;
   }
   return 1;
}


// Es el vector en todas sus componentes m�s peque�o que EPS
// @return (1) si todas las componentes son m�s peque�as que eps, (0) en caso contrario
int Vector::esCadaEntradaMasPequeno(double eps)
{
   int i;
   for (i = 0; i < Col; i++)
   {
#ifdef __Double__
      if (fabs(V[i]) >= eps) return 0;
#else
      if (fabsl(V[i]) >= eps) return 0;
#endif
   }
   return 1;
}

