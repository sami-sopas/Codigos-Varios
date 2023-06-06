#include <iostream>
#include"pila.h"
#include<stdlib.h>


using namespace std;

bool validacion(char*abc){
bool isValid=false;
if(int(*abc)>=48 && int(*abc)<=57){
    isValid = true;
}
return isValid;
}

int main(){
	pila p;
	int num;
	int opc=0;
	char opcion[100];

		do{    system("cls");
		       p.mostrar_pila();
			cout<<"\n\n[1].ingresar numero\n[2].Eliminar tope\n[3].Mostrar tope\n[4].Mostrar pila\n[5].salir"<<endl;
		         cin>>opcion;
		         if(validacion(opcion)){
                    opc=atoi(opcion);
		         }
			switch(opc){
				case 1:
                    //system("cls");
			        	  p.push();
			            	  break;
				case 2:  p.pop();
			      		   break;
				case 3:  p.mostrar_tope();
			       	  break;
				case 4:  p.mostrar_pila();
				         break;
				default: cout<<"Opcion incorrecta "<<endl;
			                  system("pause");
		}
		}while(opc!=5);
}
