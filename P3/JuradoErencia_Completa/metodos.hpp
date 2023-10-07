#ifndef METODOS_HPP
#define METODOS_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "serietemporal.hpp"
#include "punto.hpp"
#include "recta.hpp"

//Funcion comun
void rellenarDominantes(SerieTemporal &serie, vector<int> &dominantes);
//Metodo 1
void metodo1();
void rellenarISE(SerieTemporal &serie, vector<int> &dominantes, vector<long double> &ISE);
void calcularISE(vector<long double> &ISE, int &punto, vector<int> &dominantes);
void recalcularISE(SerieTemporal &serie, vector<long double> &ISE, vector<int> &dominantes, int punto);
//Metodo 2
void metodo2();
void rellenareMax(SerieTemporal &serie, vector<int> &dominantes, vector<long double> &eMax);
void calculareMax(vector<long double> &eMax, int &punto, vector<int> &dominantes);
void recalculareMax(SerieTemporal &serie, vector<long double> &eMax, vector<int> &dominantes, int punto);
#endif