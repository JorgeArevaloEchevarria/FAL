/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/


#include <iostream>

using namespace std;

typedef unsigned long long t_num;

bool limpio(unsigned short d, unsigned short alpha, t_num n, unsigned int s);

/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
bool limpio(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	int digit = n;
	int suma = 0;
	int cont = 0;

	//caso base numeros de un digito
	if (alpha == 1 && n < 10 && d == n) {//que no sea a limpio
		if (n != 0 && n != s) {//que sea 0 o sea la suma
			return false;
		}
		
	}

	while (n > 0) {
		digit = n % 10;
		suma += digit;
		n /= 10;
		if (digit == 0 || suma > s) {//poda: si hay un 0 o me he pasado de la suma
			return false;
		}
		if (digit == d)
			cont++;
		else
			cont = 0;

		if (cont >= alpha)//poda: si ya no es a limpio
			return false;
	}
	if (suma == s && cont < alpha) {
		return true;
	}
	else return false;
}

int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	int cont = 0;
	if (n == 0 || n == 1) {
		return 0;
	}
	if (alpha == 0) {
		return 0;
	}
	for (int i = n - 1; i > 0; i--) {
		if (limpio(d,alpha,i,s)) {
			cont++;
		}
	}
	return cont;
}


bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha;
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}