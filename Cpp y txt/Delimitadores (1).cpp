#include <iostream>
#include <fstream> // TIENE FUNCIONES DE LECTURA Y ESCRITURA DENTRO DEL ARCHIVO
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* cin>> // lectura de numeros
   cin.getline(cadena, longitud) // para leer tipos de datos char
   getline(cin, cadena) // para leer tipos de datos string
*/

using namespace std;

class Peliculas
{
public:
    char nombre[64], descripcion[500], categoria[15],puntuacion[10]; //ARREGLOS UNIDIMENSIONALES
    void Capturar(); //METODOS
    void Mostrar();
    void Buscar();
    void Eliminar();
    void Modificar();
}p;


/////METODO CAPTURAR
void Peliculas::Capturar() // DE LA CLASE ALUMNO PERTENECE CAPTURAR ESO SIGNIFICAN LOS DOS PUNTOS
{
    cout<<"Dame el nombre de la pelicula: ";
    cin.getline(nombre, 10);
    cin.getline(nombre, 10); //EN LUGAR DE FFLUSH X QUE NO SIRVE CON GETLINE PARA LEER CADENAS
    cout<<"Dame la descripcion: ";
    cin.getline(descripcion,500);
    cout<<"Dame el categoria: ";
    cin.getline(categoria,15);
    cout<<"Dame la puntuacion: ";
    cin.getline(puntuacion,15);

    ofstream Archivo("Prodauto.txt",ios::app); // ofstream crea un objeto para escritura en el archivo llamado "Archivo", ios::app = entrada y salida de datos
    Archivo<<nombre<<'|'<<descripcion<<'|'<<categoria<<'|'<<puntuacion<<'|'; // se escribiendo en el archivo creado campo por campo separado por el delimitador '|'
    Archivo.close(); // cerrar el archivo
}

//////METODO MOSTRAR
void Peliculas::Mostrar()
{
    int i;
    ifstream Lectura("Prodauto.txt"); // abrir archivo en formato de lectura, "Lectura" que es un objeto
    if(!Lectura.good()) // good ( libreria fstream) nos verifica si hubo problema al abrir el archivo a traves de true o false
    {
        cout<<"No existe el archivo\n";
        system("pause");
    }
    else
    {
        while(!Lectura.eof()) // eof = end of file
        {
            //Lectura de la variable user
            i=0;
            do
            {
                Lectura.read((char *)&nombre[i],1); //leo el objeto de tipo char, lo asigno a la variable user en la posicion que tenga el subindice, y se lee de caracter en carácter
                if(Lectura.eof())
                    break;
                    i++;
            }while(nombre[i-1]!='|'); // mientras user en la posicion del subindice menos 1 sea diferente al delimitador, sigues escribiendo en el arreglo "user"
            nombre[i-1]='\0'; // si no se cumple el while anterior, entonces escribe en la posicion del delimitador '\0' que significa final de la cadena para saber que se termino ese campo "user"
            //Lectura de la variable pass
            i=0;
            do
            {
                Lectura.read((char *)&descripcion[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(descripcion[i-1]!='|');
            descripcion[i-1]='\0';
            //Lectura de la variable nom
            i=0;
            do
            {
                Lectura.read((char *)&categoria[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(categoria[i-1]!='|');
            categoria[i-1]='\0';

            do
            {
                Lectura.read((char *)&puntuacion[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(puntuacion[i-1]!='|');
            puntuacion[i-1]='\0';

            //Lectura de la variable ape

            if(Lectura.eof())
                break;

            //Imprimes valores
            cout<<endl<<"\nnombre: "<<nombre<<endl<<"\nDescripcion: "<<descripcion<<endl<<"\ncategoria: "<<categoria<<endl<<"\npuntuacion: "<<puntuacion<<endl<<"\n"; // endl=salto de linea
            if(Lectura.eof())
                break;
        }
        system("pause");
    }
    Lectura.close(); // cierras el archivo a traves del objeto "Lectura"
}
/* PARA BUSCAR POR CUALQUIER ATRIBUTO O VARIABLE SE TIENE QUE RECORRER TODOS LOS CAMPOS DEL REGISTRO CARACTER POR CARACTER */
void Peliculas::Buscar(){
    int b;  b = 0; // Bandera
    int i; // Contador
    int iguales;
    char caracter;
    char alubus[10];


    ifstream arc("Prodauto.txt");/* Abrimos el archivo */
    if(!arc.good())   /* Verificamos si el archivo existe */
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }

    else{
        cout<<"\n Escribe el nombre del producto a buscar: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);


        while(!arc.eof()){
            i = 0;
            do{ // ciclo para leer cada uno de los campos
                arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                if(caracter!='|')
                {
                    nombre[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                    i++;
                }

            }while(caracter != '|');

            nombre[i]= '\0'; // Finaliza la cadena despues del fin del atributo

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                   descripcion[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            descripcion[i]= '\0';


            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                {
                    categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
            categoria[i]= '\0';




            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(nombre,alubus);

            if(iguales == 0){
                cout<<"\n nombre: " <<nombre <<"\n DESCRIPCION: " <<descripcion <<"\n categoria: " <<categoria<<"\npuntuacion: "<<puntuacion<<endl<<"\n";
                b = 1; // Activamos la bandera
                break;
            }
        }

        if( b == 0){
            cout<<"\n\n NO EXISTE EL REGISTRO... \n\n";
        }
        arc.close();
    }
}

void Peliculas::Eliminar(){
    int b = 0; // Bandera
    int i; // Contador
    int iguales,respuesta; respuesta = 0;
    char caracter;
    char alubus[10];


    ifstream arc("Prodauto.txt"); /* Abrimos el archivo */
    if(!arc.good())   /* Verificamos si el archivo existe */
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }
    else{
        cout<<"\n Escribe el nombre del producto: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);

        while(!arc.eof()){
            i = 0;
            do{ // ciclo para leer cada uno de los campos
                arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                if(caracter!='|')
                {
                    nombre[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                    i++;
                }

            }while(caracter != '|');

            nombre[i]= '\0'; // Finaliza la cadena despues del fin de la cadena

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    descripcion[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            descripcion[i]= '\0';

            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                {
                    categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
            categoria[i]= '\0';


            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(nombre,alubus); // COMPARACION DE LOS CAMPOS 0 ES VERDADERO

            if(iguales == 0){
                cout<<"\n nombre: " <<nombre <<"\n DESCRIPCION: " <<descripcion <<"\n categoria: " <<categoria<<"\npuntuacion: "<<puntuacion<<endl<<"\n";
                b = 1; // Activamos la bandera            }
        }


        }
        arc.close();
        }

        if(b == 0) {
            cout<<"\n\n EL REGISTRO NO EXISTE \n\n";
        }
        if(b == 1){

            cout<<"\n Escribe 1 si deseas eliminar este registro: ";

            cin>>respuesta;

            if(respuesta == 1){
                ifstream arc ("Prodauto.txt"); // Abrimos el archivo de datos
                ofstream temporal ("temporalauto.txt",ios::app); // Creamos el archivo temporal

                while(!arc.eof()){
                    i = 0;
                    do{ // ciclo para leer cada uno de los campos
                        arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                        if(caracter!='|')

                        {
                            nombre[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                            i++;
                        }

                    }while(caracter != '|');
                    nombre[i]= '\0'; // Finaliza la cadena despues del fin de la cadena

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')
                        {

                            descripcion[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    descripcion[i]= '\0';

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                        {
                            categoria[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
                    categoria[i]= '\0';



                   if(arc.eof())
                    {
                        break;
                    }

                    iguales = strcmp(nombre,alubus);
                    if(iguales != 0){
                        temporal <<nombre<<"|"<<descripcion<<"|"<<categoria<<"|"<<puntuacion<<"|";

                    }
                } // while

                arc.close();
                temporal.close();
                remove("Prodauto.txt");
                rename("temporalauto.txt","Prodauto.txt");
                cout<<"\n\n EL REGISTRO FUE ELIMINADO... \n\n";
                b = 1;
            } // if

            else {
                cout<<"\n EL REGISTRO NO FUE ELIMINADO... \n\n";
            }

        }


}

void Peliculas::Modificar()
{
    int i;//contador
    int opcion;
    char prodMod[10];
    bool b;

    ifstream Lectura("Prodauto.txt");/* Abrimos el archivo */
    ofstream LecturaTemporal("temporalauto.txt",ios::app);

    if(!Lectura.good())
        cout<<"\n EL REGISTRO NO EXISTE \n ";
    else
    {
        cout<<"\n Introduce el nombre a modificar :  ";
        cin.getline(prodMod,10);
        cin.getline(prodMod,10);

        b = false;

        while(!Lectura.eof()){

            i=0;
            do{
                Lectura.read((char*)&nombre[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(nombre[i-1]!='|');
            nombre[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;


            i=0;
            do{
                Lectura.read((char*)&descripcion[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(descripcion[i-1]!='|' && !Lectura.eof());
            descripcion[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;


            //NOMBRE
            i=0;
            do{// ciclo para leer cada uno de los campos
                Lectura.read((char*)&categoria[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(categoria[i-1]!='|');
            categoria[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;

            if(strcmp(nombre,prodMod)==0 && !b)
            {
                cout<<endl<<"\n  nombre : "<<nombre<<endl<<"\n  Descripcion : "<<descripcion<<endl<<"\n  categoria : "<<categoria<<endl<<"\n puntuacion: " <<puntuacion<<endl;
                cout <<"\n 1) Que desea realiza ?\n ";
                cout <<"\n 1) Modificar nombre: ";
                cout <<"\n 2) Modificar Descripcion: ";
                cout <<"\n 3) Modificar categoria: ";
                cout <<"\n 4) Regresar: ";

                cout<<"\n   Elige la opcion a realizar: ";
                cin>>opcion;


                switch(opcion) ///switch para realizar las modificaciones
                {
                    case 1:///////nombre del alumno
                        cout<<"\n nombre del Producto : ";
                        cin.getline(nombre,10);
                        cin.getline(nombre,10);
                        break;
                    case 2://////apellido
                        cout<<"\n Descripcion : ";
                        cin.getline(descripcion,35);
                        cin.getline(descripcion,35);
                        break;
                    case 3:///correo electronico
                        cout<<"\n categoria : ";
                        cin.getline(categoria,15);
                        cin.getline(categoria,15);
                        break;
                    default: cout<<"\n No se encontro la opcion ";
                }

                if(opcion!=6 && opcion>0 && opcion<7)
                    b = true;
            }
            LecturaTemporal<<nombre<<'|'<<descripcion<<'|'<<categoria<<'|'<<puntuacion<<'|';
        }
        Lectura.close();
        LecturaTemporal.close();
        if(!b)
            cout<<"\n No se encontro arhcivo ";

        remove("Prodauto.txt");
        rename("temporalauto.txt","Prodauto.txt");
    }
}


int main(){
    int opc;
    do{
        cout<<"\n 1.- CAPTURAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6-SALIR \n\n SELECCIONA LA OPCION (1-5): ";
        cin>>opc;
        switch(opc){
            case 1: p.Capturar();
                break;

            case 2: p.Mostrar();
                break;

            case 3: p.Buscar();
                break;

            case 4: p.Eliminar();
                break;

            case 5: p.Modificar();
                break;
        }

    }while(opc!=6);
}
