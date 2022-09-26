#include <iostream>

using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos




/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
 P = { 0 < n < tamaño(a) }

*/
bool es_gaspariforme(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
  sumaParcial(a,n) = SUMA i : 0 <= i < n y sumaParcial(a,i) > 0 :  a[i] 
  gaspariforme(a,n) = sumaParcial(a,n) == 0



  (2) Postcondici�n
  Q{ res = gaspariforme(a,n) }

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables
 tenemos la variable sum , que nos permite almacenar la suma recorrida del vector, pudiendo asi comprobar si la sumaParcial es positiva
 la variable i es el contador que utilizamos para recorrer el vector

 PASO 2. Invariante
 el segmento que ya hemos explorado cumplira la condicion de sumaParcial 
 I = res = gaspariforme(a,i) y 0 < i <= n
  
 PASO 3. Inicializaci�n:
 basta hacer sum = 0 y i = 0;


 PASO 4: Continuaci�n y finalizaci�n
 Continuaremos mientras no lleguemos al final del vector (i!=n-1),
 y mientras la condicionn de que la sumaParcial sea positiva (sum <= 0) 
 Si se falsifica res, que en nuestro caso es el return entonces el termino res =  gaspariforme(a,i), asegura que gaspariforme(a,i) es falso,
 por lo que gaspariforme(a,n) es falso;
 si se falsifica i!=n-1, ocurriria que i = n-1. En este caso, el termino res = gaspariforme(a,i)
 asegura directamente que se cumple la postcondicion



 PASO 5: Cuerpo del bucle.
 Caso 1: sum <= 0 :hemos descubierto que el vector deja de ser gaspariforme.
 por tanto podemos hacer return false;
 Caso 2: sum > 0: esto nos obliga a re-establecer res = gaspariforme(a,i),
 lo que puede hacerse incrementado i (i++)




PASO 6: Terminaci�n
 en cada iteracion incrementamos i. Por tanto, podemos tomar como expresion de cota n-i;


*/



bool es_gaspariforme(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int sum = 0, i = 0;

	while (i < n - 1) {
		sum += a[i];

		if (sum <= 0) {
			return false;
		}
		i++;
	}
	return ((sum += a[i]) == 0);
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo
t(n) tiene la forma k0 + k1 n:
k0 es una constante que representa el coste de la inicializacion/terminacion
k1 es una constante que representa el coste del cuerpo del bucle.
el bucle realiza n iteraciones
t(n) es de coste O(n) lineal



*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n > 0) {
			if (es_gaspariforme(a, n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n != 0);
}