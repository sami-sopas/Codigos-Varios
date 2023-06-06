
#include <iostream>
#include"windows.h"
using namespace std;
class pila{
	private: int datos[10],tope;
	public:

		pila();
		void push();
		void pop();
		int  vacia();
		int llena();
		void mostrar_tope();
		void mostrar_pila();
		void gotoxy(int,int);
		bool validacion(char*);


};

bool pila::validacion(char*abc){
bool isValid=false;
if(int(*abc)>=48 && int(*abc)<=57){
    isValid = true;
}
return isValid;
}

pila::pila(){
	 tope=-1;
}
void pila::push(){
    char num[100];
	int x;
	if(llena()==0){
		cout<<"ingresa numero"<<endl;
		cin>>num;
        if(validacion(num)){
        x=atoi(num);
        if(x<10){
        tope ++;
	     datos[tope]=x;
        }else{
        cout<<"Ingrese un numero menor a 10"<<endl;
        }
	}

	}

}
void pila::pop(){
	if(vacia()==0){
		datos[tope ]= 0;
		tope --;
	}

}
void pila::mostrar_tope(){
	if(vacia()==0){
		system("cls");
		cout<<"El tope es:  "<<datos[tope ]<<endl;
		system("pause");
	}
}

void pila::mostrar_pila(){
int cont=1,i;
	if(vacia()==0){
		system("cls");

	    for(i=tope;i>=0;i--){
        cont=cont+4;
        gotoxy(cont,2);

        if(i==tope){printf("%c%c%c%c%c ",201,205,205,205,187);}
        else {printf("%c%c%c%c%c ",203,205,205,205,187);}
        gotoxy(cont,3);printf("%c ",186);cout<<datos[i]; printf(" %c",186);
        if(i==tope){gotoxy(cont,4);printf("%c%c%c%c%c\n",200,205,205,205,188);}
        else {gotoxy(cont,4);printf("%c%c%c%c%c\n",202,205,205,205,188);}
		}
		cout<<"       ^ \n       | \n       | \n Frente";
		gotoxy(cont,5);cout<<"   ^";gotoxy(cont,6);cout<<"   |";gotoxy(cont,7);cout<<"   |";gotoxy(cont+2,8);cout<<" Final";
			//system("pause");
	}
}
int  pila::vacia(){
	if(tope==-1){
		system("cls");
		cout<<"LA PILA ESTA VACIA"<<endl;
		system("pause");

		return 1;
	} else{
		return 0;
	}
}
int  pila::llena(){
	if(tope==9){
		system("cls");
		cout<<"LA PILA ESTA LLENA "<<endl;
		system("pause");
	     return 1;

	}
	else{
			return 0;
	}
}

void pila:: gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }

