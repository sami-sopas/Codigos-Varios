/*Alumno: Nahuatlato Neri Néstor Leonel
Código: 216546402

Fecha: 09/03/2021

Materia: Seminario de Solución de Problemas de Estructuras de Datos I (I5887)
Profesor: LUPERCIO CORONEL, RAMIRO.
Sección: D21 / NRC: 42656*/

#include <iostream>

using namespace std;

double numVotos[3];
double* ptrs[3];

void inicializacion();
double* ConteoDeVotos(double*);
void MostrarResultados();

int main(){
    char op;
    inicializacion();

    do{
        cout<<endl<<"----Urna de votos----"<<endl;
        cout<<"a. Candidato A."<<endl<<"b. Candidato B."<<endl<<"c. Candidato C."<<endl<<"d. SALIR.";
        cout<<endl<<"---------------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': case 'A':
                ptrs[0] = &numVotos[0];
                numVotos[0] = *ConteoDeVotos(ptrs[0]);
            break;
            case 'b': case 'B':
                ptrs[1] = &numVotos[1];
                numVotos[1] = *ConteoDeVotos(ptrs[1]);
            break;
            case 'c': case 'C':
                ptrs[2] = &numVotos[2];
                numVotos[2] = *ConteoDeVotos(ptrs[2]);
            break;
            case 'd': case 'D': cout<<"SALIENDO..."<<endl;  break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo."<<endl;
        }

        MostrarResultados();
    }while(op != 'd');

    return 0;
}

void inicializacion(){
    for(int i(0); i < 3; i++){
        numVotos[i] = 0;
        ptrs[i] = nullptr;
    }
}

double* ConteoDeVotos(double* p){
    *p = *p + 1;
    return p;
}

void MostrarResultados(){
    double votosTotales(0);
    for(int i(0); i < 3; i++)
        if(ptrs[i] != nullptr)
            votosTotales += *ptrs[i];

    char auxChar = 'A';
    for(int i(0); i < 3; i++)
        if(ptrs[i] != nullptr){
            cout<<endl<<"-----Candidato "<<auxChar<<" ----"<<endl;
            cout<<"Votos: "<<*ptrs[i]<<endl<<"Porcentaje: "<<(*ptrs[i] / votosTotales) * 100<<endl;
            cout<<"--------------------"<<endl;
            auxChar++;
        }
}
