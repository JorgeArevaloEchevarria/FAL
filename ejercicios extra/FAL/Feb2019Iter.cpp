#include <algorithm>
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  P ={2<=L<=n y -1000<=v<=1000}

*/
/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
  series(v,n,l) = # i :0<=i<j<=n y contiguio(v,i,j,n,resul) : resul>l 

  contiguo(v,i,j,n,resul) :resul = # w :i<w<=j<n y abs(v[w] - v[w-1])<=1: 

  (2) Postcondici�n

  {resul = series(v,n,l)}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo


PASO 1. Variables
	int long_segmento -> variable que nos dice la longitud que llebamos del segmento
	int num_segmentos -> variable que nos dice el numero de segmentos >= L que llebamos recorridos
	int v[] -> vector que nos guarda la entrada
	int n -> longitud del vector



PASO 2. Invariante
I = (1) y (2)
(1) = 1<=i<=n
(2) =  {(resul = series(v,n,l)) 
		donde (series(v,n,l) = # i :0<=i<j<=n y contiguio(v,i,j,n,resul) : resul>l)
		donde (contiguo(v,i,j,n,resul) :resul = # w :i<w<=j<n y abs(v[w] - v[w-1])<=1 )}



PASO 3. Inicializaci�n:
	int long_segmento = 1;
	int num_segmentos = 0;
	int i =0;


PASO 4: Continuaci�n y finalizaci�n:
	si i<n-1 -> el termino resul = series(v,n,l) del invariante, asegura que se cumpla la postcondicion
	


PASO 5: Cuerpo del bucle
	->if (abs(v[i] - v[i - 1]) <= 1) primero comprobamos si se cumple que la diferencia entre elementos es menor o igual a 1,
		y si se cumple añadimos este elemento (long_segmento++)
	->sino, si la diferencia es mayor de 1 el segmento se habra acabado y tendremos que saber si dicho segmento cumple la condicion del problema :
		- if (long_segmento >= l): miramos si nuestro segmento actual sea mayor a L, si se cumple incrementamos num_segmentos

		y despues actualizamos la long_segmento a 1 ya que volveremos a explorar el vector.




PASO 6: Terminaci�n
	nuestra espresion de cota es n-i ,ya que i la incrementamos en cada iteracion nos aseguramos la terminacion.

*/


unsigned int series(int v[], unsigned int n, unsigned int l) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int long_segmento = 1;
	int num_segmentos = 0;
	for (int i = 1; i < n; i++) {
		if (abs(v[i] - v[i - 1]) <= 1)
			long_segmento++;
		else {
			if (long_segmento >= l)
				num_segmentos++;
			long_segmento = 1;
		}
	}
	if (long_segmento >= l)
		num_segmentos++;

	return num_segmentos;
}

/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo:
como en cada vuelta tenemos un coste constante, y con nuestra expresion de cota nos aseguramos e¡de un coste lineal O(n) segun el numero de elemntos del vector

*/





int main(int argc, char* args[])
{
	int N, L;
	int V[100];
	for (cin >> N >> L; N || L; cin >> N >> L)
	{
		for (int n = 0; n < N; n++) cin >> V[n];
		cout << series(V, N, L) << endl;
	}
	return 0;
}

/*
10 3
5 5 3 4 3 4 7 8 9 3
2
5 2
5 4 4 5 6
1
6 3
4 6 8 2 5 9
0
6 6
3 4 3 2 5 4
0
0 0
*/