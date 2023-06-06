//funciones
#include<iostream>

using namespace std;

float num1=0,num2=0;
float resultado=0;
int opc=0;
void suma();
void resta(float,float);
float division(float,float);
float multiplicacion();
int main(){
	
	
	/*cout<<"Numero 1: "<<endl;
	cin>>num1;
	cout<<"Numero 2:"<<endl;
	cin>>num2;*/
	do{
		cout<<"Que opcion quieres"<<endl;
		cout<<"1) sumar"<<endl;
		cout<<"2) restar"<<endl;
		cout<<"3) multiplicar"<<endl;
		cout<<"4) dividir"<<endl;
		cout<<"5) salir"<<endl;
		cin>>opc;
		
		switch(opc){
			case 1:
				suma();
				break;
			case 2:
				cout<<"Numero 1: "<<endl;
             	cin>>num1;
             	cout<<"Numero 2:"<<endl;
            	cin>>num2;
            	resta(num1,num2); //enviando los parametros
				break;
			case 3:
				cout<<"resultado "<<multiplicacion()<<endl;
				break;
			case 4:
				cout<<"Numero 1: "<<endl;
             	cin>>num1;
             	cout<<"Numero 2:"<<endl;
            	cin>>num2;
            	resultado = division(num1,num2);
            	cout<<"resultado "<<resultado<<endl;
            	
				break;
			case 5:
				break;
			default:
				cout<<"opcion invalida"<<endl;
				break;
		}
		
		system("pause");
		system("cls");
		
		
	}while(opc!=5);
	
	
	
	return 0;
}


//hay 4 tipos de funciones y se impplementan fuera del main

//Funcion sin parametros no retorna nada
void suma(){
	float num1=0,num2=0;
	cout<<"Numero 1: "<<endl;
	cin>>num1;
	cout<<"Numero 2:"<<endl;
	cin>>num2;
	
	cout<<"la suma es: "<<num1+num2<<endl;
}

//Funcion con parametros no retorna nada
void resta(float num1,float num2){
	cout<<"resultado: "<<num1-num2<<endl;
}

//Funcion que retorna sin parametros
float multiplicacion(){
	float num1=0,num2=0;
	cout<<"Numero 1: "<<endl;
	cin>>num1;
	cout<<"Numero 2:"<<endl;
	cin>>num2;
	
	return num1*num2; //Manda el resultado directo sin otra variable
}

//Funcion que retorna con parametros
float division(float num1,float num2){
	float resultado;
	resultado = num1/num2;
	return resultado;
}
