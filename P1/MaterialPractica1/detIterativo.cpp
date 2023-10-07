//detIterativo

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

void determinanteIterativo(){
	Clock time;

	int nMin= 100;
	int nMax= 200;
	int inc= 10;
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
		det=triangulo(M);
	
		if (time.isStarted()){
				time.stop();
		}
		cout<<"detM["<<i<<"]["<<i<<"]= "<<det<<endl;
		
		tiempo= time.elapsed() + tiempo;
		tiemposReales.push_back(tiempo);
		n.push_back(i);
	}
	
	fichero(tiemposReales, n);

	ajustePolinomico(n, tiemposReales, a);

	calcularTiemposEstimadosPolinomico(n, tiemposReales, a, tiemposEstimados);

	coefDet=calcularCoeficienteDeterminacion(tiemposReales, tiemposEstimados);
	
	datosFinales(n, tiemposReales, tiemposEstimados);

	cout<<"Ecuacion curva ajustada= "<<a[0]<<"+"<<a[1]<<"*n+"<<a[2]<<"*n^2+"<<a[3]<<"*n^3"<<endl;
	cout<<"Coeficiente de determinacion= "<<coefDet<<endl;

	do{
		cout<<"Estimacion de tiempos(Si->Introduce un tamaño/No->tamaño=0"<<endl;
		cin>>k;
		if(k!=0){
			tiempo= calcularTiempoEstimadosPolinomico(k, a);
			seg= tiempo/1000000;
			min= seg/60;
			dias= min/(24*60);
			years= dias/365;
			cout<<"Tiempo estimado= "<<years<<" años, "<<dias<<" dias, "<<min<<" min, "<<seg<<" seg"<<endl;	
		}
	}while(k!=0);
}

void rellenarMatriz(vector<vector<double>> &M){
	srand(time(NULL));
	for(unsigned int i = 0; i < M.size(); i++){
		for(unsigned int j = 0; j < M.size(); j++){
			M[i][j]=(rand()%1000);
			M[i][j]=M[i][j]/10000+0.95;
			
   		}
	}
}

double triangulo(vector<vector<double>> M){
	bool correcto;
	for(unsigned int i = 0; i < M.size() - 1; i++)
	{
		if (fabs(M[i][i])< 0.0000000001) //Se ha encontrado un 0 en la diagonal principal, hay que eliminarlo
		{
			correcto = elimCero(M, i);
			if (correcto == false)
			{
				exit(0);
			}
		}
		hacerCerosColum(M, i);
	}
	return productoDiag(M);
}

bool elimCero(vector<vector<double>> M, unsigned int x){
	unsigned int i;
	bool correcto = false;
	bool salir = false;

	i = x+1;
	while(salir == false)
	{
		if (i == M.size())
			salir = true;
		else if (fabs(M[i][x]) > 0.0000000001) //Comprueba que no es 0
		{
			salir = true;
			correcto = true;
		}
		else
			i = i + 1;
	}
	if (correcto == true)
	{
		combFilas(M, i, 1.0, x);
	}
	return correcto;
}

void hacerCerosColum(vector<vector<double>> M, unsigned int x){
	double aux;

	for(unsigned int i = x+1; i < M.size(); i++)
	{
		aux = -M[i][x]/M[x][x];
		combFilas(M, x, aux, i);
	}
}

void combFilas(vector < vector < double > > &matriz, unsigned int filaOrigen, double factor, unsigned int filaDestino)
{
	for(unsigned int i = 0; i < matriz.size(); i++)
		matriz[filaDestino][i] = matriz[filaDestino][i] + factor * matriz[filaOrigen][i];
}

double productoDiag(const vector < vector < double > > &matriz)
{
	double d = 1.0;

	for(unsigned int i = 0; i < matriz.size(); i++)
		d = d * matriz[i][i];

	return d;  
}

void ajustePolinomico(vector<double> &n, vector<double> &tiemposReales, vector<double> &a){
	vector<vector<double>> A;
	vector<vector<double>> B;
	vector<vector<double>> X;
	
	A= vector<vector<double>>(4, vector <double>(4));
	B= vector<vector<double>>(4, vector <double>(1));
	X= vector<vector<double>>(4, vector <double>(1));
	
	A[0][0]= n.size();
	A[0][1]= sumatorio(n, tiemposReales, 1, 0);
	A[0][2]= sumatorio(n, tiemposReales, 2, 0);
	A[0][3]= sumatorio(n, tiemposReales, 3, 0);

	A[1][0]= sumatorio(n, tiemposReales, 1, 0);
	A[1][1]= sumatorio(n, tiemposReales, 2, 0);
	A[1][2]= sumatorio(n, tiemposReales, 3, 0);
	A[1][3]= sumatorio(n, tiemposReales, 4, 0);

	A[2][0]= sumatorio(n, tiemposReales, 2, 0);
	A[2][1]= sumatorio(n, tiemposReales, 3, 0);
	A[2][2]= sumatorio(n, tiemposReales, 4, 0);
	A[2][3]= sumatorio(n, tiemposReales, 5, 0);

	A[3][0]= sumatorio(n, tiemposReales, 3, 0);
	A[3][1]= sumatorio(n, tiemposReales, 4, 0);
	A[3][2]= sumatorio(n, tiemposReales, 5, 0);
	A[3][3]= sumatorio(n, tiemposReales, 6, 0);


	B[0][0]= sumatorio(n, tiemposReales, 0, 1);
	B[1][0]= sumatorio(n, tiemposReales, 1, 1);
	B[2][0]= sumatorio(n, tiemposReales, 2, 1);
	B[3][0]= sumatorio(n, tiemposReales, 3, 1);


	resolverSistemaEcuaciones(A, B, 4, X);

	for(int i=0; i<4; i++){
		a.push_back(X[i][0]);
	}
	
}

void calcularTiemposEstimadosPolinomico(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a, vector<double> &tiemposEstimados){
	for(size_t i=0; i<n.size(); i++){
		tiemposEstimados.push_back(a[0]+a[1]*n[i]+a[2]*pow(n[i], 2)+a[3]*pow(n[i], 3));
	}
}

double calcularTiempoEstimadosPolinomico(const double &n, const vector<double> &a){
	return a[0]+a[1]*n+a[2]*pow(n, 2)+a[3]*pow(n, 3);
}

