#include <iostream>
#include <cstdlib>
#include <string.h>


using namespace std;

template<typename T>
class Nodo{
public:
    Nodo();
    Nodo(T,T);
    ~Nodo();
    Nodo *next;
    T id;
    T nombre;
    void print();
};
template<typename T>
Nodo<T>::Nodo()
{   id= NULL;
    nombre=NULL;
    next=NULL;
}

template<typename T>
Nodo<T>::Nodo(T id_,T nombre_ )
{
    id=id_;
    nombre=nombre_;
    next=NULL;
}
template<typename T>
void Nodo<T>::print()
{
    cout<<"Id:"<<id<<endl;
    cout<<"Nombre:"<<nombre<<endl;

}
template<typename T>
Nodo<T>::~Nodo(){}

template<class T>

class List
{
private:
    Nodo<T> *ptrHead;
    int number_nodo;
public:
        List();
        ~List();

        void add_head(T,T);
        void add_end(T,T);
        void add_sort(T,T);
        void delete_position(int);
        void print();
        void Search(T);
        void invertir();
        void ordenar();
        void buscar_pos(int pos);
        void SearchName(T);
        void DeleteAll();
        void Order();
        void modificar(int pos);
};
template<typename T>
List<T>::List()
{
    number_nodo=0;
    ptrHead=NULL;
}
 template<typename T>
 List<T>::~List(){}


template<typename T> ///INSERTAR AL INICIO
void List<T>::add_head(T id_,T nombre_)
{
    Nodo<T> *new_nodo=new Nodo<T>(id_,nombre_);
    Nodo<T> *temp = ptrHead;
    if(!ptrHead){
        ptrHead=new_nodo;
    }
    else{
        new_nodo->next=ptrHead;
        ptrHead= new_nodo;
        while(temp){
            temp=temp->next;
        }
    }
    number_nodo++;
}

template <typename T>
void List<T>::add_sort(T id_,T nombre_)
{
    Nodo<T> *new_nodo= new Nodo<T> (id_,nombre_);
    Nodo<T> *temp=ptrHead;
    if (!ptrHead){
        ptrHead=new_nodo;
    }
    else{
            if(ptrHead->id==id_){
                new_nodo->next=ptrHead;
                ptrHead=new_nodo;
            }
            else{
                while(temp->next!=NULL){
                    temp= temp->next;
                }
                new_nodo->next=temp->next;
                temp->next=new_nodo;
            }
    }
    number_nodo++;
}
template<typename T>
void List<T>::delete_position(int pos) ///BORRAR DADA UNA POSICION
{
    Nodo<T>*temp=ptrHead;
    Nodo<T>*temp1=temp->next;
    if(pos<1||pos>number_nodo){
        cout<<"Fuera de rango\n";
    }
    else if(pos==1){
        ptrHead=temp->next;
        delete temp;
        number_nodo--;
    }
    else{
        for(int i=2;i<=pos;i++){
            if(i==pos){
                Nodo<T>*aux_nodo=temp1;
                temp->next=temp1->next;
                delete aux_nodo;
                number_nodo--;
            }
            temp=temp->next;
            temp1=temp1->next;
        }
    }
}

template<typename T>
void List<T>::print() ///IMPRIMIR
{
 Nodo<T> *temp=ptrHead;
    if(!ptrHead){
        cout<<"La Agenda esta vacia\n";
 }
    else{
        while(temp){
            temp->print();
            cout<<"\n\n";
                temp=temp->next;
        }
    }

}

template<typename T>
void List<T>::SearchName(T nombre_) ///BUSCAR POR NOMBRE
{
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp){
        if(temp->nombre==nombre_){
            cout<<"Encontrado en la posicion:"<<count1<<endl;
            count2++;
        }
        temp=temp->next;
        count1++;
    }
    if(count2==0){
        cout<<"No existe el dato\n";
    }
    cout<<"\n\n";
}

template<typename T>
void List<T>::Search(T id_) ///BUSCAR POR ID
{
    Nodo<T> *temp=ptrHead;
    int count1=1,count2=0;
    while(temp){
        if(temp->id==id_){
            cout<<"Encontrado en la posicion: "<<count1<<endl;
            count2++;
        }
        temp=temp->next;
        count1++;
    }
    if(count2==0){
        cout<<"No existe el dato\n";
    }
    cout<<"\n\n";
}

template<typename T>
void List<T>::DeleteAll() ///BORRAR TODO
{
    if(ptrHead==NULL)
        cout<<"La agenda esta vacia\n";
    else{
        Nodo<T>* aux1=ptrHead;
        Nodo<T>* aux2=aux1;
        while(aux1==NULL){
            delete aux1;
            aux1=aux2->next;
            aux2=aux2->next;

        }
        ptrHead=NULL;
        number_nodo=0;
        cout<<"Se eliminaron los datos\n";
    }
}

template<typename T>  ///INVERTIR LISTA
void List<T>::invertir()
{
    Nodo<T> *anterior = NULL;
    Nodo<T> *next = NULL; //siguinte
    Nodo<T> *temporal = ptrHead;

    while (temporal) {
        next = temporal->next;
        temporal-> next = anterior;
        anterior = temporal;
        temporal = next;
    }
    ptrHead = anterior;
}

template<typename T> ///ORDENAR
void List<T>::ordenar()
{
    T dato_temporal;
    Nodo<T> *nodo_auxiliar = ptrHead;
    Nodo<T> *temporal = nodo_auxiliar;

    while (nodo_auxiliar) {
        temporal = nodo_auxiliar;

        while (temporal->next) {
            temporal = temporal->next;

            if (nodo_auxiliar->nombre > temporal->nombre) {
                dato_temporal = nodo_auxiliar->nombre;
                nodo_auxiliar->nombre = temporal->nombre;
                temporal->nombre = dato_temporal;
            }
        }
        nodo_auxiliar = nodo_auxiliar->next;
    }
}

template<typename T>
void List<T>::buscar_pos(int pos){ ///BUSCAR DADA UNA POSICION
    int band=0;
    Nodo<T> *aux=ptrHead;
    if(number_nodo==0){
        cout<< "Agenda vacia"<<endl;
    }
    else{
        if(pos<number_nodo+1 && pos>0){
            for(int i=1; i<pos; i++){
                cout<<"aux"<<i<<"="<<aux->id<<endl;
                aux=aux->next;
            }
            cout<<"ID: "<<aux->id<<endl;
            cout<<"Nombre: "<<aux->nombre<<endl;
        }
        else{
            cout<< "Posicion invalida"<<endl;
        }
    }

}

template<typename T>
void List<T>::modificar(int pos){ ///MODIFICAR DATOS

    if(ptrHead==NULL){
        cout<< "La agenda esta vacia"<<endl;
    }
    else{
        if(pos>number_nodo){
            cout<< "Posicion invalida"<<endl;
        }
        else if(pos<0){
            cout<< "Posicion invalida"<<endl;
        }
        else{
            int opc;
            string dat;
            Nodo<T> *aux1=ptrHead;
            for(int i=1; i<pos;i++){
                aux1=aux1->next;
            }
            do{
               cout<< "1.-Cambiar ID "<<endl;
               cout<< "2.-Cambiar nombre"<<endl;
               cout<<" 3.-Salir"<<endl;
               cin>>opc;
               cin.ignore();
               switch(opc){
                    case 1:{
                        cout<<"Ingresa nuevo ID: "<<endl;
                        getline(cin, dat);
                        aux1->id=dat;
                        break;
                    }
                    case 2:{
                        cout<< "Ingresa nuevo nombre: "<<endl;
                        getline(cin, dat);
                        aux1->nombre=dat;
                        break;
                    }
               }
            }while(opc!=3);
        }
    }


}

List<string> list1;
    int element,dimention,pos,dat;
    string id_ ,nombre_,correo_,numero_,direccion_,_pos;
    int opc,op;

void menu(){
    do{
            system("cls");
        cout<<"1-.Agregar contacto \n";
        cout<<"2-.Buscar contacto por su ID.\n";
        cout<<"3-.Eliminar contacto por posicion.\n";
        cout<<"4-.Buscar por posicion\n";
        cout<<"5-.Invertir\n";
        cout<<"6-.Buscar por nombre\n";
        cout<<"7-.Ordenar alfabeticamente\n ";
        cout<<"8-.Imprimir datos\n";
        cout<<"9-.Modificar\n";
        cout<<"10-.Eliminar Todo\n";
        cout<<"0-.Salir..\n";
        cout<<"Seleccione un opcion\n";
        cin>>opc;
        cin.ignore();

        switch(opc){
            case 1:{
                cout<<"ID"<<endl;
                getline(cin,id_);
                cout<<"Nombre"<<endl;
                getline(cin,nombre_);

                list1.add_head(id_,nombre_);
                list1.print();
            break;
            }

            case 2:{
            cout<<"Ingrese el ID a buscar"<<endl;
            getline(cin,id_);
            list1.Search(id_);
            break;
            }

            case 3:{
                cout<<"Ingrese la posicion a eliminar"<<endl;
                cin>>pos;
                list1.delete_position(pos);
                list1.print();
                break;
            }

            case 4:{
				cout<<"Ingrese la posicion a buscar"<<endl;
                cin>>pos;
                list1.buscar_pos(pos);
            break;
            }

            case 5:{
                list1.invertir();
                cout<<"Imprimiendo lista invertida"<<endl;
                list1.print();
            break;
            }
            case 6:{
                cout<<"Ingrese el nombre a buscar"<<endl;
                getline(cin,nombre_);
                list1.SearchName(nombre_);
            break;
            }
            case 7:{
                list1.ordenar();
                cout<<"Imprimiendo lista ordenada alfabeticamente"<<endl;
                list1.print();
            break;
            }

            case 8:{
                cout<<"Imprimiendo lista"<<endl;
                list1.print();
            break;
            }

            case 9:{
                cout<<"Ingresa la posicion del dato a modificar\n";
				cin>>dat;
                list1.modificar(pos);
            break;
            }

            case 10:{
                list1.DeleteAll();
                cout<<"Lista eliminada..."<<endl;
            break;
            }

            case 0:{
            break;
            }

        }
        cout<<"\nQue desea hacer?"<<endl;
       cout<<"1)Regresar al menu\n2)Salir"<<endl;
       cin>>op;
    }while(op!=2);

}

int main (int argc,char *argv[])
{
    menu();

    return 0;
}
