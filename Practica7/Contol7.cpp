/*
No Grupo:D35
Nombre y Apellidos de los miembros:
Javier Navarro Vaquero y Jagoba Montes Larrabaster

*/


// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#include <iostream>
#include <vector>

#define DOM_JUDGE

#ifndef DOM_JUDGE
#include <ctime>
#include <stdlib.h>
#endif 

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

	if (posicion < 0) return 0;

(2.2) Casos recursivos

	return resto + contar(numero, numero.size() - 1, pot);

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



*/




/*
t_num numero -> todos los dígitos ordenados con el mas significativo al final. Entrada
int posicion -> la posición del dígito a procesar. Entrada
t_num -> la potencia acumulada. Entrada
*/
t_num contar(vector<int> numero, int posicion, t_num pot) {

	// caso base, se han procesado todos los dígitos
	if (posicion < 0) return 0;

	//cuando se repita el digito mas significativo, no seguir contando
	if (posicion != numero.size() - 1 && numero[posicion] == numero[numero.size() - 1]) return numero[posicion] * pot;

	//si el número a procesar es mayor que el dígito signif. excluirlo del conteo
	if (numero[posicion] > numero[numero.size() - 1]) numero[posicion]--;

	//evaluar el paso actual y pasar al siguiente elemento
	return numero[posicion] * pot + contar(numero, posicion - 1, pot / 9);

}

t_num num_singulares_menoresque(t_num n) {
	vector<int> numero;
	t_num num = n;
	t_num pot = 1;
	t_num resto = 0;
	while (num > 0) {
		numero.push_back(num % 10);//guardamos el dígito actual
		num = num / 10;//eliminamos el dígito mas a la izquierda
		resto += pot;// calculamos el resto del dig mas rep.
		pot *= 9; //calculamos la potencia para el algoritmo
	}
	pot /= 9;
	resto -= pot;
	//llamada al algoritmo mas el resto residual
	return resto + contar(numero, numero.size() - 1, pot);
}
/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(2) Resoluci�n utilizando los patrones vistos en clase

(3) Determinaci�n justificada de la complejidad del algoritmo final.

T(n) = 1	caso base n <0
T(n) = T(n-1) +1	  n>=0
coste O(n)
*/

#ifndef DOM_JUDGE
unsigned short digito_mas_significativo(t_num n) {
	while (n > 9) {
		n = n / 10;
	}
	return (unsigned short)n;
}
bool es_singular(t_num n) {
	unsigned short msd = digito_mas_significativo(n);
	bool loes = true;
	while (n > 9 && loes) {
		loes = (n % 10 != msd);
		n = n / 10;
	}
	return loes;
}

t_num num_singulares_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (es_singular(i)) {
			num++;
		}
	}
	return num;
}
#endif

#ifdef DOM_JUDGE
bool ejecuta_caso() {
	long long n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		cout << num_singulares_menoresque(n) << endl;
		return true;
	}
}
#endif

int main() {

#ifndef DOM_JUDGE
	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_singulares_menoresque_naif(n) != num_singulares_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_singulares_menoresque_naif(n) << "..." << num_singulares_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause");
#endif

#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif
}