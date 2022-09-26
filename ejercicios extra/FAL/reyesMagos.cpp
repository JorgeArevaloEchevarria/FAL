/*

NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS AUTORES:


*/


#include <iostream>

using namespace std;

const int MAXN = 10;


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

typedef struct {

	int satisfaccion[MAXN];
	int edad;
	int numToys;

}tPeque;




void reyes (int sol[],int nToys, int edadToys[], tPeque pequeños[], int nPeques, int minToys,int kToys, int kPeque, bool marcas[], int &maxSatis, int &satisAct){
	/* A IMPLEMENTAR */
	
	
		
	if (pequeños[kPeque].edad > edadToys[kToys] && !marcas[kToys])
		if (pequeños[kPeque].numToys <= minToys) {
			if (kPeque == nPeques)


			if (pequeños[kPeque].numToys == minToys) {
			if (satis > maxSatis)
				maxSatis = satis;
		}
		else {
			satis += pequeños[kPeque].satisfaccion[kToys];
			pequeños[kPeque].numToys++;
			marcas[kToys] = true;
			if (pequeños[kPeque].numToys == minToys)
				kPeque++;
			reyes(nToys, edadToys, pequeños, nPeques, minToys, kToys++, kPeque, marcas, maxSatis, satis);
			marcas[kToys] = false;
			satis -= pequeños[kPeque].satisfaccion[kToys];
		}

	
}



void lee_datos(int& nToys, int edadToys[],tPeque pequeños[],int &nPeques, int &minToys ) {
	cin >> nToys;
	cin >> nPeques;
	cin >> minToys;
	
	if (nToys != 0) {
		for (int i = 0; i < nToys; i++) 
			cin >> edadToys[i];
		
		for (int i = 0; i < nPeques; i++) {
			cin >> pequeños[i].edad;
			pequeños[i].numToys = 0;
		}
		for (int i = 0; i < nPeques; i++) 
			for (int j = 0; j < nToys; j++) 
				cin >> pequeños[i].satisfaccion[j];
		
	}
}

bool ejecuta_caso() {
	int edadToys[MAXN];
	tPeque pequeños[MAXN];
	bool marcas[MAXN];
	int nToys,nPeques,minToys,satis,maxSatis;
	int kPeque = 0, kToys = 0;

	lee_datos(nToys,edadToys,pequeños, nPeques,minToys);
	if (nToys != 0) {
		reyes(nToys, edadToys, pequeños, nPeques, minToys, kToys++, kPeque, marcas, maxSatis, satis);
		cout <<maxSatis  << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}
