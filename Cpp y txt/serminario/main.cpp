#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"

using namespace std;


class Series_TV
{
    public:
        char nombre[10], descripcion[35], duracion[15];

    void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void menu();
}stv;

int dim1, dim2, dim3, opc = 0;


void Series_TV::Agregar()
{
    cout<<"ESCRIBE EL NOMBRE DE LA SERIE: ";
    cin.getline(nombre, 10);
    cin.getline(nombre, 10);
    cout<<"ESCRIBE LA DESCRIPCION: ";
    cin.getline(descripcion,35);
    cout<<"ESCRIBE LA DURACION EN CAPITULOS: ";
    cin.getline(duracion,15);
    ofstream Archivo("Series.txt",ios::app);
    dim1 = strlen(nombre);
    dim2 = strlen(descripcion);
    dim3 = strlen(duracion);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&nombre, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&descripcion, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&duracion, dim3);

    Archivo.close();

}
void Series_TV::Mostrar()
{
	system("cls");

    ifstream archivo("Series.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&nombre, dim1);
			nombre[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&duracion, dim3);
			duracion[dim3] = '\0';
            cout << nombre << "  " << descripcion << "  " << duracion << endl;
		}
	}
    archivo.close();
}


void Series_TV::Modificar()
{
    int band = 0;
    char nombre2[10];

	ifstream archivo("Series.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "escribe el nombre de la serie: ";
        cin.getline(nombre2, 10);
        cin.getline(nombre2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&duracion, dim3);
            nombre[dim3] = '\0';

            if(strcmp(nombre2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << duracion << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Series.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&duracion, dim3);
            duracion[dim3] = '\0';

            if(strcmp(nombre2, nombre) == 0)
            {
                cout<<"ESCRIBE EL NOMBRE DE LA SERIE: ";
                cin.getline(nombre, 10);
                cin.getline(nombre, 10);
                cout<<"ESCRIBE LA DESCRIPCION: ";
                cin.getline(descripcion,35);
                cout<<"ESCRIBA LA DURACION EN CAPITULOS: ";
                cin.getline(duracion,15);
                dim1 = strlen(nombre);
                dim2 = strlen(descripcion);
                dim3 = strlen(duracion);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&nombre, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&descripcion, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&duracion, dim3);
        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Series.txt");
	rename("temporal.txt", "Series.txt");
	}//condicional de la opcion

    }// else

}

void Series_TV::Eliminar()
{
int band = 0;
    char nombre2[10];

	ifstream archivo("Series.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "NOMBRE QUE QUIERES ELIMINAR: ";
        cin.getline(nombre2, 10);
        cin.getline(nombre2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&duracion, dim3);
            duracion[dim3] = '\0';

            if(strcmp(nombre2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << duracion << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Series.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&nombre, dim1);
            nombre[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&duracion, dim3);
            duracion[dim3] = '\0';

            if(strcmp(nombre2, nombre) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&nombre, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&descripcion, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&duracion, dim3);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Series.txt");
	rename("temporal.txt", "Series.txt");
	}//condicional de la opcion

    }//

}

void Series_TV::Buscar()
{
    char nombre2[10];
    int band = 0;
    system("cls");

    ifstream archivo("Series.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "escribe el nombre de la serie que quieres buscar: ";
        cin.getline(nombre2, 10);
        cin.getline(nombre2, 10);
		while(!archivo.eof() && !band)
        {
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&nombre, dim1);
			nombre[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&duracion, dim3);
			duracion[dim3] = '\0';
			if( strcmpi(nombre2, nombre) == 0)
            {
                cout << nombre << "  " << descripcion << "  " << duracion << endl;
                band = 1;
            }
		}
		if (!band)
            cout << "NO SE ENCUENTRA LA SERIE..." << endl;
	}
    archivo.close();
}
int main()
{

	cout<<"\n\n\t\tBIENVENIDO AL MENU DE SERIES\n\n";
	do{
		cout<<"\n\tSELECCIONE LA OPCION DESEADA\n1.- AGREGAR\n2.- MOSTRAR\n3.- BUSCAR\n4.- MODIFICAR\n5.- ELIMINAR\n6.- SALIR\n>: ";
		cin>>opc;
		switch(opc) {
		  case 1:
			stv.Agregar();
			break;
		  case 2:
			stv.Mostrar();
			break;
          case 3:
			stv.Buscar();
			break;
		  case 4:
            stv.Modificar();
			//empleado.Datos();
			break;
          case 5:
			stv.Eliminar();
			break;
          default:
            cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opc != 6);
}
