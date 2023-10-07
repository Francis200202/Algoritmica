//detRecursivo

#include <cassert>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t
#include <algorithm>
#include <fstream>
#include "sistemaEcuaciones.hpp"
#include "ClaseTiempo.hpp"

using namespace std;

void determinanteRecursivo(){
	Clock time;

	int nMin= 2;
	int nMax= 10;
	int inc= 1;
	int k= 0;
	double tiempo=0;
	double det=0;
	double coefDet;
	double seg;
	double min;
	double dias;
	double years;
	
	vector<vector<double>> M;
	vector<vector<double>> inv;
	vector<double>tiemposReales;
	vector<double>n;
	vector<double>a;
	vector<double>tiemposEstimados;

	cout<<"nMin= ";
	cin>>nMin;
	cout<<"nMax= ";
	cin>>nMax;
	cout<<"inc= ";
	cin>>inc;
	

	for(int i=nMin;i<=nMax;i=i+inc){
		
		M= vector<vector<double>>(i, vector<double>(i));
		rellenarMatriz(M);
		time.start();
		det=algrecursivo(M, i);
	
		if (time.isStarted()){
				time.stop();
		}
		cout<<"detM["<<i<<"]["<<i<<"]= "<<det<<endl;
		
		tiempo= time.elapsed() + tiempo;
		tiemposReales.push_back(tiempo);
		n.push_back(i);
	}
	
	fichero(tiemposReales, n);

	ajusteFactorial(n, tiemposReales, a);

	calcularTiemposEstimadosFactorial(n, tiemposReales, a, tiemposEstimados);



	coefDet=calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
	
	datosFinales(n, tiemposReales, tiemposEstimados);

	cout<<"Ecuacion curva ajustada= "<<a[0]<<"+"<<a[1]<<"*n!"<<endl;
	cout<<"Coeficiente de determinacion= "<<coefDet<<endl;

	do{
		cout<<"Estimacion de tiempos(Si->Introduce un tamaño/No->tamaño=0"<<endl;
		cin>>k;
		if(k!=0){
			tiempo= calcularTiempoEstimadosFactorial(k, a);
			seg= tiempo/1000000;
			min= seg/60;
			dias= min/(24*60);
			years= dias/365;
			cout<<"Tiempo estimado= "<<years<<" años, "<<dias<<" dias, "<<min<<" min, "<<seg<<" seg"<<endl;	
		}
	}while(k!=0);
}

double algrecursivo(vector<vector<double>> &M, int b){
	double det=0;
	if(b==1){
		return M[0][0];
	}else if(b>1){
		for(int k=1;k<b;k++){
			det= pow(-1, 1+k)*M[0][k]*algrecursivo(M, k);
		}
	}
	return det;
}

void ajusteFactorial(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a){
	vector<vector<double>> A;
	vector<vector<double>> B;
	vector<vector<double>> X;
	vector<double> z;
	double factorial=1;

	A= vector<vector<double>>(2, vector <double>(2));
	B= vector<vector<double>>(2, vector <double>(1));
	X= vector<vector<double>>(2, vector <double>(1));

	for(size_t i=0; i<n.size(); i++){
		for(int j=n[i];j>0;j--){
			factorial=factorial*j;
		}
		z.push_back(factorial);
	}

	A[0][0]= n.size();
	A[0][1]= sumatorio(z, tiemposReales, 1, 0);
	A[1][0]= A[0][1];
	A[1][1]= sumatorio(z, tiemposReales, 2, 0);
	cout<<"A= "<<A[0][0]<<", "<<A[0][1]<<", "<<A[1][0]<<", "<<A[1][1]<<endl;

	B[0][0]= sumatorio(z, tiemposReales, 0, 1);
	B[1][0]= sumatorio(z, tiemposReales, 1, 1);

	cout<<"B= "<<B[0][0]<<", "<<B[1][0]<<endl;

	resolverSistemaEcuaciones(A, B, 2, X);

	for(int i=0; i<2; i++){
		a.push_back(X[i][0]);
	}

}

void calcularTiemposEstimadosFactorial(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a, vector<double> &tiemposEstimados){
	double factorial=1;
	for(size_t i=0; i<n.size(); i++){
		for(int j=n[i];j>0;j--){
			factorial=factorial*j;
		}
		tiemposEstimados.push_back(a[0]+a[1]*factorial);
	}
}

double calcularTiempoEstimadosFactorial(const double &n, vector<double> &a){
	double factorial=1;
	for(int j=n;j>0;j--){
			factorial=factorial*j;
	}
	return a[0]+a[1]*factorial;

}
