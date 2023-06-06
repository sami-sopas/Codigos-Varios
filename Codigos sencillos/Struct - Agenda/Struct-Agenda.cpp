#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Calificaciones{
    int grades;
};
Calificaciones a[5];

struct Agenda{
    Calificaciones.grades;
	int id;
	char nombre[30];
    char direccion[30];
    char telefono[10];
};
Agenda a[5];

//Prototipos
void registrar();
void buscar();
void mostrar(int);
void editar();
void remover();
void listar();

int Usercount(0);

int main(){
    char op;
    do{
        cout<<"----------------------"<<endl;
        cout<<"Seleccione una opcion."<<endl<<"a. Registro."<<endl<<"b. Buscar."<<endl<<"c. Editar."<<endl<<"d. Eliminar."<<endl<<"e. Mostrar."<<endl<<"f. SALIR."<<endl;
        cout<<"----------------------"<<endl;
        fflush(stdin); cin>>op;

        switch(op){
            case 'a': registrar();  break;
            case 'b': buscar();     break;
            case 'c': editar();     break;
            case 'd': remover();    break;
            case 'e': listar();     break;
            case 'f': break;
        }
    }while(op != 'f');

    return 0;
}

void registrar(){
    for(int i = 0; i < 5; i++){
        a[i].id = i + 1;

        cout<<endl<<"Teclea el nombre del usuario("<<a[i].id<<"): ";
        cin>>a[i].nombre;
        cout<<endl<<"Teclea la direccion del usuario("<<a[i].id<<"): ";
        cin>>a[i].direccion;
        cout<<endl<<"Teclea el telefono del usuario("<<a[i].id<<"): ";
        cin>>a[i].telefono;
        cout<<endl;

        Usercount++;
    }

    system("cls");
}

void buscar(){
    int auxOP, auxID;
    char auxNombre[30];

    cout<<endl<<"Escoje opcion de busqueda."<<endl<<"1. ID."<<endl<<"2. Nombre."<<endl;
    cin>>auxOP;

    if(auxOP == 1){
        cout<<endl<<"Teclea ID: ";
        cin>>auxID;

        for(int i = 0; i < Usercount; i++)
            if(auxID == a[i].id){
                mostrar(i);
                break;
            }
    }else if(auxOP == 2){
        cout<<endl<<"Teclea Nombre: ";
        cin>>auxNombre;

        for(int i = 0; i < Usercount; i++)
            if(strcmp(a[i].nombre, auxNombre) == 0){
                mostrar(i);
                break;
            }
    }else{
        cout<<endl<<"Opcion incorrecta. El usuario no fue encontrado."<<endl;
    }
}

void listar(){
    for(int i = 0; i < Usercount; i++){
        cout<<endl<<"---------------"<<endl;
        cout<<"USUARIO "<<a[i].id<<endl<<"NOM: "<<a[i].nombre<<endl<<"DIC: "<<a[i].direccion<<endl<<"TEL: "<<a[i].telefono<<endl;
        cout<<"---------------"<<endl;
        cout<<endl;
    }
}

void mostrar(int pos){
    cout<<endl<<"---------------"<<endl;
    cout<<"Id: "<<a[pos].id<<endl<<"NOM: "<<a[pos].nombre<<endl<<"DIC: "<<a[pos].direccion<<endl<<"TEL: "<<a[pos].telefono<<endl;
    cout<<"---------------"<<endl;
}

void editar(){
    int auxID;

    cout<<endl<<"Teclea ID del usuario a editar: ";
    cin>>auxID;

    if(auxID < 6 && auxID > 0){
        cout<<endl<<"Teclea el nuevo nombre del usuario("<<auxID<<"): ";
        cin>>a[auxID].nombre;
        cout<<endl<<"Teclea la nuevo direccion del usuario("<<auxID<<"): ";
        cin>>a[auxID].direccion;
        cout<<endl<<"Teclea el nuevo telefono del usuario("<<auxID<<"): ";
        cin>>a[auxID].telefono;
        cout<<endl;
    }else{
        cout<<endl<<"ID incorrecto."<<endl;
    }
    system("cls");
}

void remover(){
    int auxID;

    cout<<endl<<"Teclea ID del usuario a ELIMINAR: ";
    cin>>auxID;

    for(int i = 0; i < Usercount; i++)
        if(auxID == a[i].id){
            cout<<endl<<"Eliminando a este usuario..."<<endl;
            mostrar(i);

            if(auxID != Usercount - 1){
                a[auxID].id = a[Usercount - 1].id;
                strcpy(a[auxID].nombre , a[Usercount - 1].nombre);
                strcpy(a[auxID].direccion , a[Usercount - 1].direccion);
                strcpy(a[auxID].telefono , a[Usercount - 1].telefono);

                Usercount--;
            }else{
                Usercount--;
            }

            break;
        }else if(i == Usercount - 1){
            cout<<endl<<"Usuario no encontrado."<<endl;
        }
}
