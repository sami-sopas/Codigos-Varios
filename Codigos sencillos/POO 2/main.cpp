///Ramirez Cuenca Samuel Osvaldo_Entregable 3

///Librerias del sistema------
#include <iostream>
///Librerias del proyecto-----
#include"album.h"
#include"interprete.h"

using namespace std;

void menu(){
    ///Instanciando los tipos de datos abstractos (objetos)
    Album a1;
    Interprete aux;
    //Variables auxiliares con las que se setearan los datos
    string auxiliar;
    int entero;
    float precio;
    //Variable para el menu
    int opc=0;

        cout<<"--------Registro de Albumes--------"<<endl;
        cout<<"1)Registrar Album"<<endl;
        cin>>opc;
        cin.sync();

        switch(opc){
            case 1:{
        ///Ingresando datos ---------------------------------

        cout<<"Ingrese el nombre del album: \n";
        getline(cin,auxiliar); ///Funcion parecida al cin >>. Pero esta es la mejor al momento de leer strings

        a1.setNombre(auxiliar); ///Una vez leida esa cadena, esta se envia y se setea en el objeto en el campo nombre

        cout<<"El interprete es un solista o una banda?"<<endl;
        cout<<"1)Solista\n2)Banda"<<endl;
        cin>>opc;
        cin.ignore(); ///Esta funcion permite que no se pase a la siguiente opcion. Hasta que ingrese un numero

        /**Se le da a elegir al usuario si el interprete del album sera un solista
           o una banda. dependiendo de la opcion sucede lo siguiente**/

        if(opc==1){
                ///aux es la instancia del objeto Interprete. se setea segun la opcion
                cout<<"Ingrese el nombre del solista: "<<endl;
                getline(cin,auxiliar);
                aux.setSolista(auxiliar);
        }else{
        cout<<"Ingrese el nombre de la banda: "<<endl;
        getline(cin,auxiliar);
        aux.setBanda(auxiliar);}

        /**Se le envia el Objeto Interprete (aux) para setearlo en el Objeto Album (a1)**/
        a1.setInterprete(aux);

        cout<<"Ingrese el anio: \n";
        cin>>entero;       /** En este caso se ingresa un entero. asi que se usa cin en vez de getline
                                de la misma manera, este se envia para ser asignado al objeto **/
        a1.setAnio(entero);

        cout<<"Ingrese la cantidad disponible de albumes: \n";
        cin>>entero;
        a1.setCantidad(entero);

        cout<<"Ingrese el precio: \n";
        cin>>precio;
        a1.setPrecio(precio);

        ///Imprimiendo datos ---------------------------------------

         //Interprete aux2 = a1.getInterprete();

        cout<<"\nImprimiendo datos...\n";
        cout<<"Nombre: "<<a1.getNombre()<<endl;
        if(opc==1){
                cout<<"Interprete: "<<aux.getSolista()<<endl;
        }
        else{
                cout<<"Interpretes: "<<aux.getBanda()<<endl;
        }
        cout<<"Anio: "<<a1.getAnio()<<endl;
        cout<<"Cantidad disponible: "<<a1.getCantidad()<<endl;
        cout<<"Precio: "<<a1.getPrecio()<<endl;
        break;
            }
         default:{
         cout<<"Ingrese una opcion valida"<<endl;
        break;}
    }
}


int main()
{
    int opc=0; ///Ciclo do-while para estar ejecutando el menu. Asi como para preguntar si desea continuar o salir
    do{
        system("cls");
        menu();
        cout<<"\n1)Continuar\n2)Salir"<<endl;
        cin>>opc;
    }while(opc!=2);

   return 0;
}

