/*

NUMERO DE GRUPO:04

NOMBRRE Y APELLIDOS DE LOS AUTORES: Jorge Arevalo Ecehvarria y Jesus Martin Moraleda


*/

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;


typedef unsigned long long t_num;


/*
(1) En caso de utilizar una generalizacion,
determinación de los parámetros de la generalización.
Determina los parámetros de la generalización. Para cada parámetro
indica: (i) su tipo; (ii) su nombre; (iii) si es un parámetro
de entrada, de salida, o de entrada / salida; (iv) su propósito,
descrito de manera clara y concisa.

- t_num n, par�metro de entrada: El n�mero para el cu�l hay
	que calcular todos los naturales menores que �l, que sean alternados.
  - sumAlternados, par�metro de salida: Cantidad de
	naturales positivos menores que 'n', sin d�gitos repetidos,
	y con exactamente el mismo n�mero de d�gitos que 'n'
  - posicion: posicion por la cual vamos por el vector, y nos indica en
	que diginito nos ubicamos
  - parOimparSeguidos , true si has dos digitos impares o pares seguidos
  - paresSeguidos: nos dice el numero de pares que van seguidos
  - imparesSeguidos: nos dice el numero de impares que van seguidos



(2) Análisis de casos:

(2.1) Casos base
//caso base, en el que el numero solo contiene un digito
	if (n < 10)
		return n;

//caso base en el que estamos en el ultimo digito del numero

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

//caso base en el que el digito es el mas significativo

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

(2.2) Casos recursivos

* n tiene m�s de un d�gito (n > 9)
		  - Resolvemos el problema para n 
			(es decir, para n/10) =>
			contar(numero, posicion, sumAlternados, parOimparSeguidos, paresSeguidos, imparesSeguidos);
		  - Para resolver el problema para n: 
				* se actualiza sumAlternados, con la ayuda del valor aux
					aux = pow(5, posicion) * (numero[posicion] - 1);
				* miramios si hay par o impar seguidos, si no hay:
				* miramos si el digito es par o impar y segun sea actualizamos sumAlternados
				* despues actualizamos pareSeguidos e impareSeguidos

(3) En caso de utilizar una generalizacion, definición por inmersión
del algoritmo. Describe de manera clara y concisa cómo se lleva a
cabo el algoritmo, en qué punto o puntos se invoca a la generalización,
con qué parámetros reales, y cómo se genera el resultado
a partir de los devueltos por la generalización.

* Los casos n<10 se tratan
	 devolviendo directamente el resultado n
   * El resto de los casos se resuelven
	  - invocando a la generalizaci�n como:
	 contar(vector<int> numero,
			int posicion,
			t_num& sumAlternados,
			bool& parOimparSeguidos,
			int& paresSeguidos,
			int& imparesSeguidos)
	  - devolviendo el resultado como
			sumAlternados




*/

void contar(vector<int> numero, int posicion, t_num& sumAlternados, bool& parOimparSeguidos, int& paresSeguidos, int& imparesSeguidos) {

	t_num aux = 0, auxResto = 0;
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
	else {//caso recursivo
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
		numero.push_back(num % 10);//guardamos el dígito actual
		num = num / 10;//eliminamos el dígito mas a la izquierda
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

(1) Determinación de las ecuaciones de recurrencia para la generalización

(2) Resolución utilizando los patrones vistos en clase

(3) Determinación justificada de la complejidad del algoritmo final.


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