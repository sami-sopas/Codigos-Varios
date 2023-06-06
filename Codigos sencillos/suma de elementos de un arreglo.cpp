/*Programa que defina un vector de numeros y calcule la suma de sus elementos*/
#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int numeros[]={1,2,3,4,5}; //Se definen los elementos del arreglo
	int suma=0; //Aqui se almacena el resultado de la suma
	
	for(int i=0;i<5;i++){
	    suma= suma + numeros[i];
    }
    
    cout<<"La suma de los elementos es: "<<suma<<endl;
    
    getch();
    return 0;
}
