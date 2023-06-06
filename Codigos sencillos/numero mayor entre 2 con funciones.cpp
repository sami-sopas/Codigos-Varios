//Programa que encuentre el mayor entre 2 numeros

#include<iostream>
#include<conio.h>

using namespace std;

//Prototipo de funcion (Busco que me retorne un valor entero asi que uso int)
int encontrarMax(int x,int y);

//Funcion principal main
int main(){
	int n1,n2;
	int mayor;
	
	cout<<"Digite 2 numeros: ";
	cin>>n1>>n2;
	
	mayor = encontrarMax(n1,n2); //n1 y n2 son x y y.
	cout<<"El mayor de los 2 numeros es: "<<mayor<<endl;
	
	getch();
	return 0;
}

//Definicion de funcion
int encontrarMax(int x,int y){
	int numMax;
	
	if(x>y){
		numMax=x;
	}
	else{
		numMax=y;
	}
	
	return numMax;
}
