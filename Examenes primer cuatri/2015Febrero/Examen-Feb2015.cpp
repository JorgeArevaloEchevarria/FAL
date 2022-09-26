#include <iostream>
using namespace std;


//Ejercicio 2: imagen especular, un array invertido recursivamente



void especularAux(int v[], int n, int p, int u){ //Ejercicio hecho en O(n)

	int aux=0;

	if(p==u)
		 v[p]=v[u];
	else{

		aux=v[p];
		v[p] = v[u];
		v[u]=aux;

		return especularAux(v,n,p+1,u-1);
	}
}

void especular(int v[], int n){

	return especularAux(v,n,0,n-1);
}


int main(){
	int v[5];

	for(int i =0; i<5; i++)
		cin >> v[i];

	especular(v,5);
	
	for(int i =0; i<5; i++)
		cout << v[i];

return 0;
}

//Ejercicio 3 : backTracking

bool esValida(int sol[], int n, int contador, int p[], int prot[],  int k , int m , int q, int pAct, int protAct){
	bool valida=true;

		if(contador > n)
			valida=false;

		if(pAct >m)
			valida=false;
		if(protAct> q)
			valida=false;

	return valida;
}

bool esSolucion(int k , int n){
	return k==n;
}

void alimentos(int sol[], int k, int n, int precioAct, int proteinasAct, int caloriasAct, int solOpt[], int caloriasMin, int m, int q, int c[] int p[], int prot[]){

		sol[k] = true;
		caloriasAct +=c[sol[k]];
		precioAct += p[sol[k]];
		proteinasAct += prot[sol[k]];

		if(esValida(sol,n,contador,k,m,q,precioAct,proteinasAct)){
			//poda---> if(caloriasMin<caloriasAct + (n-k)*minimoCalorias) minimoCalorias es el alimeno con el minimo de calorias
			if(esSolucion(k,n)){
				if(caloriasAct<caloriasMin){
					caloriasMin=caloriasAct;
					copiarSolucion(solOpt,sol);
				}
			}
			else{
				alimentos(contador,sol,k+1,n,precioAct,proteinasAct,caloriasAct,solOpt,caloriasMin,m,q,marcas,p,prot);
			}
		}

		sol[k]=false;
		precioAct -= p[sol[k]];
		proteinasAct -= prot[sol[k]];
		caloriasAct -=c[sol[k]];
	

		if(esValida(sol,n,contador,precioAct,proteinasAct,k,m,q,marcas)){
					if(esSolucion(k,n)){
						if(caloriasAct<caloriasMin){
							caloriasMin=caloriasAct;
							copiarSolucion(solOpt,sol);
						}
					}
					else{
						alimentos(sol,k+1,n,precioAct,proteinasAct,caloriasAct,solOpt,caloriasMin,m,q,marcas,p,prot);
					}
				}


}

//Ejercicio 1 : iterativo

//int sumarMultiplicaciones(int v[], int n){
//	int i =0;
//	int resultado=0;
//	int contador=i+1;
//	int cuantosNum=n;
//
//	while(contador<n && cuantosNum>0){
//
//		resultado += v[n-cuantosNum]*v[contador];
//		contador++; //para que se haga todos hasta que ya lleve los n
//
//		if(contador==n){
//			cuantosNum--; 
//			i++; //Porque numero va
//			contador=i+1; 
//		}
//	}
//return resultado;
//}
//
//int main(){
//	int v[4];
//	v[0]= 1;
//	v[1] = 3;
//	v[2] = 5; 
//	v[3]= 7;
//	
//	cout<< sumarMultiplicaciones(v,4);
//	
//
//return 0;
//
//
//}