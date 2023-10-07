#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include "funciones.hpp"
#include "ClaseTiempo.hpp"

using namespace std;
int x=0;

void opcion1(){
	vector<int> reinas;
	vector<vector<int>> sol;
	int n;
	cout<<"\nCantidad de reinas:"<<endl;
	cin>>n;
	reinas.resize(n);
	x=0;
	backtracking(n, reinas, sol, 0);
	cout<<"--Soluciones backtracking--"<<endl;
	for(int i=0; i<x;i++){
		cout<<"["<<i+1<<"]: ";
		for(int j=0; j<n; j++){
			cout<<sol[i][j]<<"| ";
		}
		cout<<endl;
	}
	cout<<"->"<<x<<" soluciones"<<endl;	
}

void opcion2(){
	Clock time;
	int n;
	int t;
	vector<int> reinas;
	vector<vector<int>> sol;
	cout<<"\nCantidad de reinas:"<<endl;
	cin>>n;
	reinas.resize(n);
	x=0;
	time.start();
	backtracking(n, reinas, sol, 1);
	if (time.isStarted()){
		time.stop();
	}
	t= time.elapsed();
	cout<<"--Primera solucion backtracking--"<<endl;
	cout<<"[1]: ";
	for(int i=0; i<n; i++){
		cout<<sol[0][i]<<"| ";
	}
	cout<<endl;
	cout<<"->"<<t<<" microsegundos en encontrar una solucion"<<endl;	
}

void opcion3(){
	Clock time;
	bool exito=false;
	int n;
	int t;
	int inten=0;
	vector<int> reinas;
	vector<vector<int>> sol;
	cout<<"\nCantidad de reinas:"<<endl;
	cin>>n;
	reinas.resize(n);
	x=0;
	time.start();
	do{
		inten++;
		exito=vegas(n, reinas);	
	}while(exito==false);
	if (time.isStarted()){
		time.stop();
	}
	t= time.elapsed();
	if(exito==true){
		cout<<"--Solucion Vegas--"<<endl;
		for(int i=0; i<n; i++){
			cout<<reinas[i]<<"| ";
		}
		cout<<endl;
	}
	cout<<"->"<<inten<<" numeros de intentos para encontrar dicha solucion"<<endl;
	cout<<"->"<<t<<" microsegundos en encontrar una solucion"<<endl;
}

void backtracking(int n, vector<int> &reinas, vector<vector<int>> &sol, int op){
	reinas[0]=-1;
	int k=0;
	while(k>=0){
		reinas[k] = reinas[k]+1;
		while(reinas[k]<n && lugar(k, reinas)==false){
			reinas[k] = reinas[k]+1;
		}
		if(reinas[k]<n){
			if(k==n-1){
				x++;
				sol.push_back(reinas);
				if(op==1){
					return;
				}
			}else{
				k++;
				reinas[k]=-1;
			}
		}else{
			k--;
		}
	}
}

bool vegas(int n, vector<int> &reinas){
	bool exito;
	int cont;
	int columna;
	vector<int> ok;
	for(int i=0; i<n; i++){
		reinas.push_back(-1);
	}
	ok.resize(n);
	for(int k=0; k<n; k++){
		cont=0;
		for(int j=0; j<n; j++){
			reinas[k]=j;
			if(lugar(k, reinas)==true){
				cont++;
				ok[cont-1]=j;
			}
		}
		if(cont==0){
			return false;
		}
		srand(time(NULL));
		columna=ok[rand() % cont];
		reinas[k]=columna;
	}
	if(cont==0){
		exito=false;
	}else{
		exito=true;
	}
	return exito;
}

bool lugar(int k, vector<int> &reinas){
	for(int i=0; i<k; i++){
		if(reinas[i]==reinas[k] || abs(i-k)==abs(reinas[i]-reinas[k])){
			return false;
		}
	}
	//comprobar si la reina puede atacar a las reinas de su izquierda con el movimiento del caballo
	if(k>0){
		if(reinas[k]>1 && reinas[k]==(reinas[k-1]+2)){
			return false;
		}
		if(reinas[k]<reinas.size()-2 && reinas[k]==(reinas[k-1]-2)){
			return false;
		}
	}
	if(k>1){
		if(reinas[k]>0 && reinas[k]==(reinas[k-2]+1)){
			return false;
		}
		if(reinas[k]<reinas.size()-1 && reinas[k]==(reinas[k-2]-1)){
			return false;
		}
	}
	return true;
}

