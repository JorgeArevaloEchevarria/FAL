/*
No Grupo:grupo 4
Nombre y Apellidos de los miembros: Jorge Arevalo Ecehvarria y Jesus Martin Moraleda

*/


// Si se comenta esta definici�n, el programa
// autocomprobar� su funcionamiento comparando
// la implementaci�n realizada con una 
// implementaci�n 'naif' del algoritmo
#define DOM_JUDGE

#include <iostream>
/* 
#ifndef DOM_JUDGE 
#include <ctime>
#include <stdlib.h>
#include <climits>
#endif
*/

using namespace std;

typedef unsigned long long t_num;

/*
(1) Determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro 
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa. 

  - t_num n, par�metro de entrada: El n�mero para el cu�l hay
    que calcular todos los naturales menores que �l, que no 
	tengan d�gitos repetidos.
  - num_menos_num_digs, par�metro de salida: Cantidad de 
    naturales postivos sin d�gitos repetidos, y que tienen
	menos d�gitos que 'n'
  - num_mismo_num_digs, par�metro de salida: Cantidad de
    naturales positivos menores que 'n', sin d�gitos repetidos,
	y con exactamente el mismo n�mero de d�gitos que 'n'

	.... *** a�ade y explica el resto de par�metros que
	.... *** consideres oportuno


(2) An�lisis de casos para la generalizaci�n:

(2.1) Casos base


(2.2) Casos recursivos

(3) Definici�n por inmersi�n del algoritmo. Describe
de manera clara y concisa c�mo se lleva a cabo el algoritmo,
en qu� punto o puntos se invoca a la generalizaci�n, 
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n. 



*/


int sacarB1(int num, int d) {
	if (d != 1) {
		int exp1 = pow(10, d - 1);
		int exp2 = pow(10, d - 2);
		int dig1 = num / exp1;
		int dig2 = num -(dig1*10);// hay q sacar la unidad
		if (dig1 > dig2)
			return dig2;//ya que se repetira un numero
		else
			return dig2-1;//ya que no se repite el numero
	}
	else
		return 0;

}

void cuenta_sinrepetidos_menoresque(t_num n,
 	                                t_num& num_menos_num_digs,//A
	                                t_num& num_mismo_num_digs,//B
	                                           // A�ade los par�metros adicionales que consideres oportuno
									//parametros auxiliares para A
									int k,//k-digitos
									int d,//digitos de n
									//parametros auxiliares para B
									int b1

	                                ) {
	// A implementar
	if (k < d) {
		//A
		t_num numerosA_esimos = num_menos_num_digs * (10 - k);
		k++;
		//B
	//	t_num b0 = num_mismo_num_digs * (10 - k) + B1 ;
		cuenta_sinrepetidos_menoresque(n, num_menos_num_digs, num_mismo_num_digs, k, d,b1);
		num_menos_num_digs += numerosA_esimos;
	}
	//B implementar
	//caso base de B
	else if (d == 1) {
		num_mismo_num_digs = n - 2;
	}
	else {
		t_num b0 = num_mismo_num_digs * (10 - k) + b1;
		num_mismo_num_digs += b0;
	
	
	}
}

t_num num_sinrepetidos_menoresque(t_num n) {
	// A implementar, como una inmersi�n de
	// 'cuenta_sin_repetidos_menoresque 
	if (n == 0)
		return 0;
	else if (n > 10000000000LL)
		return 8877691LL;
	else {
		t_num a = 1;// Ck+1 = Ck * (10 – k)
		//donde A = C1 + C2 + … + CD-1, con D el número de dígitos de n. 
		t_num b = 1;//Si n es un único dígito, B = n-1
		t_num num = n;
		int k = 1;
		int d = 1;
		int b1;

		while (num / 10 > 0) {
			num = num / 10;
			d++;
		}

		b1 = sacarB1(n, d);
		cuenta_sinrepetidos_menoresque(n, a, b, k, d, b1);
		return (a + b + 1);
	}
}

/*
Determina justificadamente la complejidad del algoritmo

(1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(2) Resoluci�n utilizando los patrones vistos en clase

(3) Determinaci�n justificada de la complejidad del algoritmo final.


*/



// No modificar el c�digo que sigue

#ifndef DOM_JUDGE

bool digs_reps(t_num n) {
	bool digs[10];
	for (unsigned short d = 0; d < 10; d++) {
		digs[d] = false;
	}
	while (n > 0 && !digs[n % 10]) {
		digs[n % 10] = true;
		n /= 10;
	}
	return n != 0;
}

t_num num_sinrepetidos_menoresque_naif(t_num n) {
	t_num num = 0;
	for (t_num i = 0; i < n; i++) {
		if (!digs_reps(i)) num++;
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
		cout << num_sinrepetidos_menoresque(n) << endl;
		return true;
	}
}
#endif


int main() { 
#ifdef DOM_JUDGE
	while (ejecuta_caso());
#endif

#ifndef DOM_JUDGE

	srand(time(NULL));
	for (int i = 1; i < 1000; i++) {
		t_num  n = (t_num)rand();
		if (num_sinrepetidos_menoresque_naif(n) != num_sinrepetidos_menoresque(n)) {
			cout << "NO FUNCIONA" << endl;
			cout << n << ":" << num_sinrepetidos_menoresque_naif(n) << "..." << num_sinrepetidos_menoresque(n) << endl;
			break;
		}
	}
	cout << "OK" << endl;
	system("pause"); 
#endif

}