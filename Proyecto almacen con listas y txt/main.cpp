#include <iostream>
///Librerias para numeros random-----
#include <random>
#include <chrono>
#include <functional>
///----------------------------------
#include"Product.h"
#include "admin.h"
#include "seller.h"
#include"LDLCCED.h"

using namespace std;

    default_random_engine generador(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribucion(10000, 99999);
    auto randomNum = bind(distribucion, generador);

void displayMenu();
void interfazAdmin();
void interfazVendedor();

void registrarProducto();
void buscarProducto();
void venderProducto();
void modifyInventory();
void recoverPreviousInventory();

bool validacion(char*);

Product producto;
Admin admin;
Seller seller;
List<Product> lista;
fstream myFile;

int main()
{
    recoverPreviousInventory();
    displayMenu();
    return 0;
}

void displayMenu(){
    char myChar[50];
    int opc,attempts=3;
    int myInt;

    cout << "¿Quien eres?" << endl;
    cout << "1) Administrador" << endl;
    cout << "2) Vendedor" << endl;
    cin >> myChar;
    if(validacion(myChar)){
    opc=atoi(myChar);

    if(opc == 1){
        while(attempts>0){              ///Para que se repita hasta que se quede sin intentos
        do{
        cout<<"Ingrese la contraseña";
        cin>>myChar;
        }while(!validacion(myChar));

        myInt=atoi(myChar);
        cout<<"La contraseña: " <<myInt<< "es: ";
        if(admin.getPassword()==myInt){ ///Si está bien la contraseña, lo lleva a la interfaz
        cout<<"correcta"<<endl;
        interfazAdmin();
        }else{
        cout<<"incorrecta: "<<endl;
        attempts--;                 ///Si está mal, le quita un intento
        cout<<"Le quedan "<<attempts<<" intentos"<<endl;
        }

        }
        if(attempts==0){             ///Si se queda sin intentos, lo dejamos trabado 5 minutos por *IMBECIL*

        }
    }else{
        interfazVendedor();
    }
}
}

void interfazAdmin(){
    int opc;
    char myChar[50];

    do{
    system("cls");
    cout << "Que desea hacer?" << "\n"
            "1) Registrar producto " << "\n"
            "2) Buscar un producto" << "\n"
            "3) Imprimir lista" << "\n"
            "4) O" << endl;

            cin >> myChar;

            if(!validacion(myChar)){

            }else{
            opc=atoi(myChar);
            switch(opc){
                case 1: registrarProducto(); ///Insertar en la lista
                    break;

                case 2: buscarProducto();
                    break;

                case 3:
                    cout << "EL CONTENIDO DE LA LISTA ES: " << endl;
                    cout<<lista.toString();///Imprimir lista
                    break;

                case 4:
                    break;


            }
            }
        do
        {cout << "Que deseas hacer? \n1)Continuar \n2)Salir" << endl;
        cin >> myChar;}
        while(!validacion(myChar));
        opc=atoi(myChar);

    }while(opc!=2);

}

void interfazVendedor(){
    int opc;
    char myChar[50];

    do{
    system("cls");
    cout << "Que desea hacer?" << "\n"
            "1) Vender producto " << "\n"
            "2) Consultar productos" << "\n";
            cin >> myChar;

            if(!validacion(myChar)){

            }else{
            opc=atoi(myChar);
            switch(opc){
                case 1: venderProducto();
                    break;

                case 2: cout << "EL CONTENIDO DE LA LISTA ES: " << endl;
                    cout<<admin.getInventory();///Imprimir el inventario (Está en el TXT)
                    break;

                case 3:
                    break;


            }
            }
        do
        {cout << "Que deseas hacer? \n1)Continuar \n2)Salir" << endl;
        cin >> myChar;}
        while(!validacion(myChar));
    opc=atoi(myChar);
    }while(opc!=2);

}

void registrarProducto(){
    string auxiliar;
    float precio;
    int cantidad;

    producto.setCode(randomNum());

    cout << "Ingrese nombre" << endl;
    cin.sync();
    getline(cin,auxiliar);
    producto.setName(auxiliar);

    cout << "Ingrese categoria" << endl;
    getline(cin,auxiliar);
    producto.setCategory(auxiliar);

    cout << "Ingrese precio" << endl;
    cin >> precio;
    producto.setPrice(precio);

    cout << "Ingrese cantidad" << endl;
    cin >> cantidad;

    producto.setAmount(cantidad);

    cout << "Su producto quedo asi:" << endl;
    cout << producto;

    /*hacer que el id sea random */

    lista.insertData(lista.getLastPos(),producto); ///Insertamos los datos a la lista
    string inventory=lista.toString();
    admin.setInventory(inventory);
}

void buscarProducto(){
    char myChar[50];
    int aux;

    do{
    cout<<"Ingrese el codigo del producto";
    cin>>myChar;
    }while(!validacion(myChar));
    aux=atoi(myChar);
    producto.setCode(aux);
    producto=lista.retrieve(lista.findData(producto));

    cout<<producto;



}

void venderProducto(){
    char myChar[50];
    int aux;

    do{
    cout<<"Ingrese el codigo del producto";
    cin>>myChar;
    }while(!validacion(myChar));
    aux=atoi(myChar);
    producto.setCode(aux);
    producto=lista.retrieve(lista.findData(producto));

    do{
    cout<<"Ingrese la cantidad a vender";
    cin>>myChar;
    }while(!validacion(myChar));
    aux=atoi(myChar);

    if(producto.getAmount()<aux){
        cout<<"Imposible de realizar la venta, no hay producto suficiente";
    }else{
    producto.setAmount(producto.getAmount()-aux);
    seller.registerSale(producto,aux);

    modifyInventory();

    }
}

void modifyInventory(){
    string inventory=lista.toString();
    admin.setInventory(inventory);

}

void recoverPreviousInventory(){
    string name,category,price,code,amount;
    myFile.open("Inventory.txt",ios::in);

    if(myFile.is_open()){
        while(!myFile.eof()){
            getline(myFile,code,'|');
            getline(myFile,name,'|');
            getline(myFile,category,'|');           ///LEEMOS LOS DATOS DEL ARCHIVO
            getline(myFile,amount,'|');
            getline(myFile,price,'|');

            producto.setName(name);
            producto.setCategory(category);
            producto.setPrice(stof(price));     ///LOS DATOS DEL ARCHIVO LOS ASIGNAMOS AL OBJETO
            producto.setCode(stoi(code));           ///STOI PARA CONVERTIR STRING EN INT
            producto.setAmount(stoi(amount));       ///STOF PARA CONVERTIR STRING EN FLOAT


            lista.insertData(lista.getLastPos(),producto);
        }
        myFile.close();
    }

}


bool validacion(char *abc){
   bool isValid=false;
    if(int(*abc)>=48 && int(*abc)<=57){
    isValid=true;
}
return isValid;
}
