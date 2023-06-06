#include <iostream>
#include"windows.h"
#include <cstdlib>

using namespace std;
gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

bool validacion(char*abc){
bool isValid=false;
if(int(*abc)>=48 && int(*abc)<=57){
    isValid = true;
}
return isValid;
}

class Nodo{

  public:

    int value;

    Nodo* next;

};

bool cola_vacia(Nodo *frente){

	return (frente == NULL)? true : false;

};

void push(Nodo *&frente,Nodo *&fin,int n){




	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->value = n;

	nuevo_nodo->next = NULL;

	if(cola_vacia(frente)){

		frente = nuevo_nodo;

	}else{

		fin->next = nuevo_nodo;

	}

	fin = nuevo_nodo;




};




void pop(Nodo *&frente,Nodo *&fin){

	Nodo *aux = frente;

	if(frente == fin){

		frente = NULL;

		fin = NULL;

	}else{

		frente = frente->next;

	}

	delete aux;

};




void display(Nodo *&frente, int cont)

   //CODIGO DISPLAY PILA DINAMICA
  {
  Nodo *temp = frente;
  int aux=1;


  if(temp==0){
  	cout<<"Cola vacia"<<endl;
  }else{
  	  printf("\t%c%c%c%c%c  \n",201,205,205,205,187);
  
  while(temp!=NULL){
    if(temp==frente){
    cout<<"inicio>";
    printf(" %c ",186);cout<<temp->value; printf(" %c\n",186);
      temp=temp->next;
      if(aux<cont){printf("\t%c%c%c%c%c\n",204,205,205,205,185);}
      else{printf("\t%c%c%c%c%c\n",200,205,205,205,188);}
    }else{
    printf("\t%c ",186);cout<<temp->value; printf(" %c\n",186);
    temp = temp->next;
    cont--;
    if(aux<cont){printf("\t%c%c%c%c%c\n",204,205,205,205,185);}
    else{printf("\t%c%c%c%c%c\n",200,205,205,205,188);}
    }
    }
    cout<<"        ^"<<endl;
    cout<<"Final---|\n";
}


};


int menu(){

  char myopc[100];
  int opc;

  cout <<endl;

  cout <<"Menu"<<endl;

  cout <<"[1]Push"<<endl;

  cout <<"[2]Pop"<<endl;

  cout <<"[3]Salir"<<endl;

  cin>>myopc;
  if(validacion(myopc)){
  	opc=atoi(myopc);
  }else{cout<<"Ingrese una opcion correcta"<<endl;
  }

  return opc;




};

int main(){

  Nodo *frente = NULL;

  Nodo *fin = NULL;

  int value, cont=0, opc=1, cont2=0;

  do {




    switch (menu()) {

      case 1:

         cont2++;

         cont++;

         push(frente, fin, cont);

         system("cls");

         display(frente, cont2);

      break;

      case 2:

          cont2--;

          pop(frente, fin);

          system("cls");

          display(frente, cont2);

      break;

    }




  } while(menu()!=3);

  return 0;

};
