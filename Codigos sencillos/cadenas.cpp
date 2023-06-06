//cadenas

#include<iostream>
#include<conio.h>//Para poder ejecutar el .exe
#include<string.h>//libreria para poder usar cadenas

using namespace std;

int main(){
	char nombre[20];
	
	cout<<"Digite su nombre: ";
	cin.getline(nombre,20,'\n');
	
	cout<<nombre<<endl;
	
	getch();
	return 0;
}
