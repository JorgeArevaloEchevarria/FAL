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

  


(2) An�lisis de casos para la generalizaci�n:

  (2.1) Casos base
	

  (2.2) Casos recursivos
	


(3) Definici�n por inmersi�n del algoritmo. Describe
de manera clara y concisa c�mo se lleva a cabo el algoritmo,
en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

  
*/



t_num num_sinrepetidos_menoresque(t_num n) {
	
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
}
