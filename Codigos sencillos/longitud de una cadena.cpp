//Longitud de una cadena de caracteres - funcion strlen()

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main(){
	char palabra[]="hola";
	int longitud=0;
	
	longitud=strlen(palabra);
	
	cout<<"Numero de elementos de la cadena: "<<longitud<<endl;
	
	getch();
	return 0;
}
