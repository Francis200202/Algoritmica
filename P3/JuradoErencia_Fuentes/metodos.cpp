#include <algorithm>
#include <fstream>
#include <cstring>
#include <cassert>

#include "serietemporal.hpp"
#include "punto.hpp"
#include "recta.hpp"
#include "metodos.hpp"

using namespace std;

void metodo1(){
	int ndom;
	char fich[20]= "metodo1.txt";
	char nombre[20];
	int punto=0;
	vector<int>dominantes;
	vector<long double>ISE;
	long double ise;
	long double errorMaximo;
	cout<<"Nombre de la serie"<<endl;
	cin>>nombre;
	SerieTemporal serie(nombre);

	cout<<"Numero de puntos dominantes:"<<endl;
	cin>>ndom;
	
	rellenarDominantes(serie, dominantes);
	
	rellenarISE(serie, dominantes, ISE);
		
	while(ndom<dominantes.size()){
		calcularISE(ISE, punto, dominantes);
		
		dominantes.erase(dominantes.begin()+punto);
		
		ISE.erase(ISE.begin()+punto);
		
		recalcularISE(serie, ISE, dominantes, punto);
	}
	//asiganar dominantes al vector bool dominanttes
	for(size_t i=0;i<dominantes.size();i++){
		serie.dominantePunto(dominantes[i], true);
	}
	serie.guardarSegmentacion(fich);

	serie.erroresSegmentacion(ise, errorMaximo, punto);
	cout<<"numero de puntos dominantes: "<<serie.contarPuntosDominantes()<<endl;
	cout<<"ISE= "<<ise<<endl;
	cout<<"errorMaximo= "<<errorMaximo<<endl;
	cout<<"puntoErrorMaximo= "<<punto<<"\n"<<endl;
}

//Funcion usada por ambos metodos
void rellenarDominantes(SerieTemporal &serie, vector<int> &dominantes){
	for(int i=0; i<serie.numeroPuntosSerieTemporal();i++){
		dominantes.push_back(i);
	}
}

void rellenarISE(SerieTemporal &serie, vector<int> &dominantes, vector<long double> &ISE){
	ISE.push_back(99999);
	for(int i=1; i<dominantes.size()-1; i++){
		ISE.push_back(serie.calcularIseEntreDosPuntos(dominantes[i-1], dominantes[i+1]));
	}
	ISE.push_back(99999);
	
}

void calcularISE(vector<long double> &ISE, int &punto, vector<int> &dominantes){
	long double min= ISE[0];
	for(int i=0; i<ISE.size(); i++){
		if(ISE[i]<min){
			min=ISE[i];
			punto=i;
		}
	}
}

void recalcularISE(SerieTemporal &serie, vector<long double> &ISE, vector<int> &dominantes, int punto){
	if(punto>1){
		ISE[punto-1]=serie.calcularIseEntreDosPuntos(dominantes[punto-2], dominantes[punto]);
	}
	
	if(punto>0 && punto<dominantes.size()-1){
		ISE[punto]=serie.calcularIseEntreDosPuntos(dominantes[punto-1], dominantes[punto+1]);
	}

	if(punto<dominantes.size()-2){
		ISE[punto+1]=serie.calcularIseEntreDosPuntos(dominantes[punto], dominantes[punto+2]);
	}
}

//Metodo 2
void metodo2(){
	int ndom;
	char fich[20]= "metodo2.txt";
	char nombre[20];
	int punto=0;
	vector<int>dominantes;
	vector<long double>eMax;
	long double ise;
	long double errorMaximo;
	cout<<"Nombre de la serie"<<endl;
	cin>>nombre;
	SerieTemporal serie(nombre);

	cout<<"Numero de puntos dominantes:"<<endl;
	cin>>ndom;
	
	rellenarDominantes(serie, dominantes);
	
	rellenareMax(serie, dominantes, eMax);
	
	while(ndom<dominantes.size()){
		calculareMax(eMax, punto, dominantes);
		
		dominantes.erase(dominantes.begin()+punto);
		
		eMax.erase(eMax.begin()+punto);
		
		recalculareMax(serie, eMax, dominantes, punto);
	}
	//asiganar dominantes al vector bool dominanttes
	for(size_t i=0;i<dominantes.size();i++){
		serie.dominantePunto(dominantes[i], true);
	}
	serie.guardarSegmentacion(fich);

	serie.erroresSegmentacion(ise, errorMaximo, punto);
	cout<<"numero de puntos dominantes: "<<serie.contarPuntosDominantes()<<endl;
	cout<<"ISE= "<<ise<<endl;
	cout<<"errorMaximo= "<<errorMaximo<<endl;
	cout<<"puntoErrorMaximo= "<<punto<<"\n"<<endl;
}

void rellenareMax(SerieTemporal &serie, vector<int> &dominantes, vector<long double> &eMax){
	int pos;
	eMax.push_back(99999);
	for(int i=1; i<dominantes.size()-1; i++){
		eMax.push_back(serie.calcularEmaxEntreDosPuntos(dominantes[i-1], dominantes[i+1], pos));
	}
	eMax.push_back(99999);
	
}

void calculareMax(vector<long double> &eMax, int &punto, vector<int> &dominantes){
	long double min= eMax[0];
	for(int i=0; i<eMax.size(); i++){
		if(eMax[i]<min){
			min=eMax[i];
			punto=i;
		}
	}
}

void recalculareMax(SerieTemporal &serie, vector<long double> &eMax, vector<int> &dominantes, int punto){
	int pos;
	if(punto>1){
		eMax[punto-1]=serie.calcularEmaxEntreDosPuntos(dominantes[punto-2], dominantes[punto], pos);
	}
	
	if(punto>0 && punto<dominantes.size()-1){
		eMax[punto]=serie.calcularEmaxEntreDosPuntos(dominantes[punto-1], dominantes[punto+1], pos);
	}

	if(punto<dominantes.size()-2){
		eMax[punto+1]=serie.calcularEmaxEntreDosPuntos(dominantes[punto], dominantes[punto+2], pos);
	}
}