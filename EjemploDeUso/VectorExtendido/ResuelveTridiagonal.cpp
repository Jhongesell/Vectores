//////////////////////////////////////////////////////////////////////////////////////////////
// Clase para resolver un sistema lineal tridiagonal                                        //
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


#include "ResuelveTridiagonal.hpp"


// Resuelve el sistema lineal
void ResuelveTridiagonal::resuelve(void)
{
#ifdef DEPURAR
   if (!M->matrizCuadrada()) error("matriz no cuadrada");
#endif

   int i;
   ldouble XX, XY;

   // Factorizaci�n LU
   for (i = 0; i < M->renglones()-1; i++)
   {
#ifdef DEPURAR
      if (M->retorna(i,i) == 0.0) error("Diagonal con valores cero");
#endif
      XX = M->retorna(i,i+1) / M->retorna(i,i);
      M->asigna(i,i+1,XX);
      XY = M->retorna(i+1,i+1) - M->retorna(i+1,i) * XX;
      M->asigna(i+1,i+1,XY);
   }

   // Resuelve Lx=y
#ifdef DEPURAR
   if (M->retorna(0,0) == 0.0) error("Diagonal con valores cero");
#endif
   X->asigna(0,B->retorna(0) / M->retorna(0,0));
   for (i = 1; i < M->renglones(); i++)
   {
#ifdef DEPURAR
      if (M->retorna(i,i) == 0.0) error("Diagonal con valores cero");
#endif
      X->asigna(i,(B->retorna(i) - M->retorna(i,i-1) * X->retorna(i - 1)) / M->retorna(i,i));
   }
   // Resuleve Ux=y
   for (i = M->renglones() - 2; i >= 0; i--) X->asigna(i,X->retorna(i) - X->retorna(i+1) * M->retorna(i,i+1));
}


