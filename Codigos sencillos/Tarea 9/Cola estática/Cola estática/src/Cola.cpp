#include "Cola.h"

using namespace std;

Cola::Cola(): posFrente(0), posFinal(MAXIMO - 1){}

bool Cola::vacia() const{
    return posFrente == posFinal + 1 or (posFrente == 0 and posFinal == MAXIMO - 1);
}

bool Cola::llena() const{
    return posFrente == posFinal + 2 or (posFrente == 0 and posFinal == MAXIMO - 2) or (posFrente == 1 and posFinal == MAXIMO - 1);
}

void Cola::encolar(const int& e){
    if(llena()){
        cout<<"No es posible encolar otro dato."<<endl;
        exit(1);
    }

    if(++posFinal == MAXIMO)
        posFinal = 0;

    datos[posFinal] = e;
}

int Cola::desencolar(){
    if(vacia()){
        cout<<"No es posible desencolar datos."<<endl;
        exit(1);
    }

    int resultado(datos[posFrente]);

    if(++posFrente == MAXIMO)
        posFrente = 0;

    return resultado;
}

int Cola::getFrente(){
    if(vacia()){
        cout<<"No es posible obtener los datos."<<endl;
        exit(1);
    }

    return datos[posFrente];
}

int Cola::getFinal(){
    if(vacia()){
        cout<<"No es posible obtener datos."<<endl;
        exit(1);
    }

    return datos[posFinal];
}

string Cola::Imprimir() const{
    string resultado;
    int i(posFrente);

    while(i != posFinal + 1){
        resultado += to_string(datos[i]) + " ";

        if(++i == MAXIMO)
            i = 0;
    }

    return resultado;
}
