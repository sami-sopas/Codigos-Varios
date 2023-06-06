#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;
int orden = 0;
bool aux=false; //Nos servira para saber si nuestro contador esta en 0 o no

class Lista
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
    void Mostrar_Indice();
    void Recovery();
    void ChangeCont();
} x;

class Indice
{
public:
    char idList[14];
    long int pos;

} y;

int cont = 0;
void Lista::Recovery()
{
    int temp;
    ifstream Archivo("Cont.txt", ios::app);
    if (!Archivo.good())
    {
        cout << "\nEl archivo no existe...";
        ofstream Archivo("Cont.txt", ios::app);
        Archivo << 0;
        return;
    }
    else
    {
        Archivo >> temp;
        cont = temp;
    }
    Archivo.close();
}

void Lista::setList(char _idList[15], char _nameList[35],char _genre[30], char _descripcionList[50])
{
    strcpy(idList, _idList);
    strcpy(nameList, _nameList);
    strcpy(genreList,_genre);
    strcpy(descripcionList,_descripcionList);
}

void Lista::capturar()
{
    indxContent = 0;
    char _idList[15], _nameList[35],_genreList[30],_descripcionList[50];
    cout << "Dame el ID:" << endl;
    cin.getline(_idList, 14);
    cout << "Dame el nombre de la pelicula" << endl;
    cin.getline(_nameList, 35);
    cout << "Dame el genero de la pelicula" << endl;
    cin.getline(_genreList,30);
    cout << "Dame la descripcion de la pelicula" << endl;
    cin.getline(_descripcionList,50);
    setList(_idList, _nameList,_genreList,_descripcionList);
    ofstream a("datos.txt", ios::app);
    if(cont){
        y.pos = y.pos + sizeof(x);
    }else{
        y.pos = a.tellp();
    }
    a.write((char *)&x, sizeof(x));
    a.close();
    strcpy(y.idList, idList);
    ofstream b("indice.txt", ios::app);
    b.write((char *)&y, sizeof(y));
    b.close();
    orden++;
    cont++;
}

void Lista::mostrar()
{
    ifstream a("datos.txt");
    if (!a.good())
        cout << "No existe el archivo";
    else
    {
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

void Lista::buscar()
{
    char idListbus[14];
    int band = 0;
    ifstream b("indice.txt");
    if (!b.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "\nID a buscar!" << endl;
        cin.getline(idListbus, 14);
        while (!b.eof())
        {
            b.read((char *)&y, sizeof(y));
            if (b.eof())
            {
                break;
            }
            if (strcmp(y.idList, idListbus) == 0)
            {
                ifstream a("datos.txt");
                a.seekg(y.pos, ios::beg);
                a.read((char *)&x, sizeof(x));
                cout << "ID:" << x.idList << endl
                     << "Nombre: " << x.nameList << endl
                     << "Genero: " << x.genreList << endl
                     << "Descripcion: " << x.descripcionList << endl;
                a.close();
                band = 1;
                break;
            }
        }
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO.....";
        }
    }
    b.close();
}

void Lista::Modificar()
{
    char idListmod[15];
    int band = 0;
    int opc;
    ifstream indice("indice.txt");
    ifstream datos("datos.txt");
    ofstream c("temp.txt", ios::app);
    ofstream d("tempind.txt", ios::app);
    if (!indice.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "\nidList a modificar!" << endl;
        cin.getline(idListmod, 14);
        while (!indice.eof())
        {

            indice.read((char *)&y, sizeof(y));
            datos.read((char *)&x, sizeof(x));
            if (indice.eof())
            {
                break;
            }
            if (strcmp(y.idList, idListmod) == 0 && band == 0)
            {
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
            strcpy(y.idList, idList);
            d.write((char *)&y, sizeof(y));
        } // while archivo
        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO.....";
        }
    } // else
    d.close();
    c.close();
    indice.close();
    datos.close();
    remove("indice.txt");
    rename("tempind.txt", "indice.txt");
    remove("datos.txt");
    rename("temp.txt", "datos.txt");
}

void Lista::Eliminar()
{
    char idListeli[15];
    int band = 0;
    int opc, cont1 = 0, cont2 = 0;
    long int tempPos;
    ifstream b("indice.txt");
    if (!b.good())
    {
        cout << "No existe el archivo";
    }
    else
    {
        cout << "\nidList a eliminar!" << endl;

        cin.getline(idListeli, 14);
        while (!b.eof())
        {
            b.read((char *)&y, sizeof(y));
            cont1++;
            if (b.eof())
            {
                break;
            }
            if (strcmp(y.idList, idListeli) == 0)
            {
                ifstream a("datos.txt");
                a.seekg(y.pos, ios::beg);
                a.read((char *)&x, sizeof(x));
                if (a.eof())
                    break;

                cout << "ID:" << x.idList << endl
                     << "Nombre:" << x.nameList << endl
                     << "Genero: " << x.genreList << endl
                     << "Descripcion: " << x.descripcionList << endl;
                cout << "Deseas eliminar\n"
                     << "1.-Si   2.-No";
                cin >> opc;
                band = 1;
                tempPos = y.pos;
                a.close();
                break;
            } // if de comparacion

        } // while
        b.close();

        if (opc == 1)
        {
            ifstream indice("indice.txt");
            ifstream datos("datos.txt");
            while (!indice.eof())
            {
                indice.read((char *)&y, sizeof(y));
                datos.read((char *)&x, sizeof(x));
                if (indice.eof())
                {
                    break;
                }
                if (strcmp(y.idList, idListeli))
                {
                    cont2++;
                    ofstream c("temp.txt", ios::app);
                    c.write((char *)&x, sizeof(x));

                    strcpy(y.idList, idList);
                    if (tempPos< y.pos)
                    {
                        y.pos = y.pos - sizeof(x);
                    }
                    ofstream d("tempind.txt", ios::app);
                    d.write((char *)&y, sizeof(y));
                    d.close();
                    c.close();
                }
            } // while archivo
            indice.close();
            datos.close();
            remove("indice.txt");
            rename("tempind.txt", "indice.txt");
            remove("datos.txt");
            rename("temp.txt", "datos.txt");
        } // if
        else
        {
        }

        if (band == 0)
        {
            cout << "\n NO EXISTE REGISTRO.....";
        }

    } // else
    cont--;
}

void Lista::Mostrar_Indice()
{
    ifstream a("indice.txt");
    if (!a.good())
        cout << "No existe el archivo";
    else
    {
        while (!a.eof())
        {
            a.read((char *)&y, sizeof(y));
            if (a.eof())
                break;
            cout << "idList:" << y.idList << endl
                 << "Posicion de Registro: "<< y.pos<<endl<<endl;
        }
    }
    a.close();
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
             << "6.-Mostrar Indice" << endl
             << "7.- Salir" << endl
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

        case 6:
            x.Mostrar_Indice();
            break;
        }
        getch();
    } while (opc != 7);
    return 0;
}

