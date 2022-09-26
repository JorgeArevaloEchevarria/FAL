/*
N� Grupo: 04

Nombre y apellidos de los miembros del grupo: Jesus Martin Moraleda y Jorge Arevalo Echevarria

*/

//#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;


/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

(2) An�lisis de casos

	 (2.1) Caso(s) base


	 (2.2) Caso(s) recursivos

(3) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
	a partir de la misma, por inmersi�n.


*/

bool subtramo(int a[], int n) {
	return a[n] == a[n + 1];
}

//pre: a est� ordenado. n > 0
int lon_tramo_cte_max(int a[], int n) {
	int num = a[0];
	int longmax = 1, lon = 1;

	if (n == 1) {//caso base
		return 1;
	}
	else if (n == 2) {
		if (subtramo(a, 0))
			return 2;
		else return 1;
	}
	for (int i = 1; i < n; i = i + 2) {
		num = a[i];
		if (subtramo(a, i)) {
			if (a[i - 1] == num) {
				lon += 2;
			}
			else {//cambio de numero
				if (lon > longmax) {
					longmax = lon;
				}
				lon = 2;
			}
			if (lon > longmax) {
				longmax = lon;
			}

		}
		else {//cambio de numero
			if (a[i - 1] == num) {
				lon++;
			}
			if (lon > longmax) {
				longmax = lon;
			}
			lon = 1;
		}

	}
	/*if (n % 2 == 0) {
		if (a[n - 1] == num) {
			lon++;
		}
		if (lon > longmax) {
			longmax = lon;
		}
	}*/
	return longmax;
}
/*
(1) Ecuaciones de recurrencia

(2) Resoluci�n de las ecuaciones (aplicaci�n de los patrones de resouluci�n)

(3) Complejidad final del algoritmo.

(4) Posibles ventajas y desventajas de tu algoritmo frente a una soluci�n iterativa de coste
	 lineal


*/


#ifndef DOM_JUDGE
int lon_tramo_cte_max_it(int a[], int n) {
	int lon = 1;
	int pos = 1;
	int lon_max = 1;
	while (pos != n) {
		if (a[pos] == a[pos - 1]) {
			lon++;
		}
		else {
			lon = 1;
		}
		if (lon > lon_max) {
			lon_max = lon;
		}
		pos++;
	}
	return lon_max;
}


const int MAX_LON = 40;
const int MAX_INIT = 20;
const int MAX_INC = 10;


void genera_caso(int a[], int& n) {
	n = (rand() % MAX_LON) + 1;
	a[0] = rand() % MAX_INIT;
	for (int i = 1; i < n; i++) {
		if (rand() % 2 == 0) {
			a[i] = a[i - 1];
		}
		else {
			a[i] = a[i - 1] + (rand() % MAX_INC);
		}
	}

}

const int MAX_PRUEBAS = 1000;
#endif

#ifdef DOM_JUDGE
const int MAX_LON = 10000;

bool ejecuta_caso() {
	int a[MAX_LON];
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << lon_tramo_cte_max(a, n) << endl;
		return true;
	}
}

#endif

int main() {
#ifndef DOM_JUDGE
	int a[MAX_LON];
	int n;
	srand(time(NULL));
	int i = 0;
	int ok = true;
	while (i < MAX_PRUEBAS && ok) {
		genera_caso(a, n);
		if (lon_tramo_cte_max_it(a, n) != lon_tramo_cte_max(a, n)) {
			cout << "NO FUNCIONA PARA: ";
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			ok = false;
		}
		i++;
	}
	if (ok) {
		cout << "OK" << endl;
	}
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

}