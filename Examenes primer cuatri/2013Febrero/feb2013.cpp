#include <iostream>

using namespace std;

//EJERCICIO 1: EL ITERATIVO

bool oki(int n, int v[]){

	bool ok=true;
	bool unosAcabados=false;
	int i=0;
	

	while(i<n && ok){
		if(!unosAcabados){
			if(v[i]==1){
				ok=true;
				i++;
			}
			else
				unosAcabados=true;
		}
		else{
			if(v[i]==0){
				ok=true;
				i++;
			}
			else
				ok=false;
		}
	}

	return ok;
}

int main(){

	bool ok;
	int v[7];
	v[0]=1;
	v[1]=1;
	v[2]=1;

	v[3]=0;
	v[4]=0;
	v[5]=0;
	v[6]=0;
	

	ok=oki(7,v);
	if(ok)
		cout<<"yesssss";
	else
		cout <<"nooooooo";

	return 0;
}

//EJERCICIO 2: EL RECURSIVO

void histograma(int p, int u, int v[],int w[],int total){	

	if(u==p)
		w[p]=v[u];
	else{
		w[p]=total;
		p++;
		histograma(p,u,v,w,total+v[p]);
	}
}

void histo(int n, int v[], int w[]){
	histograma(0,n,v,w,v[0]);
}

int main(){
	int v[5];
	int w[5];

	v[0]=1;
	v[1]=2;
	v[2]=4;
	v[3]=3;
	v[4]=-2;

	for(int i=0; i<5; i++)
		w[i]=0;

	histo(4,v,w);

	for(int i=0; i<5;i++)
		cout << w[i]<< " ";

	return 0;
}