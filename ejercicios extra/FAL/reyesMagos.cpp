/*

NUMERO DE GRUPO:

NOMBRE Y APELLIDOS DE LOS AUTORES:


*/


#include <iostream>

using namespace std;

const int MAXN = 10;


/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
	sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
	parciales viables?

(6) An�lisis de casos

	 (6.1) Caso(s) base


	 (6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
	a partir de la misma, por inmersi�n.



*/

typedef struct {

	int satisfaccion[MAXN];
	int edad;
	int numToys;

}tPeque;




void reyes (int sol[],int nToys, int edadToys[], tPeque peque�os[], int nPeques, int minToys,int kToys, int kPeque, bool marcas[], int &maxSatis, int &satisAct){
	/* A IMPLEMENTAR */
	
	
		
	if (peque�os[kPeque].edad > edadToys[kToys] && !marcas[kToys])
		if (peque�os[kPeque].numToys <= minToys) {
			if (kPeque == nPeques)


			if (peque�os[kPeque].numToys == minToys) {
			if (satis > maxSatis)
				maxSatis = satis;
		}
		else {
			satis += peque�os[kPeque].satisfaccion[kToys];
			peque�os[kPeque].numToys++;
			marcas[kToys] = true;
			if (peque�os[kPeque].numToys == minToys)
				kPeque++;
			reyes(nToys, edadToys, peque�os, nPeques, minToys, kToys++, kPeque, marcas, maxSatis, satis);
			marcas[kToys] = false;
			satis -= peque�os[kPeque].satisfaccion[kToys];
		}

	
}



void lee_datos(int& nToys, int edadToys[],tPeque peque�os[],int &nPeques, int &minToys ) {
	cin >> nToys;
	cin >> nPeques;
	cin >> minToys;
	
	if (nToys != 0) {
		for (int i = 0; i < nToys; i++) 
			cin >> edadToys[i];
		
		for (int i = 0; i < nPeques; i++) {
			cin >> peque�os[i].edad;
			peque�os[i].numToys = 0;
		}
		for (int i = 0; i < nPeques; i++) 
			for (int j = 0; j < nToys; j++) 
				cin >> peque�os[i].satisfaccion[j];
		
	}
}

bool ejecuta_caso() {
	int edadToys[MAXN];
	tPeque peque�os[MAXN];
	bool marcas[MAXN];
	int nToys,nPeques,minToys,satis,maxSatis;
	int kPeque = 0, kToys = 0;

	lee_datos(nToys,edadToys,peque�os, nPeques,minToys);
	if (nToys != 0) {
		reyes(nToys, edadToys, peque�os, nPeques, minToys, kToys++, kPeque, marcas, maxSatis, satis);
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
