#include"Movie.h"

using namespace std;

Movie::Movie()
{

}

Movie::Movie(const Movie& m):name(m.name),category(m.category),clasification(m.clasification),points(m.points)
{

}

void Movie::setName(const std::string& n)
{
    name = n;
}

void Movie::setCategory(const std::string& c)
{
    category = c;
}

void Movie::setClasification(const std::string& t)
{
    clasification = t;
}

void Movie::setPoints(const int& p)
{
    points = p;
}

string Movie::getName()
{
    return name;
}

string Movie::getCategory()
{
    return category;
}

string Movie::getClasification()
{
    return clasification;
}

int Movie::getPoints()
{
    return points;
}

///METODO CAPTURAR
void Movie::capturar(Movie& movie)
{
    string myString;
    int n;

    cout << "Dame el nombre" << endl;
    getline(cin,myString);
    cin.ignore();

    movie.setName(myString);

    cout << "Dame la categoria" << endl;
    getline(cin,myString);
    cin.ignore();

    movie.setCategory(myString);


    cout << "Dame la clasificacion" << endl;
    getline(cin,myString);
    cin.ignore();

    movie.setClasification(myString);

    cout << "Dame la puntuacion" << endl;
    cin >> n;

    movie.setPoints(n);

    cout << "Pelicula agregada correctamente" << endl;

    ofstream Archivo("Producto.txt",ios::app); // ofstream crea un objeto para escritura en el archivo llamado "Archivo", ios::app = entrada y salida de datos
    Archivo<<movie.getName()<<'|'<<movie.getCategory()<<'|'<<movie.getClasification()<<'|'<<to_string(movie.getPoints()) <<'|'; // se escribiendo en el archivo creado campo por campo separado por el delimitador '|'
    Archivo.close(); // cerrar el archivo

    system("pause");
}

///METODO IMPRIMIR
void Movie::imprimir(Movie& movie)
{

    int i;
    ifstream Lectura("ProdUCTO.txt"); // abrir archivo en formato de lectura, "Lectura" que es un objeto
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
                Lectura.read((char *)&codigo[i],1); //leo el objeto de tipo char, lo asigno a la variable user en la posicion que tenga el subindice, y se lee de caracter en carácter
                if(Lectura.eof())
                    break;
                    i++;
            }while(codigo[i-1]!='|'); // mientras user en la posicion del subindice menos 1 sea diferente al delimitador, sigues escribiendo en el arreglo "user"
            codigo[i-1]='\0'; // si no se cumple el while anterior, entonces escribe en la posicion del delimitador '\0' que significa final de la cadena para saber que se termino ese campo "user"
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
                Lectura.read((char *)&precio[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(precio[i-1]!='|');
            precio[i-1]='\0';
            //Lectura de la variable ape

            if(Lectura.eof())
                break;

            //Imprimes valores
            cout<<endl<<"\nCodigo: "<<codigo<<endl<<"\nDescripcion: "<<descripcion<<endl<<"\nPrecio: "<<precio<<endl<<"\n"; // endl=salto de linea
            if(Lectura.eof())
                break;
        }
        system("pause");
    }
    Lectura.close(); // cierras el archivo a traves del objeto "Lectura"
}

void Movie::buscar(Movie& movie)
{

}

void Movie::modificar(Movie& movie)
{

}

void Movie::eliminar(Movie& movie)
{

}

Movie& Movie::operator=(const Movie& m)
{
    name = m.name;
    category = m.category;
    clasification = m.clasification;
    points =m.points;

    return *this;

}
