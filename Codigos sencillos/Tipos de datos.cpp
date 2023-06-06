///Ramirez Cuenca Samuel Osvaldo_E1

/**PROGRAMA QUE MUESTRA LA MAGNITUD Y RANGO DE LOS TIPOS DE DATOS PRIMIRITVOS
   Y UN EJEMPLO DEL USO DE TIPO DE DATO ESTRUCTURADO**/

//Liberia a incluir -----
#include <iostream>

using namespace std;

void menu(){ ///Funcion que muestra todo el menu ( se manda a llamar desde la funcion main )

	int opc=0; ///Variable para controlar la opcion del usuario
	cout<<"Tipos de datos primitivos y estructurados"<<endl;
    cout<<"1- Magnitud y Rango de los Tipos de Datos Primitivos"<<endl;
    cout<<"2- Ejemlo de uso de tipo de dato estructurado"<<endl;
    cout<<"3- Salir del Programa"<<endl;
    cin >> opc;
    system("cls");

    switch(opc){
    case 1:{      ///Mostramos la tabla con los tipos de datos primitivos y sus valores
        cout<<"Tipos de Datos Primitivos"<<endl;
        cout<<"Tipo de Dato                  |Bits|      |Valor Maximo|        |Valor Minimo| "<<endl;
        cout<<"Caracter con signo            8 bits       127                   -128"<<endl;
        cout<<"Caracter sin signo            8 bits       255                    0"<<endl;
        cout<<"Entero corto con signo        16 bits      32,767                -32,767"<<endl;
        cout<<"Entero corto sin signo        16 bits      65,535                 0"<<endl;
        cout<<"Entero largo con signo        16 bits      2.147483647*10^9      -2.147483647*10^9"<<endl;
        cout<<"Entero largo sin signo        16 bits      9.22337203*10^18      -9.22337203*10^18 "<<endl;
        cout<<"Real de presicion simple      32 bits      3,402823466*10^38     -3,402823466*10^38"<<endl;
        cout<<"Real de presicion doble       64 bits     -1,79*10^308           -1,79*10^308"<<endl;
    }break;

    case 2:{
    	int matriz[100][100],filas,columnas;

    	       ///Pedimos el numero de filas y columnas que tendra la matriz
    	cout<<"Digite el numero de filas que tendra su matriz: "<<endl;
    	cin>>filas;
    	cout<<"Digite el numero de columas que tendra su matriz: "<<endl;
    	cin>>columnas;

    	for(int i=0;i<filas;i++){
    		for(int j=0;j<columnas;j++){
    			cout<<"Digite un numero ["<<i<<"] ["<<j<<"]"; ///Aqui se van guardando los valores que escribamos en la matriz
    			cin>>matriz[i][j];
			}
		}


		/**Con este ciclo se imprimira la matriz con los datos ingresados de la siguiente manera:
		    |1|5|
		    |9|2| ...**/

		for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++){
				cout << "|" << matriz[i][j] << "|" ;
			}
			cout<<"\n";
		}
    }break;
}
}
int op=0; ///Variable para controlar la opcion despues de ejecutarse alguna funcion del menu

int main() ///Funcion principal que primero ejecutara el menu al menos una vez.
{
	do{
		system("cls");
		menu();
		cout<<"\nPara continuar escriba 1\nPara salir escriba 2"<<endl;
		cin>>op;
	}while(op!=2);/**Cuando presione 2, lo regresara al menu principal, si presiona salir
	                 volvera a preguntar si desea salir, al presionar 2 denuevo, el programa termina**/

    return 0;
}
