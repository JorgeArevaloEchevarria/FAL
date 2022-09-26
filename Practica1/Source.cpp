#include <iostream>

/*

N� GRUPO:4

NOMBRE Y APELLIDOS DE LOS MIEMBROS: Jorge Arevalo Ecehavrria y Jesus Martin Moraleda


OBSERVACIONES:


*/



using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos




/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  P={ 0<=n <=tamaño(a) }
*/
int pares_menos_impares(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'
  Q={(resul = PARATODO i :0<=i<n y a[i] % 2 == 0: resul + a[i]) y (resul = PARATODO i :0<=i<n y a[i] % 2 != 0: resul - a[i])} 
	
 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el algoritmo

 PASO 1: Variables
	a,n,i,resul


 PASO 2: Invariante
	I=(1) y (2)
	(1)= (0 <= i <= n)
	(2)= (resul = PARATODO j :0<=j<i y a[j] % 2 == 0: resul + a[j]) y (resul = PARATODO j :0<=j<i y a[j] % 2 != 0: resul - a[j])

 PASO 3: Inicio
	resul = 0;
	i = 0



 PASO 4: Continuaci�n y finalizaci�n
	condicion de continuacion : i < n
	 si false (i=n) en este caso : (resul = PARATODO j :0<=j<i y a[j] % 2 == 0: resul + a[j]) y (resul = PARATODO j :0<=j<i y a[j] % 2 != 0: resul - a[j])
	 y sales : resul = PARATODO j :0<=j<n y a[j] % 2 == 0: resul + a[j]) y (resul = PARATODO j :0<=j<n y a[j] % 2 != 0: resul - a[j])


 PASO 5: Bloque del bucle

	si (a[i] % 2 == 0)
			sumas a[i] a resul;
	si no
			restas a[i] a resul;

	luego incremento i++ para que se cumpla el invariante al iterar

 PASO 6: Terminaci�n.
	se asegura la terminacion al incrementar la variable i en cada iteracion del bucle, llegando a la condicion i=n , que saldra del bucle



 */



int pares_menos_impares(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int resul = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0)
			resul += a[i];
		else
			resul -= a[i];
	}

	return resul;

}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo
	la complejidad de nuestro algoritmo es lineal (O(n)), ya que nos aseguramos que recorremos el vector una vez, posicion a posicion n veces



 */


 /* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

bool ejecuta_caso() {
	int a[TMAX];
	int n;
	lee_vector(a, n);
	if (n >= 0) {
		cout << pares_menos_impares(a, n) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int n;
	while (ejecuta_caso());
}