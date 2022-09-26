/*
GRUPO: 4
COMPONENTES DEL GRUPO: JESUS MARTIN MORALEDA / JORGE AREVALO ECHEVARRIA

*/


#include <iostream>


using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
	 P = {n' = n}


*/
bool es_sobrado(int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
	dig_creciente(n,u) = PARA_TODO i: 0 < i < u - 1 : n[i] > n[i+1]

  (2) Postcondici�n
	Q = {resul = dig_creciente(n', tam(n')}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo

 PASO 1. Variables
	n y resul(iremos quitando digitos a n, por ello definimos n' en la precondicion para el valor original de n)


 PASO 2. Invariante
	resul = dig_creciente(n',recorrido(n',n)
		Determinamos recorrido(n',n):
			Si n es igual a 0, es que no nos quedan mas digitos por comprobar, y resul debera ser igual a dig_creciente(n', tam(n'))
			Si n es distnto de 0, es que nos quedan digitos por comprobar, y en resul se debera haber comprobado que los digitos sean crecientes del tramo ya explorado: 
			resul = dig_creciente(n', tam(n') - tam(n))
			Con todo esto definimos recorrido(n',n) = (n = 0)?tam(n'):tam(n') - tam(n)

	En n quedara el tramo por recorrer(n debe ser un prefijo de n')
		prefijo_de(n',n) = PARA_TODO i: 0 <= i < tam(n) : n[i] = n'[i]

	Y tam(n') - tam(n) >= 0

	Con todo esto el invariante que resulta es:
	(resul = dig_creciente(n', recorrido(n',n)) ^ prefijo_de(n',n) ^ tam(n') - tam(n) >= 0)

 PASO 3. Inicializaci�n:
	acum = -1, next = 0;


 PASO 4: Continuaci�n y finalizaci�n:
	n > 9, ya que cuando n sea menor o igual que 9, comprobamos que ese digito sea mayor que todos los anteriores yel termino resul = dig_creciente(n', recorrido(n',n))
	permite obtener la postcondicion resul = dig_creciente(n',tam(n'))

 PASO 5: Cuerpo del bucle
	Si el digito actual(next) es mayor estricto que el anterior, actualizamos acum con el digito actual y para seguir avanzando quitamos el ultimo digito a n(n = n /10)
	En otro caso, salimos del bucle ya que no se cumple la condicion de que los digitos sean crecientes.

PASO 6: Terminaci�n
	Basta tomar como cota |n| (el valor absoluto de n), ya que, en cada iteración, a n se le quita un dígito (por lo que dicho valor absoluto decrece).

*/


bool es_sobrado(int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	 CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int acum = -1;
	int next = 0;
	while (n > 9) {
		next = n % 10;
		if (next > acum) {
			acum = next;
			n /= 10;
		}
		else return false;
	}
	return n > acum;

}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo

Elegimos n como tamaño del problema, y suponemos que n es una potencia de 10, n = 10^d, con d igual al numero de digitos. O lo que es lo mismo, d = log10(n). Por tanto el orden de 
complejidad sera logaritmico: O(log(n))


*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */


int main() {
	int n_casos;
	cin >> n_casos;
	while (n_casos > 0) {
		int n;
		cin >> n;
		if (es_sobrado(n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		n_casos--;
	}
	return 0;
}