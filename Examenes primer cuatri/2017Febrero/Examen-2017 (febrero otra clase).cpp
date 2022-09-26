#include <math.h>

//Ejercicio 1

//bool esCreciente(int v[], int l){
//	
//	bool ok=true;
//	int i=0;
//
//	while (ok && i<l-1){
//		
//		if(abs(v[i+1] - v[i])> 1)
//			ok=false;
//
//		i++;	
//
//	return ok;
//	}
//}
//
//int esDivertido (int v[], int l, int a){
//	int contador=0;
//
//	for(int i=0; i<l; i++)
//		if(v[i] == a)
//			contador++;
//
//	return contador;
//}
//
//bool Ejer1( int v[], int l, int d){
//
//	bool ok=true;
//	bool esCreciente =false;
//	int i=0;
//
//	
//	if(esCreciente(v,l))
//		esCreciente=true;
//
//	while (i<l){
//		if(esCreciente && esDivertido (v,l,v[i]) > d)
//			ok=false;
//		i++;
//	}
//	return ok;
//}
//
//I= 0<=l<n ^ esCreciente(v,l) ^ esDivertido(v,l,v[i]) <= d; //Esto se tiene que cumplir antes, durante y despues del bucle

//Ejercicio 2

//bool creciente(int v[], int l, int pos){
//	return crecienteAux(v,1000,0);
//}
//
//
//
//bool crecienteAux (int v[], int l, int pos){
//
//	if(pos == l-2) //Si e vector tiene dos elementos
//		return abs(v[pos+1] - v[pos]) <=1;
//
//	else{ 
//		if(abs(v[pos+1] - v[pos]) <=1 && v[pos+1]>v[pos]) //Si es creciente, lo miramos con el siguiente
//			return crecienteAux(v,l,pos+1);
//	}
//}
	
//Ejercicio 3

//bool esValida(int sol[], int n, int k, int d){
//	bool valida=false;
//
//	if(abs(sol[k] - sol[k-1]) <=1 && sol[k] >= sol[k-1] && (esDivertido(sol,k,sol[k]) <= d)) //Sera valido si es creciente y divertido
//		valida=true;
//
//	return valida;
//}
//
//int esDivertido(int sol[], int k, int a){
//	int contador=0;
//
//	for(int i=0; i<=k; i++)
//		if(sol[i] == a)
//			contador++;
//
//	return contador;
//}
//
//bool esSolucion(int k, int n){
//	return k == n-1;
//}
//
//void escribeCrecientePorLosPelosDivertidos(int n, int d, int e, int k, int sol[]){
//
//	sol[0] =e; 
//
//	for(int i=0; i<n; i++){
//		sol[k] = i;
//		if(esValida(sol,n,k,d)){
//			if(esSolucion(k,n))
//				escribeSol(sol,k);
//			else
//				escribeCrecientePorLosPelosDivertidos(n,d,e,k+1,sol);
//		}
//	}
//}

//la llamada en el main se haria:

//escribeCrecientePorLosPelosDivertidos(1000,d,e,1,sol);