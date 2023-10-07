#ifndef METODOS_HPP
#define METODOS_HPP

#include <iostream>
#include <vector> //para manejar la clase vector de la STL>
#include <cmath>
#include <cstdlib>
#include "serietemporal.hpp"
#include "punto.hpp"
#include "recta.hpp"

void metodo1();
void metodo2();

void recursividad1(SerieTemporal &serie,float eMax, int p1, int p2);
void recursividad2(SerieTemporal &serie,float eMax, int p1, int p2);


#endif