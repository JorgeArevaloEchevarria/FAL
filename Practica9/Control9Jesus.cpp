/*
N� Grupo: D04

Nombre y apellidos de los miembros del grupo: Jesus Martin y Jorge Arevalo

*/

//#define DOM_JUDGE

#include <iostream>

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif

using namespace std;

int calcula_long(int a[], int ini, int fin, int &long_ini, int &long_final);
int max(int first, int second, int inter);

/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

(2) An�lisis de casos

	 (2.1) Caso(s) base


	 (2.2) Caso(s) recursivos

(3) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
	a partir de la misma, por inmersi�n.


*/

int calcula_long(int a[], int ini, int fin, int &long_ini, int &long_final) {
	int max = 0, aux = 1;
	for (int i = ini; i < fin; i++) {
		if (a[i] == a[i + 1]) {
			aux++;
		}
		else {//camio de numero
			if (long_ini == -1) {
				long_ini = aux;
				max = aux;
			}
			else if (aux > max) {
				max = aux;
			}
			aux = 1;
		}
	}
	if (long_ini == -1) {
		long_ini = aux;
	}
	long_final = aux;
	if (aux > max)
		max = aux;
	return max;
}
int max(int first, int second, int inter) {
	if (first >= second) {
		if (first >= inter)
			return first;
		else return inter;
	}
	else {
		if (second >= inter)
			return second;
		else return inter;
	}
}

//pre: a est� ordenado. n > 0
int lon_tramo_cte_max(int a[], int n) {
	// Punto de entrada al algoritmo. A implementar
	int long_ini = -1, long_ini2 = -1;
	int long_fin = -1, long_fin2 = -1;
	int fin = (n / 2) - 1;
	int ini = n / 2;
	int long_inter = 0;

	int long_first = calcula_long(a, 0, fin, long_ini, long_fin);
	int long_second = calcula_long(a, ini, n-1, long_ini2, long_fin2);

	if (a[fin] == a[ini]) {
		long_inter = long_fin + long_ini2;
	}

	return max(long_first,long_second,long_inter);
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