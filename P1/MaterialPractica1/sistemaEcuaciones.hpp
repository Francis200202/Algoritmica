#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>

using namespace std;


void resolverSistemaEcuaciones(vector < vector < double > > A, vector < vector < double > > B, int n, vector < vector < double > > &X);

//A es la matriz de coeficientes de NXN
//B es la matriz de terminos independientes de NX1
//n es el orden de las matrices
//X es el valor de las variables que se obtienen resolviendo el sistema
//Declaracion y reserva de matrices usando el tipo vector de la STL
// vector < vector < double > > matrizDatos;
// matrizDatos = vector< vector< double > >(filas, vector< double >(columnas)); //Matriz de N x N
void ordenacionQuickSort();
void rellenarVector(vector<int>&v);
bool estaOrdenado(const vector<int>&v);
void fichero(vector<double>&tiemposReales, vector<double>&numeroElementos);
void datosFinales(const vector<double> &numeroElementos, const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);
void calcularTiemposEstimadoNlogN(const vector<double> &numeroElementos,const vector<double> &a, vector<double> &tiemposEstimados);
double calcularTiempoEstimadoNlogN(const double &n, vector<double> &a);
void ajusteNlogN(const vector<double> &numeroElementos, vector<double> &tiemposReales, vector<double> &a);
double sumatorio(vector<double> &n, vector<double> &t, int expN, int expT);
double calcularCoeficienteDeterminacion(const vector<double> &tiemposReales, const vector<double> &tiemposEstimados);


void determinanteIterativo();
void rellenarMatriz(vector<vector<double>> &M);
double triangulo(vector<vector<double>> M);
bool elimCero(vector<vector<double>> M, unsigned int x);
void hacerCerosColum(vector<vector<double>> M, unsigned int x);
void combFilas(vector < vector < double > > &matriz, unsigned int filaOrigen, double factor, unsigned int filaDestino);
double productoDiag(const vector < vector < double > > &matriz);
void ajustePolinomico(vector<double> &n, vector<double> &tiemposReales, vector<double> &a);
void calcularTiemposEstimadosPolinomico(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a, vector<double> &tiemposEstimados);
double calcularTiempoEstimadosPolinomico(const double &n, const vector<double> &a);


void determinanteRecursivo();
double algrecursivo(vector<vector<double>> &M, int b);
void ajusteFactorial(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a);
void calcularTiemposEstimadosFactorial(const vector<double> &n, vector<double> &tiemposReales, vector<double> &a, vector<double> &tiemposEstimados);
double calcularTiempoEstimadosFactorial(const double &n, vector<double> &a);

#endif
