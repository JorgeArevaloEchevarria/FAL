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
	(3 Añadido en la correcion del profesor, para continuacion y finalizacion) no_empareja(v,k,i,j) = PARATODO u,w :i<=u<=w<j : |v[u] -v[w]|<k 

PASO 3. Inicializaci�n:
	Inicializamos la variable suma count = 0 y las varibales que recorren el vector i = 0 y j = 1,
	y ademas comprobamos si k==0 para saber si todos los numeros son k-esimos
	


PASO 4: Continuaci�n y finalizaci�n:
	Si (i<n-1 && j<n), el termino resul = empareja(v,n,k) del invariante nos asegura que se cumpla la postcondicion
	-tambien asegura que no_empareja(v,k,i,j)
	-Por tanto asegura que resul = empareja(v,n,k,j
	-Pero como j=n, entonces res= empareja(v,n,k,n)
	
	

PASO 5: Cuerpo del bucle
	//* son correcciones del profesor
	 Como sabemos por la precondicion que el vector es creciente y como (0<=i<j<=n) y ademas (i<n-1 && j<n), por tanto podemos asegurar que 0<=i<n y 0<=j<n. por tanto v[i] y v[j] tienen sentido :
		 - (abs(v[i] - v[j]) > k para incrementar i, ya que sabemos que necesitamos un numero que tengo menor diferencia (ya que el vector es creciente)
			*0<=i<=j<=n . pero como 0<=i<=j y j<n el termino se preserva al incrrementar i
			*res = empareja(v,n,k,i). Pero como se cumplia : (1) no_empareja(v,k,i,j)
		 - (abs(v[i] - v[j]) < k para incrementar j, ya que sabemos que necesitamos un numero mas grande que tenga menor diferencia con la posicion que estamos comparando
			*esto afecta a (0<=i<=j<=n), pero como 0<=j<n antes del incremento, despues de incrementar j el termio sigue siendo valido;
			*no_empareja(v,k,i,j), pero como |v[i]-v[j]|<k y como v es estrictamente creciente, entonces el termino se preserva
		 - (abs(v[i] - v[j]) == k) incrementamos i y j ya que hemos encontrado una posicion k-esima y exploramos la siguiente
			* -incrementamos res al haber encontrado una nueva k-pareja
			*pero esto afecta a res=empareja(v,n,k,i), como el vector es creciente y como |v[i]-v[j]|=k no habra w>j, tal que |v[i]-v[w]|=k, por tanto para restablecer el termino hasta incrementar i.Pero esto afecta a :
				** a no_empareja(v,k,i,j), pero como antes de incrementar i, se cummple para v[i.....j], podemos asegurar que se cumplia tambien para v[i...j]. Por tanto tras incrementar i el termino sigue siendo valido
				** a (0<=i<=j<=n) si antes de incremento i=j , el termino se viola, para  evitarlo en este caso debemos incrementar j ( mas cosas, no tiempo para copiar)
					***........
					***........


PASO 6: Terminaci�n
	 en cada iteracion incrementamos i. Por tanto, podemos tomar como expresion de cota n-i;
	 2n - (i+j) es una expresion de cota
	 * como en cada iteracion se incrementa i o j, la expresion disminuye
	 *ademas podemos comprobar qque 2n -(i+j) >= 0 es un invariante del bucle:
		-al inicializar i=j=0,2n-(i+j) = 2n>=0
		-Supongamos que 2n -(i+j)>=0 se cumple al entrar en el cuerpo del bucle ,como i<n y j<n,
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

	 con la expresion de cota hemos visto que el bucle no da mas de 2n vueltas. como el cuerpo se ejecuta
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