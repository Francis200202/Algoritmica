#include <iostream>
#include "metodos.hpp"

using namespace std;

int main(){
	int op= 0;
	
	do{
		cout<<"1->Metodo1\n2->Metodo2\n3->SALIR"<<endl;
		cin>>op;
		switch(op)
		{
			case 1:
				metodo1();
				break;

			case 2:
				metodo2();
				break;
		}	
	}while(op!=3);
	
}