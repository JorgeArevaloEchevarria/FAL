/*
No Grupo:
Nombre y Apellidos de los miembros:

*/


// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#include <climits>
#endif


using namespace std;

typedef unsigned long long t_num;

/*
(1) Determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro 
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa. 

  - t_num n, par�metro de entrada: El n�mero para el cu�l hay
    que calcular todos los naturales menores que �l, que no 
	tengan d�gitos repetidos.
  - num_menos_num_digs, par�metro de salida: Cantidad de 
    naturales postivos sin d�gitos repetidos, y que tienen
	menos d�gitos que 'n'
  - num_mismo_num_digs, par�metro de salida: Cantidad de
    naturales positivos menores que 'n', sin d�gitos repetidos,
	y con exactamente el mismo n�mero de d�gitos que 'n'
  - c = 9*9*8*7 ...
  - digs_rep: true si n tiene d�gitos repetidos, false en otro 
               caso
  - ndigs: Numero de d�gitos de n
  - digs: Array de 10 booleanos. digs[x] = true si el  
          digito x est� en 'n', y false en caso contrario  


(2) An�lisis de casos para la generalizaci�n:
  
  (2.1) Casos base
     * n tiene un �nico d�gito (n <= 9). 
	     num_menos_num_digs = 0
		 num_mismo_num_digs = n-1
		 c = 9
		 digs_rep = false
		 ndigs = 1
		 digs[n] = true

  (2.2) Casos recursivos		 
	 * n tiene m�s de un d�gito (n > 9)
          - Resolvemos el problema para n menos el �ltimo d�gito
            (es decir, para n/10) =>
			 cuenta_sinrepetidos_menoresque(n/10,
			                                num_menos_num_digs,
											num_mismo_num_digs,
											c,
											digs_rep,
											ndigs,
											digs)
		  - Para resolver el problema para n:
              * Se suma c a num_menos_num_digs
              * Se actualiza c, multiplic�ndolo por 
                   (10 - ndigs)
              * Se multiplica num_mismo_num_digs por
                   (10 - ndigs)
              * Si no hay digitos repetidos (! digs_reps):
                  Para cada digito d menor que n%10,
                  en caso de que d no aparezca en n/10 
                  (es decir, ! digs[d]), incrementar
                  num_mismo_num_digs
              * Se incrementa en 1 el n�mero de d�gitos
			  * En caso de que n%10 aparezca en n/10
                (es decir, en caso de que digs[d] sea true),
                fijar digs_rep a true
              * Fijar digs[n%10] a true   				
			  

(3) Definici�n por inmersi�n del algoritmo. Describe
de manera clara y concisa c�mo se lleva a cabo el algoritmo,
en qu� punto o puntos se invoca a la generalizaci�n, 
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n. 
 
   * Los casos n=0 y n>= 10000000000LL se tratan 
     devolviendo directamente el resultado (0,
	 y 8877691LL respectivamente)
   * El resto de los casos se resuelven 
      - invocando a la generalizaci�n como:
	  cuenta_sinrepetidos_menoresque(n,
			                         num_menos_num_digs,
									 num_mismo_num_digs,
									 c,
									 digs_rep,
									 ndigs,
									 digs)
	  - devolviendo el resultado como
            num_menos_num_digs + num_mismo_num_digs + 1	  
	  
*/

void cuenta_sinrepetidos_menoresque(t_num n,
 	                                t_num& num_menos_num_digs,
	                                t_num& num_mismo_num_digs,
									t_num& c,
									bool& digs_rep,
									unsigned short& ndigs,
 									bool digs[]
	                                ) {
	if (n<=9) {
		num_menos_num_digs = 0;
		num_mismo_num_digs = n - 1;
		c = 9;
		digs_rep = false;
		ndigs = 1;
		digs[n] = true;
	}
	else {
		cuenta_sinrepetidos_menoresque(n/10,
			                           num_menos_num_digs,
									   num_mismo_num_digs,
									   c,
									   digs_rep,
									   ndigs,
									   digs);
		num_menos_num_digs += c;
		unsigned short quedan = (10 - ndigs);
		c *= quedan;
		num_mismo_num_digs *= quedan;
		unsigned short ult_dig = (unsigned short) (n%10);
		if (! digs_rep) {
	     	for (unsigned short d=0; d < ult_dig; d++) {
	       	    if (! digs[d]) {
					num_mismo_num_digs++;
				}	
		    }
		}
		ndigs++;
        if (digs[ult_dig]) {
		   digs_rep = true;	
		}
        digs[ult_dig] = true;				
	}
}

t_num num_sinrepetidos_menoresque(t_num n) {
	if (n == 0) {
		return 0;
	}
	else if (n >= 10000000000LL) {
		return 8877691LL;
	}
	else {
		t_num num_menos_num_digs;
		t_num num_mismo_num_digs;
	    t_num c;
		bool digs_rep;
		unsigned short ndigs;
		bool digs[10];
		for (int d = 0; d < 10; d++) {
			digs[d] = false;
		}
		cuenta_sinrepetidos_menoresque(n,
			                         num_menos_num_digs,
									 num_mismo_num_digs,
									 c,
									 digs_rep,
									 ndigs,
									 digs);
		return num_menos_num_digs + num_mismo_num_digs + 1;							 
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

  t(1) = co
  t(n) = c1 + t(n/10)

(2) Resoluci�n utilizando los patrones vistos en clase
  Es una recurrencia por divisi�n, donde:
    - a=1
	- k = 0
	- b = 10
  Por tanto, b^k = 1. Es decir, estamos en el caso
   a = b^k. Por tanto t(n) ser� O(n^k log n). Es decir,
   O(n^0 log n). Es decir O(log n)   
  


(3) Determinaci�n justificada de la complejidad del algoritmo final.
La complejidad es O(1), ya que los casos especiales se ejecutan
en tiempo constante, y el tiempo que tarda en ejecutarse el 
caso inmerso est� acotado por la ejecuci�n para 9999999999LL,
que es una cte (aunque muy grande). 

*/



// No modificar el c�digo que sigue

#ifndef DOM_JUDGE

bool digs_reps(t_num n) {
	bool digs[10];
	for (unsigned short d = 0; d < 10; d++) {
		digs[d] = false;
	}
	while (n > 0 && !digs[n % 10]) {
		digs[n % 10] = true;
		n /= 10;
	}
	return n != 0;
}

t_num num_sinrepetidos_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (!digs_reps(i)) num++;
	}
	return num;
}
#endif


#ifdef DOM_JUDGE

bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_sinrepetidos_menoresque(n) << endl;
		return true;
	}
}
#endif


int main() { 
#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

#ifndef DOM_JUDGE

	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_sinrepetidos_menoresque_naif(n) != num_sinrepetidos_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_sinrepetidos_menoresque_naif(n) << "..." << num_sinrepetidos_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause"); 
#endif

}