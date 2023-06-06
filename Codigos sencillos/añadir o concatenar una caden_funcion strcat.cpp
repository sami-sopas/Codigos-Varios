//Añadir o concatenar cadenas - funcion strcmp()

#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

int main(){
	char cad1[]="Esto es una cadena";
	char cad2[]=" de ejemplo";
	char cad3[30];
	
	strcpy(cad3,cad1); //Aqui cad3 ya tendria lo de cad1
	
	strcat(cad3,cad2); //Strcat te añade al final de la cadena que quieras
	
	cout<<cad3<<endl;
	
	getch();
	return 0;
}
