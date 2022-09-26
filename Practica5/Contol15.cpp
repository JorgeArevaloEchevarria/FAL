/*

NUMERO DE GRUPO:04

NOMBRRE Y APELLIDOS DE LOS AUTORES: Jorge Arevalo Echevarria y Jesus Martin Moraleda

*/

#include <iostream>

using namespace std;





/*
(1) En caso de utilizar una generalizacion,
determinaci?n de los par?metros de la generalizaci?n.
Determina los par?metros de la generalizaci?n. Para cada par?metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par?metro
de entrada, de salida, o de entrada / salida; (iv) su prop?sito,
descrito de manera clara y concisa.
//utilizamos la generalizacion el metodo buscaPosicion(int a[], int ini, int fin, int &posicion
-- int a[] parametro de entrada , vector  en el que almacenamos los numeros
-- int ini paramentro de entrada, variable que usamos como pivote inicial para explorar el vector
-- int ini paramentro de entrada, variable que usamos como pivote final para explorar el vector
-- int &posicion parametro de salida, vatriable que usamos para devolver la posicion impar

(2) An?lisis de casos:

(2.1) Casos base
	if(ini==fin)
		if (a[ini] % 2 != 0)//miarmos si es impar
		//y si es impar guardamos la posicion


(2.2) Casos recursivos
	int mitad = (ini + fin) / 2;
	buscaPosicion(a, ini, mitad,posicion);// reducimos la exploracion al lado izquierdo
	buscaPosicion(a, mitad + 1, fin,posicion);// reducimos la exploracion al lado derecho

(3) En caso de utilizar una generalizacion, definici?n por inmersi?n
del algoritmo. Describe de manera clara y concisa c?mo se lleva a
cabo el algoritmo, en qu? punto o puntos se invoca a la generalizaci?n,
con qu? par?metros reales, y c?mo se genera el resultado
a partir de los devueltos por la generalizaci?n.

en nuestro caso utilizamos la generalizacion en buscaPosicion, con los parametros
ini siendo la primera posicion del vector y fin la ultima posicion del vector.
como posicion es una variable de salida nos dara la posicion del impar.
despues reducimos la exploracion en dos partes hasta que ini == fin 
en el que comprobamos si el numero es impar y en caso que sea actualizamos posicion.
*/




void buscaPosicion(int a[], int ini, int fin, int &posicion) {
	if (ini == fin) {
		if (a[ini] % 2 != 0)
			posicion = ini;
	}
	else {
		int mitad = (ini + fin) / 2;
		buscaPosicion(a, ini, mitad,posicion);
		buscaPosicion(a, mitad + 1, fin,posicion);
	}

}


int posicion_impar(int a[], int n) {
	// PUNTO DE ENTRADA AL ALGORITMO
	int posicion = -1;
	buscaPosicion(a, 0, n - 1,posicion);
	return posicion;
}



/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci?n de las ecuaciones de recurrencia para la generalizaci?n
T(1) = C0
T(n) = w(n) + Cn, con w(n)->O(n) 

(2) Resoluci?n utilizando los patrones vistos en clase

(3) Determinaci?n justificada de la complejidad del algoritmo final.
la complejidad del algoritmo final es O(n) ya que exploraremos la n posiciones del vector solo una vez cada una.

*/



const int MAX = 10000;

void genera_vector(int prim, int ult, int impar, int a[], int& n) {
	n = 0;
	for (int i = prim; i <= ult; i++) {
		if (i % 2 == 0 || i == impar) {
			a[n++] = i;
		}
	}
}

bool ejecuta_caso() {
	int a[MAX];
	int prim;
	cin >> prim;
	if (prim == -1) {
		return false;
	}
	else {
		int ult, impar;
		cin >> ult >> impar;
		int n;
		genera_vector(prim, ult, impar, a, n);
		cout << posicion_impar(a, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}