#include <iostream>

using namespace std;

//28-11-2019 Problema de la mochila

void mochila(
	//Informacion sobre el problema
	float peso[],
	float beneficio[],
	int n,
	float capacidad,

	//Solucion Parcial
	bool productos[],
	int k, //indica el numero de productos que te has planteado meter o no en la mochila

	//Marcaje
	float pesoAcu, 
	float beneficioAcu,

	//Poda
	float maxBeneficioPendiente,

	//Mejor solucion
	float &maximoBeneficio,
	bool mejorSolucion[]
	
	) {
	//Caso base
	if (k == n) {
		if (beneficioAcu > maximoBeneficio) {
			for (int i = 0; i < n; ++i) {
				mejorSolucion[i] = productos[i];
			}
		}
		return;
	}
	//Caso recursivo

	//Opcion 1: no cogemos el producto
	productos[k] = false;
	if (maximoBeneficio < maxBeneficioPendiente - beneficio[k] + beneficioAcu) { //Podemos seguir mejorando?
		mochila(peso, beneficio, n, capacidad, productos, k + 1, pesoAcu, beneficioAcu, maxBeneficioPendiente - beneficio[k], maximoBeneficio, mejorSolucion);
	}

	//Opcion 2: cogemos el producto
	if (pesoAcu + peso[k] <= capacidad) {
		productos[k] = true;
		mochila(peso, beneficio, n, capacidad, productos, k + 1, pesoAcu + peso[k], beneficioAcu + beneficio[k], maxBeneficioPendiente - beneficio[k], maximoBeneficio, mejorSolucion);
	}
}




int main() {


	return 0;
}