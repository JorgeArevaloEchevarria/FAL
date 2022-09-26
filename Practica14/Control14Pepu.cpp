/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;


typedef unsigned long long t_num;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



*/

void contar(vector<int> numero, int posicion, t_num& sumAlternados, bool& parOimparSeguidos, int& paresSeguidos, int& imparesSeguidos) {

	int aux = 0, auxResto = 0;
	//miramos si estamos en el digito menos significativo
	if (posicion == 0) {
		sumAlternados += 10;//caso base, sumamos los numeros del 0 al 9
		if (!parOimparSeguidos) {
			if (numero[posicion + 1] % 2 == 0) {//miramos si la posicion anterior es par, y si es par no contamos las posiciones con 0
				auxResto = numero[posicion] / 2;
				sumAlternados += auxResto;
			
			}else {// y si es impar contamos las posiciones con 0
				auxResto = (numero[posicion] + 1) / 2;
				sumAlternados += auxResto;
			}
		}
	}
	else if (posicion == numero.size() - 1) {//si la posicion es el digito mas significativo
		aux = pow(5, posicion) * (numero[posicion] - 1);
		sumAlternados += aux;
		if (numero[posicion] % 2 == 0) {
			paresSeguidos++;
			imparesSeguidos = 0;
		}
		else {
			imparesSeguidos++;
			paresSeguidos = 0;
		}
		posicion--;
		contar(numero, posicion, sumAlternados, parOimparSeguidos, paresSeguidos, imparesSeguidos);
	}
	else {
		//aqui contaria por ejemplo si el numero es 5678 pues hasta 5000
		aux = pow(5, posicion) * 9;
		sumAlternados += aux;
		//y aqui sumaria el resto que queda entre 5000 y 5600

		if (!parOimparSeguidos) {
			if (numero[posicion + 1] % 2 == 0) {//miramos si la posicion anterior es par, y si es par no contamos las posiciones con 0
				auxResto = pow(5, posicion) * (numero[posicion] / 2);
				sumAlternados += auxResto;
			}
			else {// y si es impar contamos las posiciones con 0
				auxResto = pow(5, posicion) * ((numero[posicion] + 1) / 2);
				sumAlternados += auxResto;
			}
		}
		if (numero[posicion] % 2 == 0) {
			paresSeguidos++;
			imparesSeguidos = 0;
		}
		else {
			imparesSeguidos++;
			paresSeguidos = 0;
		}
		if (paresSeguidos >= 2 || imparesSeguidos >= 2)
			parOimparSeguidos = true;

		posicion--;
		// y en la siguiente vuelta pasariamos a la decena y sumarimos lo q quedase de resto es decir de 5600 a 5670 y asi recursivamente
		contar(numero, posicion, sumAlternados, parOimparSeguidos, paresSeguidos, imparesSeguidos);
	}

}

t_num num_alternados(t_num n) {
	// PUNTO ENTRADA AL ALGORITMO7
	vector<int> numero;
	t_num num = n;
	t_num sumAlternativos=0;
	int parSeguidos = 0;
	int imparSeguidos = 0;
	bool parOimparSeguidos = false;
	while (num > 0) {
		numero.push_back(num % 10);//guardamos el d�gito actual
		num = num / 10;//eliminamos el d�gito mas a la izquierda
	}
	if (n < 10)
		return n;
	else {
		contar(numero, numero.size() - 1, sumAlternativos,parOimparSeguidos,parSeguidos,imparSeguidos);
		return sumAlternativos;
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(2) Resoluci�n utilizando los patrones vistos en clase

(3) Determinaci�n justificada de la complejidad del algoritmo final.


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