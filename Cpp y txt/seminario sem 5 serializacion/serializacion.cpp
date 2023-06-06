#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;
int orden = 0;
bool aux=false; //Nos servira para saber si nuestro contador esta en 0 o no

class Historial
{
private:
    int indxContent = 0;
    char idList[15], nameList[35],genreList[30], descripcionList[50];


public:
    void setList(char _idList[15], char _nameList[35], char _genre[30], char _descripcionList[50]);
    void capturar();
    void mostrar();
    void buscar();
    void Modificar();
    void Eliminar();
    void Recovery();
    void ChangeCont();
} x;

int cont = 0;
void Historial::Recovery()
{
    int temp;
    ifstream Archivo("Cont.bin", ios::binary);
    if (!Archivo.good())
    {
        cout << "\nEl archivo no existe...";
        ofstream Archivo("Cont.bin", ios::binary);
        Archivo << 0;
    }
    else
    {
        Archivo >> temp;
        cont = temp;
    }
    Archivo.close();
}

void Historial::ChangeCont()
{
    ofstream temporal("temporal.bin",ios::binary);
    temporal << cont;
    temporal.close();
    remove("Cont.bin");
    rename("temporal.bin","Cont.bin");
}

void Historial::setList(char _idList[15], char _nameList[35],char _genre[30], char _descripcionList[50])
{
    strcpy(idList, _idList);
    strcpy(nameList, _nameList);
    strcpy(genreList,_genre);
    strcpy(descripcionList,_descripcionList);
}

void Historial::capturar()
{
    ifstream b("datos.bin");
    ofstream a("tempdatos.bin", ios::binary);
    for(int i = 0; i < cont; i++)
    {
        b.read((char*)&x,sizeof(x));
        a.write((char*)&x,sizeof(x));
    }

    indxContent = 0;
    char _idList[15], _nameList[35],_genreList[30],_descripcionList[50];

    cout << "AGREGAR HISTORIAL" << endl;
    cout << "Dame el ID:" << endl;
    cin.getline(_idList, 14);
    cout << "Dame el nombre de la pelicula" << endl;
    cin.getline(_nameList, 35);
    cout << "Dame el genero de la pelicula" << endl;
    cin.getline(_genreList,30);
    cout << "Dame la descripcion de la pelicula" << endl;
    cin.getline(_descripcionList,50);
    setList(_idList, _nameList,_genreList,_descripcionList);

    a.write((char *)&x, sizeof(x));
    a.close();
    b.close();
    remove("datos.bin");
    rename("tempdatos.bin","datos.bin");
    cont++;
}

void Historial::mostrar()
{
    ifstream a("datos.bin");
    if (!a.good())
        cout << "No existe el archivo" << endl;
    else
    {
        cout << "HISTORIALES EXISTENTES" << endl;
        while (!a.eof())
        {
            a.read((char *)&x, sizeof(x));
            if (a.eof())
                break;
            cout << "ID: " << x.idList << endl
                 << "Nombre: " << x.nameList << endl
                 << "Genero: " << x.genreList << endl
                 << "Descripcion: " << x.descripcionList << endl <<endl;
        }
    }
    a.close();
}

void Historial::buscar()
{
    char idListbus[14];
    int band = 0;
    ifstream a("datos.bin");
    if (!a.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "\nID a buscar!" << endl;
        cin.getline(idListbus, 14);
        while (!a.eof())
        {
            a.read((char *)&x, sizeof(x));
            if (a.eof())
            {
                break;
            }
            if (strcmp(x.idList, idListbus) == 0)
            {
                cout << " HISTORIAL ENCONTRADO" << endl;
                cout << "ID:" << x.idList << endl
                     << "Nombre: " << x.nameList << endl
                     << "Genero: " << x.genreList << endl
                     << "Descripcion: " << x.descripcionList << endl;
                band = 1;
                break;
            }
        }
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO.....";
        }
    }
    a.close();
}

void Historial::Modificar()
{
    char idListmod[15];
    int band = 0;
    int opc;
    ifstream datos("datos.bin");
    ofstream c("temp.bin",ios::binary);

    if (!datos.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "Modificar" << endl;
        cout << "\nidID a modificar!" << endl;
        cin.getline(idListmod, 14);
        while (!datos.eof())
        {
            datos.read((char *)&x, sizeof(x));
            if (datos.eof())
            {
                break;
            }
            if (strcmp(x.idList, idListmod) == 0 && band == 0)
            {
                cout << "Historial a modificar" << endl;
                cout << "ID: " << x.idList << endl
                     << "Nombre: " << x.nameList << endl
                     << "Genero: " << x.genreList << endl
                     << "Descripcion: " << x.descripcionList << endl;
                cout << "Deseas modificarlo\n"
                     << "1.-Si   2.-No" << endl;
                cin >> opc;
                cin.ignore();
                band = 1;
                if (opc == 1)
                {
                    int mod;
                    cout << "Que quiere modificar:" << endl
                         << "1.- Nombre\n2.- Genero\n3.- Descripcion"<< endl
                         << "Digite la opcion-> ";
                    cin >> mod;
                    cin.ignore();
                    switch(mod)
                    {
                        case 1: //Change name
                        char _nameList[35];
                        cout << "Dame el nuevo nombre" << endl;
                        cin.getline(_nameList, 35);
                        x.setList(x.idList, _nameList,x.genreList,x.descripcionList);
                        break;

                        case 2: //Change genre
                        char _genreList[35];
                        cout << "Dame el nuevo genero" << endl;
                        cin.getline(_genreList, 30);
                        x.setList(x.idList, x.nameList,_genreList,x.descripcionList);
                        break;

                        case 3: //Change desc
                        char _descripcionList[50];
                        cout << "Dame la nueva descripcion" << endl;
                        cin.getline(_descripcionList,50);
                        x.setList(x.idList,x.nameList,x.genreList,_descripcionList);
                        break;

                    }
                }
            }
            c.write((char *)&x, sizeof(x));
        } // while archivo
        if (band == 0)
        {
            cout << "\n NO EXISTE HISTORIAL.....";
        }
    } // else
    c.close();
    datos.close();
    remove("datos.bin");
    rename("temp.bin", "datos.bin");
}

void Historial::Eliminar()
{
    char idListeli[15];
    bool band = false;
    long int tempPos;
    ifstream a("datos.bin");
    ofstream temp("tempData.bin",ios::binary);

    if (!a.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "Historial a eliminar" << endl;
        cout << "Id a eliminar!" << endl;
        cin.getline(idListeli, 14);

        while (!a.eof())
        {
            int opc = 0;
            a.read((char *)&x, sizeof(x));
            if (a.eof())
            {
                break;
            }
            if (strcmp(x.idList, idListeli) == 0)
            {
                if (a.eof())
                    break;

                cout << "Historial a eliminar..." << endl;
                cout << "ID:" << x.idList << endl
                     << "Nombre:" << x.nameList << endl
                     << "Genero: " << x.genreList << endl
                     << "Descripcion: " << x.descripcionList << endl;
                cout << "Deseas eliminar\n"
                     << "1.-Si   2.-No";
                cin >> opc;
                band = true;
            } // if de comparacion
            if(opc == 1)
            {
                cont--;
            }
            else
            {
                temp.write((char*)&x,sizeof(x));
            }

        } // while

        if(!band)
        {
            cout << "No existe historial..." << endl;
        }

    } // else
    a.close();
    temp.close();
    remove("datos.bin");
    rename("tempData.bin","datos.bin");
    //guardando
}


int main()
{
    x.Recovery();
    int opc;
    do
    {
        system("cls");
        cout << "Selecciona una de la siguientes opciones:" << endl
             << "1.-Capturar" << endl
             << "2.-Buscar" << endl
             << "3.-Mostrar todos" << endl
             << "4.-Modificar" << endl
             << "5.-Eliminar" << endl
             << "6.- Salir" << endl
             << "Digite la opcion-> "; cin >> opc;
             cout << endl;
        cin.ignore();
        switch (opc)
        {

        case 1:
            x.capturar();

            break;

        case 2:
            x.buscar();

            break;

        case 3:
            x.mostrar();
            break;

        case 4:
            x.Modificar();
            break;

        case 5:
            x.Eliminar();
            break;
        }
        x.ChangeCont();
        getch();
        //system("pause");
    } while (opc != 6);
    return 0;
}

