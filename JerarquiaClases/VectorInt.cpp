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



#include <stdlib.h>
#include <string.h>
#include "VectorInt.hpp"
#include "Ctrl_vis.hpp"



// Solicita la memoria necesaria para contener los valores del vector
// @param col N�mero de columnas del vector
// @param val Valor por omision para inicializar el vector
void VectorInt::solicitaMemoria(const int col, const int val)
{
   V = new int[col];
   if (!V)
   {
      printf("\nError no hay memoria para el vector\n");
      exit(1);
   }
   Col = col;
   int i;
   for (i = 0; i < Col; i++) V[i] = val;
}



// Inicializa el vector al valor val indicado
// @param val Valor por omisi�n para inicializar el vector
void VectorInt::inicializa(const int val)
{
   int i;
   for (i = 0; i < Col; i++) V[i] = val;
}


// Visualiza el vector
// @param nl (1) Visualiza el vector en forma renglones, (0) en forma de columnas
// @param num (1) Numera las componentes del vector, (0) no lo hace
void VectorInt::visualiza(int nl, int num)
{
   int i;
   Ctrl_visualizacion cv;
   printf("\nVector \"%s\" de %d elementos\n",Nmb,Col);
   for (i = 0; i < Col; i++)
   {
      // Visualiza el n�mero de elemento
      if (num) printf("%d: ",i);
      cv.visualiza(V[i]);
      // Cambia de linea
      if (nl) printf("\n");
   }
   printf("\n");
}

// Copia el contenido del vector al vector a
// @param col Columna
// @param val Valor
void VectorInt::copia(VectorInt *a)
{
#ifdef DEPURAR
   if (Col != a->columnas())
   {
      printf("Error en dimensi�n de los vectores al copiar\n");
      exit(1);
   }
#endif
   int i;
   for (i = 0; i < Col; i++) a->asigna(i,V[i]);
}

