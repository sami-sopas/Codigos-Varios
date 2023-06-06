#include <iostream>
#include <cstdlib>
#include<limits>

using namespace std;

bool verificar_dato(bool *dir_flag){
	if(!cin.good() ){
		cin.clear();
		cin.ignore(numeric_limits<int>::max(), '\n');
		*dir_flag = true;
		cout<<"Dato incorrecto"<<endl;
	}
}
int vacia(int cont){
	if(cont<1){
		system("cls");
		cout<<"LA PILA ESTA VACIA"<<endl;
		return -1;
	} else{
		return 0;
	}
}


class Nodo{
  public:
    int value;
    Nodo* next;
};

void push(Nodo *&pila, int n){
  Nodo *temp = new Nodo();
  temp->value = n;
  temp->next = pila;
  pila = temp;
};

void pop(Nodo *&pila, int cont){
  Nodo *temp = pila;
  pila = temp->next;
  delete(temp);
};

void display(Nodo *&pila, int cont){
  Nodo *temp = pila;
  int cont1;
  int i=201,i1=205,i2=187,i3=186,i4=204,i5=185,i6=200,i7=188;
  char a,b,c,d,e,f,g,h;
  a=i;
  b=i1;
  c=i2;
  d=i3;
  e=i4;
  f=i5;
  g=i6;
  h=i7;
		if(vacia(cont)==-1){
			vacia(cont);
		}else{
 		cont1=0;
 	    cout<<"\t\t"<<a<<b<<b<<b<<c<<endl;
	    printf("Tope->");
        while(temp!=NULL){
   	    cont1++;
        if(cont1==cont){
        cout <<"\t\t"<<d<<" "<<temp->value<<" "<<d<<endl;
        cout<<"\t\t"<<g<<b<<b<<b<<h<<endl;
        temp=temp->next;
	  }else{
      cout <<"\t\t"<<d<<" "<<temp->value<<" "<<d<<endl;
      cout<<"\t\t"<<e<<b<<b<<b<<f<<endl;
      temp=temp->next;
	  }
  }
}
	};


int menu(){
  int opc;
  bool flag, *dir_flag;
  dir_flag = &flag;
  flag = false;
  cout <<"\n1.- APILAR"
         "\n2.- DESAPILAR"
         "\n3.- MOSTRAR TOPE"
         "\n0.- Salir"<<endl;
  cin>>opc;
  system("cls");
  verificar_dato(dir_flag);
  return opc;
};

int main(){
	int opcion=0,top,tope[100];
  Nodo *pila = NULL;
  int value, cont=0, opc=1,num;
  bool flag, *dir_flag;
  dir_flag = &flag;
  display(pila, cont);
  do {
    switch (menu()) {
      flag = false;

      case 1:
      cout<<"Ingresa el numero a agregar"<<endl;
      cin>>num;

      verificar_dato(dir_flag);
      if(num>9){
      	system("cls");
      	continue;
	  }
      cont++;
      tope[cont]=num;
      top=tope[cont];

      push(pila, num);
      system("CLS");
      display(pila, cont);
      break;

      case 2:
      if(cont<1){
  	  cout<<"La pila esta vacia"<<endl;
  	  continue;
 	  }
      cont--;
      top=tope[cont];
      pop(pila,cont);
      system("CLS");
      display(pila, cont);
      break;

      case 3:
      	if(cont>0){
		  cout<<"El tope es: "<<top<< endl;
		  }else{
		  	cout<<"pila vacia"<<endl;
		  }
      	break;

      case 0:
      cout<<"1)continuar \n2)Salir"<<endl;
      cin>>opcion;
      if(opcion==1 ){
      	return main();
	  }else{
	  }
	  opc=0;
      return 0;
      default: std::cout << "\nOpcion no disponible" << '\n';
      system ("pause");
    }
    opc=3;
  } while(opc!=0);

};
