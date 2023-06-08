///Ramirez Cuenca Samuel Osvaldo_E2

///Librerias del sistema----
#include <iostream>
///Librerias creadas----
#include"rango.h"
#include"tamanio.h"

using namespace std;

void menu(){
    ///Instancias de los objetos Rango y Tamaño
    Rango r;
    Tamanio t;

    int opc=0; //Variable para la opcion del menu
    cout<<"Tipos de datos primitivos y estructurados"<<endl;
    cout<<"1) Magnitud y rando de los tipos de datos\n";
    cout<<"2) Ejemplo de uso de tipo de dato estructurado\n";
    cout<<"3) Salir\n";
    cin>>opc;
    system("cls");

    switch(opc){
        case 1:{ /**Para la opcion 1. Mostramos los valores de los tipos de dato. accediendo mediante
                    su funcion get. que nos retorna el valor que se encuentra en privado**/

        cout<<"Tipos de Datos Primitivos"<<endl;
        cout<<"Tipo de Dato                  |Bits|      |Valor Maximo|        |Valor Minimo| "<<endl;
        cout<<"Caracter con signo\t\t"<<t.getBitsCaracterConSigno()<<"\t   "<<r.getMaximoCaracterConSigno()<<"\t\t\t   "<<r.getMinimoCaracterConSigno();
        cout<<"\nCaracter sin signo\t\t"<<t.getBitsCaracterSinSigno()<<"\t   "<<r.getMaximoCaracterSinSigno()<<"\t\t\t    "<<r.getMinimoCaracterSinSigno();
        cout<<"\nEntero corto sin signo\t\t"<<t.getBitsEnteroCortoSinSigno()<<"\t   "<<r.getMaximoEnteroCortoSinSigno()<<"\t\t    "<<r.getMinimoEnteroCortoSinSigno();
        cout<<"\nEntero corto con signo\t\t"<<t.getBitsEnteroCortoConSigno()<<"\t   "<<r.getMaximoEnteroCortoConSigno()<<"\t\t    "<<r.getMinimoEnteroCortoConSigno();
        cout<<"\nEntero largo sin signo\t\t"<<t.getBitsEnteroLargoSinSigno()<<"\t   "<<r.getMaximoEnteroLargoSinSigno()<<"\t\t    "<<r.getMinimoEnteroLargoSinSigno();
        cout<<"\nEntero largo con signo\t\t"<<t.getBitsEnteroLargoConSigno()<<"\t   "<<r.getMaximoEnteroLargoConSigno()<<"\t\t    "<<r.getMinimoEnteroLargoConSigno();
        break;}

        case 2:{
            /**Para la opcion 2. Solo se pide el numero de filas, columnas que se guardan en estas variables
            y el usuario va ingresando los numeros dependiendo del tamaño que seleccione la matriz **/

        int matriz[100][100],filas,columnas;

    	cout<<"Digite el numero de filas que tendra su matriz: "<<endl;
    	cin>>filas;
    	cout<<"Digite el numero de columas que tendra su matriz: "<<endl;
    	cin>>columnas;

    	for(int i=0;i<filas;i++){ //Insercion de datos en la matriz
    		for(int j=0;j<columnas;j++){
    			cout<<"Digite un numero ["<<i<<"] ["<<j<<"]";
    			cin>>matriz[i][j];
			}
		}

		for(int i=0;i<filas;i++){ //Impresion de los mismos
			for(int j=0;j<columnas;j++){
				cout<< matriz[i][j];
			}
			cout<<"\n";
		}
		break;
        }
        default:{
            cout<<"\nseleccione una opcion";
        break;}
    }
}

int op=0; //Variable para controlar la opcion del usuario dentro de la funcion main

int main()
{
   	do{ //Se ejecuta el menu al menos una vez. despues de cada accion se le pregunta si quiere seguir o salir
		system("cls");
		menu();
		cout<<"\n\nPara continuar escriba 1\nPara salir escriba 2"<<endl;
		cin>>op;
	}while(op!=2);

    return 0;
}
