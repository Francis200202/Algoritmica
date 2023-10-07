#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>

#include "serietemporal.hpp"
#include "metodos.hpp"
#include "ClaseTiempo.hpp"

using namespace std;

void metodo1(){
	//E(n,m)-->aproximar los n primeros puntos de la serie usando m puntos
	Clock time;

	int n, m;
	char fich[20]= "metodo1.txt";
	char nombre[20];
	int punto=0;
	long double ise;
	long double errorMaximo;
	cout<<"Nombre de la serie"<<endl;
	cin>>nombre;
	SerieTemporal serie(nombre);

	n=serie.numeroPuntosSerieTemporal();

	cout<<"Numero de puntos de segmentacion:"<<endl;
	cin>>m;

	vector<vector<double long>> E(n, vector<double long> (m, 0));
	vector<vector<int>> father(n, vector<int> (m, 0));
	vector<int>f;

	//Poner casos iniciales
	E[0][0]=0;
	for(int i=1;i<n;i++){
		E[i][0]=99999999;
	}
	int fath;
	double long min;

	time.start();
	//m
	for(int j=1;j<m;j++){
		//n
		for(int i=j;i<n;i++){
			min=9999999;
			for(int k=j-1;k<i-1;k++){
				if(min>(E[k][j-1]+serie.calcularIseEntreDosPuntos(k, i))){
					min=E[k][j-1]+serie.calcularIseEntreDosPuntos(k, i);
					fath=k;
				}
			}
			E[i][j]=min;
			father[i][j]= fath;
		}
	}
	if (time.isStarted()){
		time.stop();
	}

	f.push_back(n-1);
	for(int i=m-2;i>=0;i--){
		f.push_back(father[f.back()][i+1]);
	}

	for(int i=0;i<m;i++){
		serie.dominantePunto(f[i], true);
	}

	serie.dominantePunto(serie.numeroPuntosSerieTemporal()-1, true);
	serie.guardarSegmentacion(fich);

	serie.erroresSegmentacion(ise, errorMaximo, punto);
	cout<<"________________________________________\n"<<endl;
	cout<<"numero de puntos segmentacion= "<<serie.contarPuntosDominantes()<<endl;
	cout<<"ISE= "<<ise<<endl;
	cout<<"errorMaximo= "<<errorMaximo<<endl;
	cout<<"puntoErrorMaximo= "<<punto<<endl;
	cout<<"Tiempo que tarda= "<<time.elapsed()<<" microsegundos"<<endl;
	cout<<"________________________________________\n"<<endl;
}