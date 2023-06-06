/*Programa que lea un vector de numeros y muestre en la salida
los numeros del vector son sus indices asociados*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[100];
	int n;
	
	cout<<"Digite el numero de elementos que tendra el arreglo: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"Digite un numero: ";
		cin>>numeros[i]; //Guardando todos los elementos del vector
	}
	
	//Mostrar los elementos con sus indices
	
	for(int i=0;i<n;i++){
		cout<<i<<" -> "<<numeros[i]<<endl;
	}
	
	getch();
	return 0;
}
