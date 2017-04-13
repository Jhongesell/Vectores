//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para el trabajar con matrices de punto flotante                                    //
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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Matriz_Base.hpp"
#include "Ctrl_vis.hpp"


/// Tipos de matrices
static char TM[][50]= {"Matriz Bandada","Matriz Densa","Matriz Densa Entera","Matriz Dispersa","Matriz Bandada Compacta","Matriz Dispersa Compacta","Matriz Rala"};


// Asigna nombre a la matriz
// @param nmb Nombre de la matriz
void Matriz_Base::asignaNombre(const char *nmb)
{
   Nmb = new char[strlen(nmb)+2];
   if (!Nmb)
   {
      printf("\nError no hay memoria para el nombre de la matriz\n");
      exit(1);
   }
   strcpy(Nmb, nmb);
}



// Visualiza informaci�n general de la matriz
void Matriz_Base::visualizaInformacion(void)
{
   if (Tipo_Matriz == MATRIZ_BANDADA || Tipo_Matriz == MATRIZ_BANDADA_COMPACTA || Tipo_Matriz == MATRIZ_DISPERSA || Tipo_Matriz == MATRIZ_DISPERSA_COMPACTA) printf("\n%s \"%s\" de dimensi�n: %d x %d y banda %d",TM[Tipo_Matriz],Nmb,Ren,Col,Ban);
   else printf("\n%s \"%s\" de dimensi�n: %d x %d",TM[Tipo_Matriz],Nmb,Ren,Col);
   printf("\nN�mero de entradas distintas de cero: %d",entradasDistintasCero());
   printf("\nNumero m�ximo de columnas ocupadas: %d\n\n",maximoTamanoColumnaOcupado());
}


// Tama�o de la matriz (aproximado) en Kb
// @return Tama�o de la matriz en Kb
ldouble Matriz_Base::tamano(void)
{
   ldouble t;
   switch (Tipo_Matriz)
   {
   case 1:
      t = ((long) sizeof(ldouble) * Ren * Col) / 1024.0;
      break;
   case 2:
      t = ((long) sizeof(int) * Ren * Col) / 1024.0;
      break;
   default:
      t = (((long) sizeof(ldouble) * Ren * Ban) +  ((long) sizeof(int) * Ren * Ban)) / 1024.0;
   }
   return t;
}

// Visualiza el tama�o en memoria de la matriz en Kb
void Matriz_Base::visualizaTamano(void)
{
   Ctrl_visualizacion cv;
   printf("\nTama�o:");
   cv.visualiza_n(tamano());
   printf("Kb\n");
}




