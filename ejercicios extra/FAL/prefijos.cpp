/*
N? GRUPO:
AUTORES DE LA PRACTICA (Nombres y Apellidos):

*/

#include <iostream>

using namespace std;

const unsigned int MAX_LON = 1000;

/*
  PASO 1. Describe el o los casos base y justifica
		  resultados asociados.


  PASO 2. Describe el o los casos recursivos, y justifica
		  los resultados asociados.


*/
int exp_prefija(char a[], int n, int i) {
	/* A IMPLEMENTAR */
	if (i == n)
		return n;
	else if (a[i] == '+') {
		i++;
		return exp_prefija(a, n, i);
	}
	else if (a[i] == '-') {
		i++;
		return exp_prefija(a, n, i);
	}
	else if (a[i] == '*') {
		i++;
		return exp_prefija(a, n, i);
	}
	else if (a[i] == '/') {
		i++;
		return exp_prefija(a, n, i);
	}
	else if (a[i] >= 48 && a[i] <= 57) {//digito
		i++;
		return exp_prefija(a, n, i);
	}
	
	else if (i == 0)
		return -1;
	else
		return i;



}

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == 0) {
		return false;
	}
	else {
		char a[MAX_LON];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << exp_prefija(a, n, 0) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());

}