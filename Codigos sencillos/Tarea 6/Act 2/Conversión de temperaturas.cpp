/*Alumno: Néstor Leonel Nahuatlato Neri
Código: 216546402
Fecha: 24/03/2021

Materia: Seminario de Solución a Problemas de Estructuras de Datos I
NRC: 42656 / SEC: D21
Profesor: LUPERCIO CORONEL, RAMIRO
*/

#include <iostream>
#include <string>

using namespace std;

///Clase Temperatura

class Temperatura{
    private:
        float valor;
    public:
        void setValor(float);
        int getValor();

        string conversion(char);
};

void Temperatura::setValor(float v){
    this->valor = v;
}

int Temperatura::getValor(){
    return this->valor;
}

string Temperatura::conversion(char op){
    string resultado;

    switch(op){
        case 'a':
            resultado = to_string(this->valor) + " 'C es igual a " + to_string(this->valor + 273.15) + " K";
        break;
        case 'b':
            resultado = to_string(this->valor) + " K es igual a " + to_string(this->valor - 273.15) + " 'C";
        break;
        case 'c':
            resultado = to_string(this->valor) + " 'C es igual a " + to_string(this->valor * 1.8 + 32) + " 'F";
        break;
        case 'd':
            resultado = to_string(this->valor) + " 'F es igual a " + to_string((this->valor - 32) / 1.8) + " 'C";
        break;
        case 'e': resultado = "Saliendo...";    break;
        default: resultado = "Opcion incorrecta. Vuelve a intentarlo.";
    }

    return resultado;
}

///Main

int main(){
    char opcion;
    float aux;
    Temperatura grado;

    do{
        cout<<endl<<"--------------------------"<<endl;
        cout<<"Menu"<<endl<<endl<<"a. Celsius -> Kelvin."<<endl<<"b. Kelvin -> Celsius"<<endl<<"c. Celsius -> Fahrenheit."<<endl<<"d. Fahrenheit -> Celsius."<<endl<<"e. SALIR.";
        cout<<endl<<"--------------------------"<<endl;
        cin>>opcion;

        if(opcion == 'a' or opcion == 'b' or opcion == 'c' or opcion == 'd'){
            cout<<"Teclea grado de temperatura: ";
            fflush(stdin); cin>>aux;
            grado.setValor(aux);
        }

        cout<<grado.conversion(opcion)<<endl;
    }while(opcion != 'e');

    return 0;
}
