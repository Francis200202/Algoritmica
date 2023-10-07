#include <iostream>
#include <vector>
#include "funciones.hpp"

using namespace std;

int main(){
	int opc;
	
	do{
		cout<<"\n--Selecciona una opcion--"<<endl;
		cout<<"1->Backtraking, obtener soluciones\n2->Backtraking, obtener 1 solucion \n3->Vegas, obtener 1 solucion\n4->SALIR"<<endl;
		cin>>opc;

		switch(opc){
			case 1:
				opcion1();
				break;
			case 2:
				opcion2();
				break;
			case 3:
				opcion3();
				break;
		}
	}while(opc!=4);
	
}