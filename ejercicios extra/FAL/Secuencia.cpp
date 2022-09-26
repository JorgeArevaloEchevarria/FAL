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
  0<=n<=tam(a)

*/
void secuencia(const int a[], int n, int& pos, int& lon);

/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'
  resul = secuencia(a,n,pos,lon);
	seceuncia(a,n,pos,lon): para todo i,j :0<=i<j<n y crecienteCons(a,i,j):pos=i y lon = (j-i)
	predicado auxiliar crecienteCons(a,i,j):para todo w:i<=w<j:(a[w+1]-a[w]==1)


 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el algoritmo

 PASO 1: Variables
  sec, posIni


 PASO 2: Invariante

	I = (1) y (2)
	(1)->1<=i<=n
	(2)-> resul = secuencia(a,n,pos,lon,i);
		seceuncia(a,n,pos,lon): para todo i,j :0<=i<j<n y crecienteCons(a,i,j):pos=i y lon = (j-i)
		predicado auxiliar crecienteCons(a,i,j):para todo w:i<=w<j:(a[w+1]-a[w]==1)

 PASO 3: Inicio
	int sec =lon= 1;
	int posIni=pos = 0;
	i=1


 PASO 4: Continuaci�n y finalizaci�n

	si i = n
		- se asegura la finalizacion ya que el invariante asegura  resul = secuencia(a,n,pos,lon,i)
		por lo cual asegura resul = secuencia(a,n,pos,lon,n)


 PASO 5: Bloque del bucle
	-- if (a[i] - a[i - 1] == 1): comprobamos si los numeros consecutivos son crecientes y con numeros seguidos
		-- y despues miramos si estamos al principio de la secuencia para guardarnos la posicion de donde empieza
			if (sec == 1)
				posIni = i - 1;
		-- despues actualizamos la longitud de la secuencia sec++;
		-- y comprobamos si la secuencia actual es mas grande que la secuencia maxima
			if (sec > lon)
				-- en ese guardamos los valores de la nueva secuencia maxima
					pos = posIni;
					lon = sec;

	-- sino , se habra acabado la secuencia y vamos en busca de una nueva secuencia
		sec = 1;



 PASO 6: Terminaci�n.(cota)
	nuestra exprosion de cota es n-i, con cada iteacion i se incrementa, por lo que n disminuye asegurando la terminacion


 */



void secuencia(const int a[], int n, int &pos, int &lon) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int sec =lon= 1;
	int posIni=pos = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] == 1) {
			if (sec == 1)
				posIni = i - 1;
			sec++;
			if (sec > lon) {
				pos = posIni;
				lon = sec;
			}
		}
		else
			sec = 1;
	}
}

/*
COMPLEJIDAD: Determina razonadamente la
complejidad del algoritmo
con la expresion de cota vemos que no se pueden dar mas de n vueltas.
como el cuerpo del bucle se ejecuta en tiempo constante nos asegura un coste lineal respecto a los elemntos del vector O(n)



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
	int n,lon,pos;
	lee_vector(a, n);
	if (n >= 0) {
		secuencia(a, n, pos, lon);
		cout <<pos<<" "<<lon << endl;
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