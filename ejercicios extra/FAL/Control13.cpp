/*

NUMERO DE GRUPO:04

NOMBRRE Y APELLIDOS DE LOS AUTORES: Jorge Arevalo Ecehvarria y Jesus Martin Moraleda


*/

#include <iostream>
using namespace std;

typedef unsigned long long t_num;

/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.
  P = { n = 'n y alpha > 0 }

*/
bool es_limpio(unsigned short d, unsigned short alpha, t_num n);


/*
POSTCONDICION DE LA FUNCION:
---Escribe aqu� la poscondici�n de la funci�n. Para refirte
---al valor devuelto por la funci�n, utiliza la pseudo-variable
---'resul'

(1) Definiciones auxiliares (si procede):

es_limpio(d,alpha,n,u) = #i,j:0<=i<=j<u y consecutivos(n,i,j) : n[i] = d  // predicado auxilar que nos devuelve el numero de numeros consecutivos
																		//iguales a al numero d
consecutivos(n,i,j): PARATODO w : i<w<=j:n[i]=n[w] // predicado auxialar uqe nos dice si los numeros son consecutivos e iguales

(2) Postcondici�n
resul = (es_limpio(d,alpha,n',tam(n')=) < alpha);

*/

/* DISE�O DEL ALGORITMO:
--- Detalla aqu� el proceso seguido para dise�ar el algoritmo

PASO 1: Variables
d, alpha, n, resto, cont (iremos quitando digitos a n, por ello definimos n' en la precondicion para el valor original de n)

PASO 2: Invariante
	resul = (es_limpio(d,alpha,n',recorrido(n',n)) < alpha)
		Determinamos recorrido(n',n):
			Si n es igual a 0, es que no nos quedan mas digitos por comprobar, y resul debera ser igual a es_limpio(d,alpha,n',tam(n'))
			Si n es distnto de 0, es que nos quedan digitos por comprobar, y en resul se debera haber comprobado que los digitos sean consecutivos,
			y la suma de los numeros consecutivos del tramo ya explorado debera  ser menor que alpha:
			resul = (es_limpio(d,alpha,n',tam(n')=) < alpha);
			Con todo esto definimos recorrido(n',n) = (n = 0)?tam(n'):tam(n') - tam(n)

	En n quedara el tramo por recorrer(n debe ser un prefijo de n')
		prefijo_de(n',n) = PARA_TODO i: 0 <= i < tam(n) : n[i] = n'[i]

	Y tam(n') - tam(n) >= 0

	Con todo esto el invariante que resulta es:
	(resul = (es_limpio(d,alpha,n',recorrido(n',n)) < alpha) ^ prefijo_de(n',n) ^ tam(n') - tam(n) >= 0)


PASO 3: Inicio
	cont = 0;
	resto = n % 10;


PASO 4: Continuaci�n y finalizaci�n
	nuestra condicion del bucle es n > 0, ya que cuando n sea 0, ya habremos comprobado el ultimo digito del numero (unidad)  y que cumple el termino
	resul = (es_limpio(d,alpha,n',recorrido(n',n)) < alpha) que nos permite obtener la postcondicion resul = (es_limpio(d,alpha,n',tam(n')=) < alpha);


PASO 5: Bloque del bucle
	Si el digito actual(resto) es igual al numero d, actualizamos cont incrementando la variable, y
	en el caso de que sea distinto actualizamos cont = 0 ya que queremos calcular si hay mas numeros7
	consecutivos iguales a d, en el tramo aun no explorado
	despues de actualizar la variable cont, comprobamos si la variable cont es mayor igual que alpha, para asi ya devolver false,
	ya que el numero no cumpliria que fuese alpha-limpio
	para seguir avanzando quitamos el ultimo digito a n(n = n /10)


PASO 6: Terminaci�n.
	Basta tomar como cota |n| (el valor absoluto de n), ya que, en cada iteración, a n se le quita un dígito (por lo que dicho valor absoluto decrece).

*/

bool es_limpio(unsigned short d, unsigned short alpha, t_num n) {
	// IMPLEMENTACION DEL ALGORITMO
	t_num cont = 0;
	t_num resto = n % 10;
	if (alpha == 1 && n < 10 && d == n)//caso base
		return false;
	while (n > 0) {
		resto = n % 10;
		if (resto == d)
			cont++;
		else
			cont = 0;

		if (cont >= alpha)
			return false;

		n = n / 10;
	}
		return (cont<alpha);
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo
Elegimos n como tamaño del problema, y suponemos que n es una potencia de 10, n = 10^d,
con d igual al numero de digitos, o lo que es lo mismo, d = log10(n).
Por tanto el orden de complejidad sera logaritmico: O(log(n))

*/



bool procesa_caso() {
	int d;
	unsigned short alpha;
	t_num n;
	cin >> d;
	if (d != -1) {
		cin >> alpha >> n;
		if (es_limpio((unsigned short)d, alpha, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}