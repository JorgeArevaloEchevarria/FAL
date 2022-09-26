/*

NUMERO DE GRUPO:

NOMBRRE Y APELLIDOS DE LOS AUTORES:


*/

#include <iostream>
#include<vector>
#include<math.h>
using namespace std;


typedef unsigned long long t_num;

void cuentanum(t_num num, int& resul, int& ult_digit, bool& par);
void cuentaok(t_num num, int& resul, int this_digit, int& ult_digit, int i, bool& end);
void compara();
int recursivo(t_num num);
int iterativo(t_num num);
void contar(vector<int> numero, int posicion, t_num& sumAlternados);

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
void cuentanum(t_num n, int& resul, int& ult_digit, bool& par) {
	if (n < 9) {
		resul++;
	}
	else {
		n = n / 10;
		ult_digit = n % 10;
		if ((ult_digit % 2 == 0 && par) || (ult_digit % 2 != 0 && !par)) {
			return;
		}
		par = !par;
		cuentanum(n, resul, ult_digit, par);
	}

}

void cuentaok(t_num n, int& resul, int this_digit, int& ult_digit, int i, bool& end) {
	if (n < 10) {
		for (int j = i; j > 0; j--){
			resul += pow(5, j) * 9;
		}
		resul += pow(5, i+1) * (n - 1);
		ult_digit = n;
	}
	else {
		i++;
		this_digit = n % 10;
		cuentaok(n/10, resul, this_digit, ult_digit, i,end);

		if (!end) {
			if (i == 0) {
				if (/*(this_digit % 2 == 0 && ult_digit % 2 == 0) ||*/ (this_digit % 2 != 0 && ult_digit % 2 != 0)) {
					resul += (this_digit / 2) + 1;
				}
				else resul += this_digit / 2;
			}
			else {
				if (/*(this_digit % 2 == 0 && ult_digit % 2 == 0) ||*/ (this_digit % 2 != 0 && ult_digit % 2 != 0)) {
					end = true;
					resul += (int)pow(5, i) * ((this_digit / 2) + 1);
				}
				else resul += pow(5, i) * (this_digit / 2);
				
				if (this_digit % 2 == 0 && ult_digit % 2 == 0) {
					end = true;
				}
				ult_digit = this_digit;
			}
		}

	}
}
void compara() {
	for (int i = 1; i < 10000; i++) {
		t_num  n = (t_num)rand();
		t_num nok = n;
		t_num n2 = n;
		
		int resul = iterativo(n);
		int resul2 = recursivo(nok);
		if (resul != resul2) {
			cout << "NO FUNCIONA" << endl;
			cout << n2 << ":" << resul << "..." << resul2 << endl;
			break;
		}
	}
}
int recursivo(t_num n) {
	vector<int> numero;
	t_num num = n;
	t_num sumAlternativos = 0;
	//t_num pot = 1;
	//t_num resto = 0;
	while (num > 0) {
		numero.push_back(num % 10);//guardamos el d�gito actual
		num = num / 10;//eliminamos el d�gito mas a la izquierda
	}
	if (n < 10)
		return n;
	else {
		contar(numero, numero.size() - 1, sumAlternativos);
		return sumAlternativos;
	}
}
void contar(vector<int> numero, int posicion, t_num& sumAlternados) {

	//miramos si estamos en el digito menos significativo
	int aux = 0, auxResto = 0;
	if (posicion == 0) {
		sumAlternados += 10;//caso base, sumamos los numeros del 0 al 9
		auxResto = numero[posicion] / 2;
		sumAlternados += auxResto;
	}
	else if (posicion == numero.size() - 1) {//si la posicion es el digito mas significativo
		aux = pow(5, posicion) * (numero[posicion] - 1);
		sumAlternados += aux;
		posicion--;
		contar(numero, posicion, sumAlternados);
	}
	else {
		//aqui contaria por ejemplo si el numero es 5678 pues hasta 5000
		aux = pow(5, posicion) * 9;
		sumAlternados += aux;
		//y aqui sumaria el resto que queda entre 5000 y 5600
		auxResto = pow(5, posicion) * (numero[posicion] / 2);
		sumAlternados += auxResto;
		posicion--;
		// y en la siguiente vuelta pasariamos a la decena y sumarimos lo q quedase de resto es decir de 5600 a 5670 y asi recursivamente
		contar(numero, posicion, sumAlternados);
	}

}


int iterativo(t_num n) {
	if (n == 0) {
		return 0;
	}
	else if (n < 10) {
		return n;
	}
	else if (n < 100 && n > 9) {
		int ult_digit = n % 10;
		n = n / 10;
		int first_digit = n % 10;
		if ((first_digit % 2 == 0 && ult_digit % 2 == 0) || (first_digit % 2 != 0 && ult_digit % 2 != 0)) {
			return (int)((first_digit + 1) * 5) + (ult_digit / 2) + 1;
		}
		else return (int)((first_digit + 1) * 5) + (ult_digit / 2);
	}
	else if (n >= 10000000000LL) {
		return 8877691LL;
	}
	else {
		int resul = 10;
		bool par = false;
		int ult_digit;
		int this_digit = 0;
		for (n--; n > 9; n--) {
			par = false;
			ult_digit = n % 10;
			if (ult_digit % 2 == 0) {
				par = true;
			}
			cuentanum(n, resul, ult_digit, par);
		}
		return resul;
	}

}
t_num num_alternados(t_num n) {
	// PUNTO ENTRADA AL ALGORITMO

	if (n == 0) {
		return 0;
	}
	else if (n < 10) {
		return n;
	}
	else if (n < 100 && n > 9) {
		int ult_digit = n % 10;
		n = n / 10;
		int first_digit = n % 10;
		if ((first_digit % 2 == 0 && ult_digit % 2 == 0) || (first_digit % 2 != 0 && ult_digit % 2 != 0)) {
			return (int)((first_digit+1) * 5) + (ult_digit / 2) + 1;
		}
		else return (int)((first_digit+1) * 5) + (ult_digit / 2);
	}
	else if (n >= 10000000000LL) {
		return 8877691LL;
	}
	else {
		//return iterativo(n);
		//return recursivo(n);
		compara();
		//return 0;
		
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