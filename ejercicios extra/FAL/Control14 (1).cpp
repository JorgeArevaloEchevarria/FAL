/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/

#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;


typedef unsigned long long t_num;

void cuentanum(t_num num, t_num& resul, int& ult_digit, bool& par);
void cuentaok(t_num num, t_num& resul, int this_digit, int& ult_digit, int i, bool& end);
void compara();
int recursivo(t_num num);
int iterativo(t_num num);

/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.


(2) Análisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.



*/
void cuentanum(t_num n, t_num& resul, int& ult_digit, bool& par) {
	if (n < 9) {
		resul++;
	}
	else {
		n = n / 10;
		ult_digit = n % 10;
		if ((ult_digit % 2 == 0 && par) || (ult_digit % 2 != 0 && !par)) {
			return;
		}
		par = !par;
		cuentanum(n, resul, ult_digit, par);
	}

}

void cuentaok(t_num n, t_num& resul, int this_digit, int& ult_digit, int i, bool& end) {
	if (n < 10) {
		for (int j = i; j > 0; j--){
			resul += pow(5, j) * 9;
		}
		resul += pow(5, i+1) * (n - 1);
		ult_digit = n;
	}
	else {
		i++;
		this_digit = n % 10;
		cuentaok(n/10, resul, this_digit, ult_digit, i,end);

		if (!end) {
			if (i == 0) {
				if (/*(this_digit % 2 == 0 && ult_digit % 2 == 0) ||*/ (this_digit % 2 != 0 && ult_digit % 2 != 0)) {
					resul += (this_digit / 2) + 1;
				}
				else resul += this_digit / 2;
			}
			else {
				if (/*(this_digit % 2 == 0 && ult_digit % 2 == 0) ||*/ (this_digit % 2 != 0 && ult_digit % 2 != 0)) {
					end = true;
					resul += pow(5, i) * ((this_digit / 2) + 1);
				}
				else resul += pow(5, i) * (this_digit / 2);
				
				if (this_digit % 2 == 0 && ult_digit % 2 == 0) {
					end = true;
				}
				ult_digit = this_digit;
			}
		}

	}
}
void compara() {
	for (int i = 1; i < 10000; i++) {
		t_num  n = (t_num)rand();
		t_num nok = n;
		t_num n2 = n;
		
		int resul = iterativo(n);
		int resul2 = recursivo(nok);
		if (resul != resul2) {
			cout << "NO FUNCIONA" << endl;
			cout << n2 << ":" << resul << "..." << resul2 << endl;
			break;
		}
	}
}
int recursivo(t_num n) {
	if (n == 0) {
		return 0;
	}
	else if (n < 10) {
		return n;
	}
	else if (n < 100 && n > 9) {
		int ult_digit = n % 10;
		n = n / 10;
		int first_digit = n % 10;
		if ((first_digit % 2 == 0 && ult_digit % 2 == 0) || (first_digit % 2 != 0 && ult_digit % 2 != 0)) {
			return ((first_digit + 1) * 5) + (ult_digit / 2) + 1;
		}
		else return ((first_digit + 1) * 5) + (ult_digit / 2);
	}
	else {
		t_num resul = 10;
		int ult_digit;
		int this_digit = 0;
		int j = -1;
		bool end = false;
		cuentaok(n, resul, this_digit, ult_digit, j, end);
		return resul;
	}
}
int iterativo(t_num n) {
	if (n == 0) {
		return 0;
	}
	else if (n < 10) {
		return n;
	}
	else if (n < 100 && n > 9) {
		int ult_digit = n % 10;
		n = n / 10;
		int first_digit = n % 10;
		if ((first_digit % 2 == 0 && ult_digit % 2 == 0) || (first_digit % 2 != 0 && ult_digit % 2 != 0)) {
			return ((first_digit + 1) * 5) + (ult_digit / 2) + 1;
		}
		else return ((first_digit + 1) * 5) + (ult_digit / 2);
	}
	else {
		t_num resul = 10;
		bool par = false;
		int ult_digit;
		int this_digit = 0;
		for (n--; n > 9; n--) {
			par = false;
			ult_digit = n % 10;
			if (ult_digit % 2 == 0) {
				par = true;
			}
			cuentanum(n, resul, ult_digit, par);
		}
		return resul;
	}

}
t_num num_alternados(t_num n) {
	// PUNTO ENTRADA AL ALGORITMO

	if (n == 0) {
		return 0;
	}
	else if (n < 10) {
		return n;
	}
	else if (n < 100 && n > 9) {
		int ult_digit = n % 10;
		n = n / 10;
		int first_digit = n % 10;
		if ((first_digit % 2 == 0 && ult_digit % 2 == 0) || (first_digit % 2 != 0 && ult_digit % 2 != 0)) {
			return ((first_digit+1) * 5) + (ult_digit / 2) + 1;
		}
		else return ((first_digit+1) * 5) + (ult_digit / 2);
	}
	else {
		return iterativo(n);
		//return recursivo(n);
		//compara();
		//return 0;
		
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinación de las ecuaciones de recurrencia para la generalización

(2) Resolución utilizando los patrones vistos en clase

(3) Determinación justificada de la complejidad del algoritmo final.


*/


bool procesa_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_alternados((t_num)n) << endl;
		return true;
	}

}

int main() {
	while (procesa_caso());

}