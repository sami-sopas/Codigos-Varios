//1. Escribe un programa que lea de la entrada estandar dos numeros y muestre en la salida estandar su suma, resta, multiplicacion y division

#include<iostream>

using namespace std;

int main(){
    int n1,n2,suma = 0, resta = 0, multiplicacion=0, division=0; //Aqui se guardan los numeros que se van a registrar y las variables
    
    cout<<"Digite un numero:";cin>>n1;
    cout<<"Digite otro numero:";cin>>n2;
    
    suma=n1+n2;
    resta=n1-n2;
    multiplicacion=n1*n2;
    division=n1/n2;
    
    cout<<"\nLa suma es"<<suma<<endl;
    cout<<"La resta es"<<resta<<endl;
    cout<<"La multiplicacion es"<<multiplicacion<<endl;
    cout<<"La division es"<<division<<endl;
    
 	
 return 0;
}
