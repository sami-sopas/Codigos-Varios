#include <iostream>
#include "Peso.h"
#include "Dolar.h"
#include "Euro.h"
#include "Yen.h"
#include "Yuan.h"

using namespace std;

int main(){
    char op;
    Peso misPesos;
    Dolar misDolares;
    Euro misEuros;
    Yen misYenes;
    Yuan misYuanes;
    double auxValor;

    do{
        cout<<endl<<"-----------------"<<endl;
        cout<<"Elije opcion."<<endl<<endl<<"a. Peso a Dolar."<<endl<<"b. Peso a Euro."<<endl<<"c. Peso a Yen."<<endl<<"d. Peso a Yuan."<<endl<<"e. Dolar a Peso."<<endl<<"f. Euro a Peso."<<endl<<"g. Yen a Peso."<<endl<<"h. Yuan a Peso."<<endl<<"i. Salir.";
        cout<<endl<<"-----------------"<<endl;
        fflush(stdin); cin>>op;

        if(op == 'a' or op == 'b' or op == 'c' or op == 'd' or op == 'e' or op == 'f' or op == 'g' or op == 'h'){
            cout<<endl<<"Teclea valor: ";
            fflush(stdin); cin>>auxValor;
        }

        switch(op){
            case 'a':
                misPesos.setValor(auxValor);
                cout<<endl<<auxValor<<" pesos es igual a "<<misPesos.getPesoADolar()<<" dolares."<<endl;
            break;
            case 'b':
                misPesos.setValor(auxValor);
                cout<<endl<<auxValor<<" pesos es igual a "<<misPesos.getPesoAEuro()<<" euros."<<endl;
            break;
            case 'c':
                misPesos.setValor(auxValor);
                cout<<endl<<auxValor<<" pesos es igual a "<<misPesos.getPesoAYen()<<" yenes."<<endl;
            break;
            case 'd':
                misPesos.setValor(auxValor);
                cout<<endl<<auxValor<<" pesos es igual a "<<misPesos.getPesoAYuan()<<" yuanes."<<endl;
            break;
            case 'e':
                misDolares.setValor(auxValor);
                cout<<endl<<auxValor<<" dolares es igual a "<<misDolares.getDolarAPeso()<<" pesos."<<endl;
            break;
            case 'f':
                misEuros.setValor(auxValor);
                cout<<endl<<auxValor<<" euros es igual a "<<misEuros.getEuroAPeso()<<" pesos."<<endl;
            break;
            case 'g':
                misYenes.setValor(auxValor);
                cout<<endl<<auxValor<<" yenes es igual a "<<misYenes.getYenAPeso()<<" pesos."<<endl;
            break;
            case 'h':
                misYuanes.setValor(auxValor);
                cout<<endl<<auxValor<<" yuanes es igual a "<<misYuanes.getYuanAPeso()<<" pesos."<<endl;
            break;
            case 'i': break;
            default: cout<<"Opcion Incorrecta. Vuelve a Intentarlo..."<<endl;
        }
    }while(op != 'i');

    return 0;
}
