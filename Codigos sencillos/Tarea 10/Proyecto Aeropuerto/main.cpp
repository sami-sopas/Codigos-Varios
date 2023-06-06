#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Pasajero.h"
#include "Fecha.h"
#include "Pila.h"
#include "Cola.h"

using namespace std;

Fecha generarFecha();
Pasajero comprarTicket();
int generarNumeroAleatorio();///1 - 9999
int generarNumeroAleatorioParaMes();
int generarNumeroAleatorioParaDia();
string generarAsiento();///49I
void generarPersonajes();

int main(){
    char op;
    Cola tickets;
    Pila avion;
    Cola bajan;

    do{
        cout<<endl<<"-------------------------"<<endl;
        cout<<"Elije proceso."<<endl<<endl<<"a. Comprar nuevo ticket."<<endl<<"b. Revisar pasajeros."<<endl<<"c. Abordar avion."<<endl<<"d. Bajar del avion."<<endl<<"e. Subir a un taxi."<<endl<<"f. Salir.";
        cout<<endl<<"-------------------------"<<endl;
        fflush(stdin); cin>>op;

        switch(op){
            case 'a':
                tickets.encolar(comprarTicket());
                cout<<" o"<<endl<<"/|\\\tPasajero registrado."<<endl<<"/\\"<<endl;
            break;
            case 'b':
                cout<<"---PASAJEROS---"<<endl;
                generarPersonajes();
                cout<<tickets.toString();
            break;
            case 'c':
                if(tickets.vacia(tickets.getFrentePos())){
                    cout<<"No hay pasajeros en espera."<<endl;
                }else{
                    while(!tickets.vacia(tickets.getFrentePos())){
                        avion.push(tickets.desencolar());
                    }

                    generarPersonajes();
                    cout<<"Los pasajeros en espera han abordado su vuelo."<<endl;
                }
            break;
            case 'd':
                if(avion.vacia()){
                    cout<<"No hay pasajeros que hayan abordado aun"<<endl;
                }else{
                    while(!avion.vacia()){
                        bajan.encolar(avion.pop());
                    }

                    generarPersonajes();
                    cout<<"Los pasajeros han llegado a su destino."<<endl;
                }
            break;
            case 'e':
                if(bajan.vacia(bajan.getFrentePos())){
                    cout<<"Los pasajeros aun no llegan a su destino."<<endl;
                }else{
                    Pasajero aux;
                    char auxChar;

                    while(!bajan.vacia(bajan.getFrentePos())){
                        aux = bajan.desencolar();

                        cout<<aux.toString()<<endl<<"Este pasajero necesita un taxi? (s)";
                        fflush(stdin); cin>>auxChar;

                        if(auxChar == 's'){
                            cout<<" o"<<endl<<"/|\\\tTaxi solicitado."<<endl<<"/\\"<<endl;
                        }
                    }
                }
            break;
            case 'f': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }
    }while(op != 'f');

    return 0;
}

Fecha generarFecha(){
    Fecha miFecha;

    miFecha.setAnio(2022);
    miFecha.setMes(generarNumeroAleatorioParaMes());
    miFecha.setDia(generarNumeroAleatorioParaDia());

    return miFecha;
}

int generarNumeroAleatorioParaMes(){
    srand((unsigned)time(0));

    return rand() % 12;
}

int generarNumeroAleatorioParaDia(){
    srand((unsigned)time(0));

    return rand() % 30;
}

Pasajero comprarTicket(){
    Pasajero miPasajero;
    string auxString;
    float auxFloat;

    cout<<"Teclea el nombre del pasajero: ";
    fflush(stdin); getline(cin, auxString);
    miPasajero.setNombre(auxString);

    cout<<"Teclea el destino del pasajero: ";
    fflush(stdin); getline(cin, auxString);
    miPasajero.setDestino(auxString);

    miPasajero.setId(generarNumeroAleatorio() + generarFecha().toInt());
    miPasajero.setMiFecha(generarFecha());
    miPasajero.setNumBoleto(generarNumeroAleatorio());
    miPasajero.setAsiento(generarAsiento());

    cout<<"Teclea el peso del equipaje del pasajero: ";
    fflush(stdin); cin>>auxFloat;
    miPasajero.setPesoEquipaje(auxFloat);

    return miPasajero;
}

int generarNumeroAleatorio(){
    srand((unsigned)time(0));

    return rand() % 9999;
}

string generarAsiento(){
    srand((unsigned)time(0));

    int numero(rand() % 49);
    char letra((rand() % 8) + 65);

    return to_string(numero) + string(1, letra);
}

void generarPersonajes(){
    cout<<" o\t o\t o"<<endl<<"/|\\\t/|\\\t/|\\"<<endl<<"/\\\t/\\\t/\\"<<endl;
}
