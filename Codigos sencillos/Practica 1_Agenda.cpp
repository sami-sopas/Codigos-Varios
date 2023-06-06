//Samuel Osvaldo Ramirez Cuenca
#include <iostream> //libreria

using namespace std;

struct agenda{
	int id;
	char nombre[30];
	char direccion[30];
	char email[30];
	char telefono[10];
}lista[5]; //Tamaño de lista

int index=0;

void RegistrarContacto()
{
     	lista[index].id=index+1;
		cout<<"Ingrese nombre: "<<endl;
		cin>>lista[index].nombre;
		cout<<"Ingrese direccion: "<<endl;
		cin>>lista[index].direccion;
		cout<<"Ingrese email: "<<endl;
		cin>>lista[index].email;
		cout<<"Ingrese telefono: "<<endl;
		cin>>lista[index].telefono;
		index++;
}

int BuscarContacto(int id)
{
	int posicion=-1,x=0;
	bool ban=false;
	while(x<5 && ban==false){
		if(id==lista[x].id){
		  ban=true;
		  posicion=x;	
		}
		x++;
	}
	return posicion;
}

void MostrarContacto(int pos)
{
		cout<<"nombre: "<<lista[pos].nombre<<endl;
		cout<<"direccion: "<<lista[pos].direccion<<endl;
		cout<<"email: "<<lista[pos].email<<endl;
		cout<<"telefono: "<<lista[pos].telefono<<endl<<endl;
}

void EditarContacto(int pos)
{
		cout<<"Ingrese nombre: \n";
		cin>>lista[pos].nombre;
		cout<<"Ingrese direccion: \n";
		cin>>lista[pos].direccion;
		cout<<"Ingrese email: \n";
		cin>>lista[pos].email;
		cout<<"Ingrese telefono: \n";
		cin>>lista[pos].telefono;
}

void BorrarContacto(int pos)
{
	cout<<"Contacto eliminado\n";
	for (int i=pos; i<=index; i++){	
    lista[i-1] = lista[i];
    lista[i-1].id = i;}
	index--;
}

void menu()
{
	int opcMenu=0,id=0;
	cout<<"Agenda\n\n";
	cout<<"1) Registro Contacto\n";
	cout<<"2) Buscar Contacto\n";
    cout<<"3) Editar Contacto\n";
	cout<<"4) Eliminar Contacto\n";
	cout<<"5) Salir\n\n";
	cout<<"Seleccione una opcion\n";
	cin>>opcMenu;
	switch(opcMenu)
	{
		case 1: RegistrarContacto();
			break;
		case 2:
		{
				cout<<"Ingrese el ID que desea buscar"<<endl;
	            cin>>id;
			    MostrarContacto(BuscarContacto(id));
			    break;
		}
		case 3:
		{
				cout<<"Ingrese el ID que desea editar"<<endl;
	        	cin>>id;
				EditarContacto(BuscarContacto(id));
			break;
		}
		case 4:
		{
				cout<<"Ingrese el ID que desea eliminar"<<endl;
				cin>>id;
				BorrarContacto(id);
			break;
		}
		case 5:
		{
				cout<<"Finalizando programa..."<<endl;
			break;
		}
		default:
		{
			cout<< "Seleccione una opcion correcta"<<endl;
			break;
		}
	}
}

int opc=0;
int main(int argc, char** argv) {
	do{
		system("cls");
		menu();
		cout<<"Para continuar escriba 1\nPara salir escriba 2"<<endl;
		cin>>opc;
	}while(opc!=2);
	return 0;
}
