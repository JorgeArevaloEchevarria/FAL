/*
No Grupo:04
Nombre y Apellidos de los miembros: Jesus Martin Moraleda y Jorge Arevalo Echevarria

*/


// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#include <iostream>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

using namespace std;

typedef unsigned long long t_num;

/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.

 - t_num n, parametro de entrada: El numero para el cual hay
	que calcular todos los naturales menores que el, que sean
	numeros singulares.
	y con exactamente el mismo n�mero de digitos que 'n'
- int primerDig, parametro de entrada que nops dice cual es el primer digito significativo de n
  - c acumulador de suma de numeros singulares menores
  - digRep: true si n tiene digitos repetidos, false en otro caso


(2) An�lisis de casos:

(2.1) Casos base
	-si n <= 9 -> n

(2.2) Casos recursivos
	- si n > 9 :
		-sea c' la solucion para n/10 c = 9 * c' //por nueve, por q al añadir otro digito, no se podria repetir el primer digito
			-si n/10 no tiene el digito simbolico:
				- si n%10 = 1 -> sumar 1
				- si n%10 > 1 ->(n%10-1)

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



*/

void cuenta_singulares(t_num n, t_num& c, int primerDig) {
	// Punto de entrada al algoritmo.
		// A implementar
	if (n <= 9) {
		if (n < primerDig)
			c = n;
		else
			c = n - 1;
	}
	else {
		cuenta_singulares(n / 10, c, primerDig);
		c *= 9;
		if (n % 10 < primerDig) {
			c += ((n % 10));
		}
		else {
			c += ((n % 10) - 1);//ya que el digito singular no se añade
		}

	}

}



t_num num_singulares_menoresque(t_num n) {


	if (n <= 9) {
		return n;

	}
	else {

		t_num  c, i = n;
		while (i >= 10)
			i /= 10;

		int primerDig = i;
		cuenta_singulares(n, c, primerDig);
		return c;
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(2) Resoluci�n utilizando los patrones vistos en clase

(3) Determinaci�n justificada de la complejidad del algoritmo final.


*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		}
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
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}