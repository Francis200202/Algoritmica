#include <vector>    // necesario para el contenedor Vector2D
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <cassert>

#include "serietemporal.hpp"
#include "punto.hpp"
#include "recta.hpp"
#include "metodos.hpp"

using namespace std;

void metodo1(){
	float eMax;
	char nombre[20];
	char fich[20]= "metodo1.txt";
	long double ISE;
	long double errorMaximo;
	int punto;
	cout<<"Nombre de la serie"<<endl;
	cin>>nombre;
	SerieTemporal serie(nombre);

	cout<<"Error maximo:"<<endl;
	cin>>eMax;
	
	serie.dominantePunto(0, true);
	
	serie.dominantePunto(serie.numeroPuntosSerieTemporal()-1, true);

	recursividad1(serie, eMax, 0, serie.numeroPuntosSerieTemporal()-1);

	serie.guardarSegmentacion(fich);

	serie.erroresSegmentacion(ISE, errorMaximo, punto);
	cout<<"numero de puntos dominantes: "<<serie.contarPuntosDominantes()<<endl;
	cout<<"ISE= "<<ISE<<endl;
	cout<<"errorMaximo= "<<errorMaximo<<endl;
	cout<<"puntoErrorMaximo= "<<punto<<endl;
}

void metodo2(){
	float eMax;
	char nombre[20];
	char fich[20]= "metodo2.txt";
	long double ISE;
	long double errorMaximo;
	int punto;
	cout<<"Nombre de la serie"<<endl;
	cin>>nombre;
	SerieTemporal serie(nombre);

	cout<<"Error maximo:"<<endl;
	cin>>eMax;

	serie.dominantePunto(0, true);
	
	serie.dominantePunto(serie.numeroPuntosSerieTemporal()-1, true);

	recursividad2(serie, eMax, 0, serie.numeroPuntosSerieTemporal()-1);

	serie.guardarSegmentacion(fich);

	serie.erroresSegmentacion(ISE, errorMaximo, punto);
	cout<<"numero de puntos dominantes: "<<serie.contarPuntosDominantes()<<endl;
	cout<<"ISE= "<<ISE<<endl;
	cout<<"errorMaximo= "<<errorMaximo<<endl;
	cout<<"puntoErrorMaximo= "<<punto<<endl;
}

void recursividad1(SerieTemporal &serie,float eMax, int p1, int p2){
	int punto;

	if(serie.calcularEmaxEntreDosPuntos(p1, p2, punto)>eMax){
		serie.dominantePunto(punto, true);
		recursividad1(serie, eMax, p1, punto);
		recursividad1(serie, eMax, punto, p2);
	}
}

void recursividad2(SerieTemporal &serie,float eMax, int p1, int p2){
	int punto;
	int intermedio = (p1+p2)/2;

	if(serie.calcularEmaxEntreDosPuntos(p1, p2, punto)>eMax){
		serie.dominantePunto(intermedio, true);
		recursividad2(serie, eMax, p1, intermedio);
		recursividad2(serie, eMax, intermedio, p2);
	}

}