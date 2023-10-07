//qsort

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

void ordenacionQuickSort(){
	Clock time;

	int nMin= 1000;
	int nMax= 5000;
	int inc= 50;
	int repeat= 10;
	int n=0;
	double tiempo=0;
	double coefDet;
	double seg;
	double min;
	double dias;
	double years;
	
	vector<double>tiemposReales;
	vector<double>numeroElementos;
	vector<double>a;
	vector<double>tiemposEstimados;

	cout<<"nMin= ";
	cin>>nMin;
	cout<<"nMax= ";
	cin>>nMax;
	cout<<"inc= ";
	cin>>inc;
	cout<<"repeat= ";
	cin>>repeat;

	for(int i=nMin;i<=nMax;i=i+inc){
		for(int j=0; j<repeat; j++){
			vector<int>v(i);
			rellenarVector(v);
			time.start();
			sort(v.begin(),v.end());
			if (time.isStarted()){
				time.stop();
			}
			if(estaOrdenado(v)==false){
				cout<<"Error, no se ha realizado la ordenacion"<<endl;
			}else{
				//cout<<"Esta ordenado"<<endl;
			}
			tiempo= time.elapsed() + tiempo;
		}
		tiempo= tiempo/repeat;
		//cout<<"Tiempo medio= "<<tiempo<<endl;
		tiemposReales.push_back(tiempo);
		numeroElementos.push_back(i);
	}
	fichero(tiemposReales, numeroElementos);
	
	ajusteNlogN(numeroElementos, tiemposReales, a);

	calcularTiemposEstimadoNlogN(numeroElementos, a, tiemposEstimados);

	coefDet= calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);

	datosFinales(numeroElementos, tiemposReales, tiemposEstimados);

	cout<<"Ecuacion curva ajustada= "<<a[0]<<"+"<<a[1]<<"*n*log10(n)"<<endl;
	cout<<"Coeficiente de determinacion= "<<coefDet<<endl;
	do{
		cout<<"Estimacion de tiempos(Si->Introduce un tamaño/No->tamaño=0"<<endl;
		cin>>n;
		if(n!=0){
			tiempo= calcularTiempoEstimadoNlogN(n, a);
			seg= tiempo/1000000;
			min= seg/60;
			dias= min/(24*60);
			years= dias/365;
			cout<<"Tiempo estimado= "<<years<<" años, "<<dias<<" dias, "<<min<<" min, "<<seg<<" seg"<<endl;	
		}
	}while(n!=0);
}

void rellenarVector(vector<int>&v){
	srand(time(NULL));
	for(size_t i=0; i<v.size(); i++){
		v[i]=rand()%10000000;
	}
	return;
}

bool estaOrdenado(const vector<int>&v){
	for(size_t i=0; i<v.size(); i++){
		if(v[i]<v[i-1]){
			return false;
		}
	}
	return true;
}

void fichero(vector<double>&tiemposReales, vector<double>&numeroElementos){
	string t, n, escribir;
	ofstream f("tiemposReales.txt");
	for(size_t i=0; i<tiemposReales.size(); i++){
		t= to_string(tiemposReales[i]);
		n= to_string(numeroElementos[i]);
		escribir=t+" "+n+"\n";
		f.write(escribir.data(), escribir.size());
	}
}

void datosFinales(const vector<double> &numeroElementos, const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){
	string t, n, e, escribir;
	ofstream f("datosFinales.txt");
	for(size_t i=0; i<tiemposReales.size(); i++){
		n= to_string(numeroElementos[i]);
		t= to_string(tiemposReales[i]);
		e= to_string(tiemposEstimados[i]);
		escribir=n+" "+t+" "+e+"\n";
		f.write(escribir.data(), escribir.size());
	}
}

void calcularTiemposEstimadoNlogN(const vector<double> &numeroElementos,const vector<double> &a, vector<double> &tiemposEstimados){
	for(size_t i=0; i<numeroElementos.size(); i++){
		tiemposEstimados.push_back(a[0]+a[1]*numeroElementos[i]*log10(numeroElementos[i]));
	}
}

double calcularTiempoEstimadoNlogN(const double &n, vector<double> &a){
	return a[0]+a[1]*n*log10(n);

}

void ajusteNlogN(const vector<double> &numeroElementos, vector<double> &tiemposReales, vector<double> &a){
	vector<vector<double>> A;
	vector<vector<double>> B;
	vector<vector<double>> X;
	vector<double> z;
	int n= 2;
	A= vector<vector<double>>(n, vector <double>(n));
	B= vector<vector<double>>(n, vector <double>(1));
	X= vector<vector<double>>(n, vector <double>(1));

	for(size_t i=0; i<numeroElementos.size(); i++){
		z.push_back(numeroElementos[i]*log10(numeroElementos[i]));
	}
	
	A[0][0]= numeroElementos.size();
	A[0][1]= sumatorio(z, tiemposReales, 1, 0);
	A[1][0]= A[0][1];
	A[1][1]= sumatorio(z, tiemposReales, 2, 0);
	cout<<"A= "<<A[0][0]<<", "<<A[0][1]<<", "<<A[1][0]<<", "<<A[1][1]<<endl;

	B[0][0]= sumatorio(z, tiemposReales, 0, 1);
	B[1][0]= sumatorio(z, tiemposReales, 1, 1);

	cout<<"B= "<<B[0][0]<<", "<<B[1][0]<<endl;

	resolverSistemaEcuaciones(A, B, n, X);

	for(int i=0; i<n; i++){
		a.push_back(X[i][0]);
	}
	
}

double sumatorio(vector<double> &n, vector<double> &t, int expN, int expT){
	double sumN=0, sumT=0, sumNT=0;
	for(size_t i=0; i<n.size(); i++){
		sumN= pow(n[i], expN)+sumN;
		sumT= pow(t[i], expT)+sumT;
		sumNT= pow(n[i], expN)*pow(t[i], expT)+sumNT;
	}
	if(expN!=0 && expT!=0){
		return sumNT;
	}else if(expN!=0){
		return sumN;
	}else{
		return sumT;
	}
}

double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados){
	double mediaR=0, mediaE=0, varianzaR=0, varianzaE=0;
	for(size_t i=0; i<tiemposReales.size(); i++){
		mediaR= tiemposReales[i]+mediaR;
		mediaE= tiemposEstimados[i]+mediaE;
	}
	mediaR= mediaR/tiemposReales.size();
	mediaE= mediaE/tiemposReales.size();

	for(size_t i=0; i<tiemposReales.size(); i++){
		varianzaR= pow(tiemposReales[i]-mediaR, 2)+varianzaR;
		varianzaE= pow(tiemposEstimados[i]-mediaE, 2)+varianzaE;
	}
	varianzaR= varianzaR/tiemposReales.size();
	varianzaE= varianzaE/tiemposReales.size();

	return varianzaE/varianzaR;
}
