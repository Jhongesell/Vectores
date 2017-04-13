//////////////////////////////////////////////////////////////////////////////////////////////
// Programa para usar la clase de matriz bandada                                            //
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



#include "Definiciones.hpp"
#include "MatrizBand.hpp"
#include "ResuelveTridiagonal.hpp"
#include "VectorExtendido.hpp"


void RevisionConsumoMemoriaMatrizBandada(void);
void ResuelveEDP(void);


int main(void)
{
   int i;

   // Ejemplo de una ecuaci�n diferencial parcial en 1D
   // -Uxx + Ux = 0
   // 0 < U < 1
   // U(0)=0 y U(1)=1

   
   ldouble a=0;             // Inicio dominio
   ldouble c=1;             // Fin dominio
   int M=500;               // Partici�n
   int N=M-2;               // Nodos interiores
   ldouble h=(c-a)/(M-1);   // Incremento en la malla
   ldouble Y0=0.0;          // Condici�n inicial en el inicio del dominio
   ldouble Y1=1.0;          // Condici�n inicial en el fin del dominio


   MatrizBand *A = new MatrizBand(N,N,3,"A");
   Vector *b = new Vector(N,"Lado Derecho");
   Vector *x = new Vector(N,"Solucion Sistema Lineal");
   
   VectorExtendido *t = new VectorExtendido(M,x,"Solucion Total");
   t->inicializa(0,Y0);
   for (i = 0; i < N; i++) t->inicializa(i+1,i);
   t->inicializa(i+1,Y1);


   ldouble P=2/(h*h);
   ldouble Q=-1/(h*h)+1/(2*h);
   ldouble R=-1/(h*h)-1/(2*h);

   // Primer renglon de la matriz A y vector b
   A->asigna(0,0,P);
   A->asigna(0,1,Q);
   b->asigna(0,-Y0*R);
   // Renglones intermedios de la matriz A y vector b
   for(i=1;i <N-1;i++) 
   {
     A->asigna(i,i-1,R);
     A->asigna(i,i,P);
     A->asigna(i,i+1,Q);
   }
   // Relglon final de la matriz A y vector b
   A->asigna(N-1,N-2,R);
   A->asigna(N-1,N-1,P);

   b->asigna(N-1,-Y1*Q);


   //~ A->visualiza(0);
   

   // Resuleve el sistema lineal Ax=b
   ResuelveTridiagonal rs(A);
   rs.resuelve(x,b);
   
   //~ x->visualiza(0,1,1);

   t->visualiza(0,1,1);

   
   delete A;
   delete b;
   delete t;
   delete x;   
   
   return 0;
}