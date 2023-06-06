#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

class Usuario
{
public:
    char nombre[20],fecha[30],tarjeta[35],perfil[25];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} usuarios;

void Usuario::Agregar()
{
    cout<<"AGREGAR NUEVO USUARIO"<<endl;
    cout<<"Nombre de usuario: ";
    cin.sync();
    cin.getline(nombre,20);
    cout<<"Fecha: ";
    cin.getline(fecha,30);
    cout<<"Numero de tarjeta: ";
    cin.getline(tarjeta,35);
    cout<<"Tipo de perfil (completo o restringido): ";
    cin.getline(perfil,25);
    ofstream archivo("usuarios.txt",ios::app);
    archivo.write((char*)&user,sizeof(user));
    archivo.close();
}
void Usuario::Mostrar()
{
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"USUARIOS"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&usuarios,sizeof(usuarios));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Tarjeta: "<<tarjeta<<endl;
            cout<<"Tipo de perfil: "<<perfil<<endl;
            cout << endl;
        }
        archivo.close();
    }
}
void Usuario::Modificar()
{
    char valor[20];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MODIFICAR USUARIO"<<endl;
        cout<<"Ingrese el nombre del usuario a modificar ";
        cin.sync();
        cin.getline(valor,20);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&usuarios,sizeof(usuarios));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(nombre,valor)==0)
            {
                cout<<""<<endl;
                cout<<"Nuevo nombre: ";
                cin.getline(nombre,20);
                cout<<"Nueva fecha: ";
                cin.getline(fecha,30);
                cout<<"Nueva tarjeta: ";
                cin.getline(tarjeta,35);
                cout<<"Nuevo tipo de perfil: ";
                cin.getline(perfil,25);
                ofstream archivo("usuarios.txt",ios::app);
                archivo2.write((char*)&usuarios,sizeof(usuarios));
            }
            else
            {
                archivo2.write((char*)&usuarios,sizeof(usuarios));
            }

        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }
}
void Usuario::Eliminar()
{
    char valor[20];
    int opcion;
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ELIMINAR USUARIO"<<endl;
        cout<<"Ingrese el nombre de usuario a eliminar ";
        cin.sync();
        cin.getline(valor,20);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&usuarios,sizeof(usuarios));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(nombre,valor)==0)
            {
                cout<<"\tUsuario encontrado"<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Numero de tarjeta: "<<tarjeta<<endl;
                cout<<"Tipo de perfil: "<<perfil<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&usuarios,sizeof(usuarios));
                }
            }
            else
            {
                archivo2.write((char*)&usuarios,sizeof(usuarios));
            }
        }
        archivo.close();
        archivo2.close();
        remove("usuarios.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="usuarios.txt";
        rename(oldname,newname);
    }

}
void Usuario::Buscar()
{
    char valor[20];
    ifstream archivo("usuarios.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"BUSCAR USUARIO"<<endl;
        cout<<"Ingrese el nombre de usuario a buscar ";
        cin.sync();
        cin.getline(valor,20);

        while(!archivo.eof())
        {
            archivo.read((char*)&usuarios,sizeof(usuarios));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(nombre,valor)==0)
            {
                cout<<"\tUsuario encontrado"<<endl;
                cout<<"Nombre: "<<nombre<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Numero de tarjeta: "<<tarjeta<<endl;
                cout<<"Tipo de perfil: "<<perfil<<endl;
            }
        }
    }
       archivo.close();
}

void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}

int main()
{
    int op;
    do
    {
        system("cls");
        cout<<"MENU DE USUARIOS"<<endl;
        cout<<"1.-Capturar" <<endl;
        cout<<"2.-Imprimir todo" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            usuarios.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            usuarios.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            usuarios.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            usuarios.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            usuarios.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}
