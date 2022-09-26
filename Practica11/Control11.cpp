/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/


#include <iostream>

using namespace std;



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

bool esValida(int d, int k, long long i) {//
	int dSig = d+1;
	long long limite = (pow(10, (k - 1)) * (dSig));//ponemos como limite la suiguiente cifra del primer digito,
											//ya que si el primer digito ya nos es "d" , no sera valida
	if (i < limite)// si aun no hemos superado el limite
		return true;
	else
		return false;
}


bool esSolucion(int d, int k, long long i) {
	int sum=0;
	long long aux = i;
	while (aux > 0) {//vamos sacando los digitos del numero
		sum += aux % 10;//vamos sumando cada digito para ver si es sumDivisible
		aux = aux / 10;//sacamos el siguiente digito
	}
	if ((sum % k) == 0)
		return true;
	else
		return false;

}

void sumaSumDiv(int d, int k, int& SolucionSum, long long& i) {
	if (esValida(d, k, i)) {
		if (esSolucion(d, k, i)) {//miramos si es sumDivisible el numero
			long long sinUltimoDig = i / 10;//quitamos el ultimo digito
			int kMenosUltimoDig = k - 1;//quitamos un digito al numero de digitos que compone el numero
			if(esSolucion(d,kMenosUltimoDig,sinUltimoDig))//miramos si es sumDivisible sin el ultimo digito
				SolucionSum++;
		}
		i++;
		sumaSumDiv(d, k, SolucionSum,i);		
	}
}


int num_sumdivisibles(int d, int k) {
	// PUNTO DE ENTRADA AL ALGORITMO: A implementar
	long long empiezaRecorrido = (pow(10, (k - 1)) *d);//Comenzamos con el primer numero con digito D, que tenga k digitos
	int suma = 0;
	sumaSumDiv(d, k, suma, empiezaRecorrido);
	return suma;
}


int main() {
	int d;
	do {
		cin >> d;
		if (d > 0) {
			int k;
			cin >> k;
			cout << num_sumdivisibles(d, k) << endl;
		}
	} while (d > 0);
}

