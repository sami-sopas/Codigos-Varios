#include <iostream>
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Poligono.h"

using namespace std;

Triangulo miTriangulo;
Cuadrado miCuadrado;
Rectangulo miRectangulo;
Poligono miPoligono;

void CapturarInfo(char);

int main(){
    char op;

    do{
        cout<<endl<<"---------------"<<endl;
        cout<<"Elije opcion."<<endl<<endl<<"a. Triangulo."<<endl<<"b. Cuadrado."<<endl<<"c. Rectangulo."<<endl<<"d. Poligono"<<endl<<"e. Salir.";
        cout<<endl<<"---------------"<<endl;
        fflush(stdin); cin>>op;

        if(op == 'a' or op == 'b' or op == 'c' or op == 'd')
            CapturarInfo(op);

        switch(op){
            case 'a': cout<<endl<<"Area del Triangulo: "<<miTriangulo.getArea()<<endl; break;
            case 'b': cout<<endl<<"Area del Cuadrado: "<<miCuadrado.getArea()<<endl; break;
            case 'c': cout<<endl<<"Area del Rectangulo: "<<miRectangulo.getArea()<<endl; break;
            case 'd': cout<<endl<<"Area del Poligono: "<<miPoligono.getArea()<<endl; break;
            case 'e': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }

    }while(op != 'e');

    return 0;
}

void CapturarInfo(char op){
    double aux1, aux2;

    cout<<endl<<"Teclea base: ";
    fflush(stdin); cin>>aux1;

    if(op == 'a' or op == 'c'){
        cout<<"Teclea altura: ";
        fflush(stdin); cin>>aux2;
    }

    switch(op){
        case 'a':
            miTriangulo.setBase(aux1);
            miTriangulo.setAltura(aux2);
        break;
        case 'b': miCuadrado.setBase(aux1); break;
        case 'c':
            miRectangulo.setBase(aux1);
            miRectangulo.setAltura(aux2);
        break;
        case 'd':
            miPoligono.setBase(aux1);

            cout<<"Teclea numero de lados: ";
            fflush(stdin); cin>>aux1;
            miPoligono.setNumLados(aux1);

            cout<<"Teclea apotema: ";
            fflush(stdin); cin>>aux2;
            miPoligono.setApotema(aux2);
        break;
    }
}
