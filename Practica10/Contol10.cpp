/*

NUMERO DE GRUPO: 04

NOMBRE Y APELLIDOS DE LOS AUTORES: Jesus Martin Moraleda y Jorge Arevalo Echeverria


*/


#include <iostream>

using namespace std;

const int MAXN = 10;


/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
	sirven cada uno de ellos
	hemos utilizado avanza, con los parametros:int coleccion[], int n, int k, int i, int suma
	- int coleccion[] : vector que almacena la coleccion de numeros, para el modulo.
	- int n : numero de elemntos que hay en el vector coleccion
	- int k : numero sobre el que hacemos el modulo para saber los numeros de coleccion[] que forman la suma
	- int i : variable que utilizamos para explorar el vector
	- int suma : variable que utilizamos para saber que suma llevamos con las varibales de coleccion[]

(2) ¿Cómo son las soluciones parciales de este problema?
		el contador de sumas,que se incrementa cuando al recorrer el vector,
		encontramos componentes que sumandose entre ellas generan modulo con k

(3) ¿Cuándo una solución parcial es viable?
		cuando puede extenderse hasta llevarnos al caso de una solucion final, en este caso,
		mientras la suma de las componentes no supere al numero k sera una solucion viable, con posiblidad de solucion final

(4) ¿Cuándo una solución parcial es una solución final al problema?
		cuando la suma de las sub-coleciones del vector sea igual al numero k.

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones parciales viables?
		Encontrando todas las posibles soluciones a partir de esa posicion (j) ,
		y exploramos con la variable (i) si para ver si generamos una solucion, si no es viable se aborta la rama,
		 y despues incrementados j para expolorar las soluciones a partir de la siguiente posicion


(6) Análisis de casos

	 (6.1) Caso(s) base : si la suma es igual k, añadimos la solucion
		if (suma == k) {
			acumulanum++;


	 (6.2) Caso(s) recursivos: si la suma es menor que k seguimos explorando
		if (suma < k) {
			acumulanum += avanza(coleccion, n, k, i + 1, suma);
		}

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
	a partir de la misma, por inmersión.



*/
int avanza(int coleccion[], int n, int k, int i, int suma) {
	int acumulanum = 0;
	for (i; i < n; i++) {
		suma += coleccion[i];
		if (suma < k) {
			acumulanum += avanza(coleccion, n, k, i + 1, suma);
			//suma -= coleccion[i];
		}
		/*if (suma > k) {
			suma -= coleccion[i];
		}*/
		else if (suma == k) {
			acumulanum++;
			//suma -= coleccion[i];
		}
		suma -= coleccion[i]; //"reseteo" la suma si encuentro la solucion correcta o me paso del valor k
	}
	return acumulanum;
}
int modulo(int coleccion[], int n, int k) {
	int cont = 0, suma = 0;

	for (int j = 0; j < n; j++) {//cuento el numero de soluciones para cada numero de la coleccion
		suma = coleccion[j];
		if (suma == k) {
			cont++;
		}
		else {
			cont += avanza(coleccion, n, k, j + 1, suma);//j+1 para no volver a repetir soluciones ya encontradas, recorro la posicion desde j+1 hasta el final, por lo que cada vez es mas pequeña
		}
	}

	return cont;
}



void lee_datos(int& n, int coleccion[], int& k) {
	cin >> n;
	if (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> coleccion[i];
		}
		cin >> k;
	}
}

bool ejecuta_caso() {
	int coleccion[MAXN];
	int n;
	int k;
	/*coleccion[0] = 2;
	coleccion[1] = 2;
	coleccion[2] = 2;
	coleccion[3] = 3;
	coleccion[4] = 1;*/
	lee_datos(n, coleccion, k);
	if (n != 0) {
		cout << modulo(coleccion, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}