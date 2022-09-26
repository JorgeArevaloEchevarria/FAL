#include<iostream>

using namespace std;

const int MAX = 100;
/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

(2) An�lisis de casos

	 (2.1) Caso(s) base


	 (2.2) Caso(s) recursivos

(3) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
	a partir de la misma, por inmersi�n.


*/

/*
(1) Ecuaciones de recurrencia

(2) Resoluci�n de las ecuaciones (aplicaci�n de los patrones de resouluci�n)

(3) Complejidad final del algoritmo.

(4) Posibles ventajas y desventajas de tu algoritmo frente a una soluci�n iterativa de coste
	 lineal


*/
void crossG(int v[], int w[], int n, int& i, int& j, int init, int fin) {
	if (v[0] > w[0]) {
		i = -1;
		j = 0;
	}
	else if (v[n] < w[n]) {
		i = n - 1;
		j = n;
	}
	else if () {
		
	
	}
	else {

		crossG(v, w, n, i, j, init, fin / 2);
		crossG(v, w, n, i, j, fin / 2, fin);
	}


}
void cross(int v[], int w[], int n, int& i, int& j) {
	crossG(v, w, n, i, j, 0, n);
}
int main(int argc, char* args[]) {
	int N;
	int V[MAX], W[MAX];
	int i, j;
	int n;
	for (cin >> N; N; cin >> N)
	{
		for (int n = 0; n < N; n++) cin >> V[n];
		for (int n = 0; n < N; n++) cin >> W[n];
		cross(V, W, N, i, j);
		cout << i << " " << j << endl;
	}
	return 0;
}


/*

5
1 3 4 7 8
8 7 4 2 1
2 3
6
-5 -3 -1 0 4 7
9 6 5 2 1 0

3 4
6
1 3 4 5 7 8
-1 -2 -4 -5 -7 -8
-1 0
6
1 3 4 5 7 8
17 14 12 11 9 8
5 6
0



*/ /