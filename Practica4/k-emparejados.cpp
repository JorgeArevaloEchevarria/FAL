//Grupo 4 :Jorge Arevalo Echevarria y Jesus Martin Moraleda
#include <algorithm>
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.
  P={0<n<tamaño(v) y esCreciente(v)}
  esCreciente(v):PARATODO i :0 <= i < n-1 :v[i] < v[i+1]

*/
unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k);
/*
POSTCONDICION DE LA FUNCION:
  ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
  ---al valor devuelto por la funci�n, utiliza la pseudo-variable
  ---'resul'

  (1) Definiciones auxiliares (si procede):
  kEsCerpo(k,n) = k==0:n
  empareja(v,n,k) = # i, j: 0 <= i < j < n: |v[i]-v[j]| == k


  (2) Postcondici�n
  Q = {resul = empareja(v,n,k) o KEsCero(k,n)}

 */

 /* DISE�O DEL ALGORITMO:
 --- Detalla aqu� el proceso seguido para dise�ar el
 --- algoritmo


PASO 1. Variables
	count : la usamos para sumar los numeros que son k-esimos
	i : variable que recorre el vector y nos comprueba si los numeros son k-esimos
	j : variable auxiliar que recorre el vector a partir de la posicion de i 

PASO 2. Invariante
	resul podra ser el resultado de empareja o KEsCero dependiendo del valor de k
	 el segmento que ya hemos explorado cumplira la condicion de los numeros k-esimos
	I = (0<=i<j<=n) y (resul = empareja(v,n,k) o KEsCero(k,n))

PASO 3. Inicializaci�n:
	Inicializamos la variable suma count = 0 y las varibales que recorren el vector i = 0 y j = 1,
	y ademas comprobamos si k==0 para saber si todos los numeros son k-esimos
	


PASO 4: Continuaci�n y finalizaci�n:
	Si (i<n-1 && j<n), el termino resul = empareja(v,n,k) del invariante nos asegura que se cumpla la postcondicion
	
	

PASO 5: Cuerpo del bucle
	 Como sabemos por la precondicion que el vector es creciente comprobamos si :
		 - (abs(v[i] - v[j]) > k para incrementar i, ya que sabemos que necesitamos un numero que tengo menor diferencia (ya que el vector es creciente)
		 - (abs(v[i] - v[j]) < k para incrementar j, ya que sabemos que necesitamos un numero mas grande que tenga menor diferencia con la posicion que estamos comparando
		 - (abs(v[i] - v[j]) == k) incrementamos i y j ya que hemos encontrado una posicion k-esima y exploramos la siguiente


PASO 6: Terminaci�n
	 en cada iteracion incrementamos i. Por tanto, podemos tomar como expresion de cota n-i;
*/


unsigned int num_k_emparejados(int v[], unsigned int n, unsigned int k) {
	unsigned int count = 0;
	unsigned int j = 1;
	unsigned int i = 0;

	if (k == 0) return n;//si k es igual a 0 todos los numeros estan emparejados consigomismo

	while (i < n-1 && j < n) {
		if (abs(v[i] - v[j]) == k) {//si es igual a k
			count++;
			i++;
			j++;
		}
		else if(abs(v[i] - v[j]) > k){//si es mayor que k
			i++;	
		}
		else {//si es menor que k
				j++;
		}
			
	}
	return count;
}


/*
Complejidad: Determina justificadamente el orden de complejidad
de este algoritmo:

	 Supongamos que k == 0 en este caso, se ejecuta en tiempo constante.
	 En cambio si k != 0 entonces el bucle principal se ejecuta n veces. Con ello, la complejidad es (n). 
*/



bool procesa_caso() {
	int v[100];
	int n, k;
	cin >> n;
	if (n != -1) {
		cin >> k;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		cout << num_k_emparejados(v, n, k) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}