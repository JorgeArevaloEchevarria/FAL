#include <iostream>

/*

N� GRUPO:

NOMBRE Y APELLIDOS DE LOS MIEMBROS:


OBSERVACIONES:


*/



using namespace std;

const int TMAX = 1000;  // No habr� vectores de m�s de 1000 elementos




/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  0<=n<=tam(a) y 0<=m<=tam(a) y s = SUM i :0<=i<=m:a[i]

*/


int mayorSuma(const int a[], int n, int m, int s); 
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO 
	int sumaMax = s;
	int suma = s;
	for (int i = m; i < n; i++) {
		suma = suma - a[i - m] + a[i];
		if (suma > sumaMax)
			sumaMax = suma;
	}
	return sumaMax;
}*/

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'
  resul = mayorSuma(a,n,m,s)
  mayorSuma(a,n,m,s) = max i :0 <= i < n : sumaConsecutiva(a,n,m,i)
  predicado auxiliar que nos calcula la suma de m elementos consecutivos
  sumaConsecutiva(a,n,m,i): SUM j : (0<=i<j<n) y (j-i==m) :a[i]

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el algoritmo

 PASO 1: Variables
 a,n,m,s,sumaMax,suma


 PASO 2: Invariante
 (1) y (2)
 (1) -> 0<=i<=n
 (2) ->(resul = mayorSuma(a,n,m,s)) y (mayorSuma(a,n,m,s) = max i :0 <= i < n : sumaConsecutiva(a,n,m,i)) y
	(sumaConsecutiva(a,n,m,i): SUM j : (0<=i<j<n) y (j-i==m) :a[i])

 PASO 3: Inicio
	sumaMax = s;
	suma = s;


 PASO 4: Continuaci�n y finalizaci�n
	si i = n el invariante asegura sumaConsecutiva(a,n,m,n) con lo que nos asegura la continuacion y finalizacion


 PASO 5: Bloque del bucle
	-- suma = suma - a[i - m] + a[i]; 
		actualizamos la suma de m elementos consecutivos
	-- if (suma > sumaMax)
		comprobamos si la suma es mayor quye la suma maxima
	-- sumaMax = suma;
		en el caso de que sea mayor, actualizamos la nueva suma maxima



 PASO 6: Terminaci�n.//expresion de cota
	nuestra ecuacuion de cota = n - m - i, y sabemos que y se incrementa en cada iteracion, 
	 con lo que nuestra expresion disminuye  y aseguramos la finalizacion


 */



int mayorSuma(const int a[], int n, int m, int s) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int sumaMax = s;
	int suma=s;
	for (int i = m; i < n; i++) {
		suma = suma - a[i - m] + a[i];
		if (suma > sumaMax)
			sumaMax = suma;
	}
	return sumaMax;
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo
 nuestro algortimo tendra un coste lineal respecto a los elementos del vector O(n),
 ya que realizamos n vueltas, y en cada iteracion realizamos un coste constante



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
	int n,m,s;
	cin >> m;
	cin >> s;
	lee_vector(a, n);
	if (n >= 0) {
		cout <<mayorSuma(a, n,m,s) << endl;
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