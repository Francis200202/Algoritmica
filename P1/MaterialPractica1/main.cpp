//g++ -Wall main.cpp qsort.cpp

#include <cassert>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t
#include <algorithm>
#include "sistemaEcuaciones.hpp"
#include "ClaseTiempo.hpp"

using namespace std;

void ordenacionQuickSort();
void rellenarVector(vector<int>&v);

int main(){
	int op= 0;
	cout<<"1->ordenacionQuickSort()\n2->determinanteIterativo()\n3->determinanteRecursivo()"<<endl;
	cin>>op;
	switch(op)
	{
		case 1:
			ordenacionQuickSort();
			break;

		case 2:
			determinanteIterativo();
			break;

		case 3:
			determinanteRecursivo();
		break;
	}
}

