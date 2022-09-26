#include<iostream>

using namespace std;


const int MAX = 100;





bool hayVeto(bool vetos[MAX][MAX], bool sol[], int k) {
	bool hayveto = false;
	int i = 0;
	while (!hayveto && i < k) {
		hayveto = ((vetos[i][k] || vetos[k][i]) && sol[i]);
		i++;
	}
	return hayveto;
}
void resuelve(int n, int m, int beneficio[], bool vetos[MAX][MAX], int &resul,int &resul_max, bool sol[], bool solOpt[], int cont, int i) {
	sol[i] = true;
	resul += beneficio[i];
	cont++;

	if (cont <= n && !hayVeto(vetos, sol, i)) {
		if (i == m) {
			if (n == cont) {
				if (resul > resul_max) {
					resul_max = resul;
					solOpt = sol;
				}
			}
		}
		else {
			resuelve(n, m, beneficio, vetos, resul, resul_max, sol, solOpt, cont, i + 1);
		}
	}
	sol[i] = false;
	resul -= beneficio[i];
	cont--;
	if (i == m) {
		if (n == cont) {
			if (resul > resul_max) {
				resul_max = resul;
				solOpt = sol;
			}
		}
	}
	else {
		resuelve(n, m, beneficio, vetos, resul, resul_max, sol, solOpt, cont, i + 1);
	}
}
int festival(int n, int m, int beneficio[], bool vetos[MAX][MAX]) {
	int resul = 0,resul_max = 0,cont = 0,i= 0;
	bool sol[MAX] = { false };
	bool solOpt[MAX] = { false };
	resuelve(n, m, beneficio, vetos, resul, resul_max,sol, solOpt,cont,i);

	return resul_max;
}
int main() {

	int n, m;
	bool vetos[MAX][MAX];
	int beneficio[MAX];

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> beneficio[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> vetos[i][j];
		}
	}
	cout << festival(n, m, beneficio, vetos) << endl;


	return 0;
}
/*
3 6
2 -1 0 4 3 -5
0 1 0 0 0 0
0 0 0 0 1 0
0 0 0 0 0 1
0 0 1 0 0 0
0 0 0 1 0 0 
1 0 0 1 0 0
*/