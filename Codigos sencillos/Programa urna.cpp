/*Samuel Osvaldo Ramirez Cuenca
Programa de urna de votos con estructuras y punteros*/
#include<iostream>

using namespace std;
int *ptr1=NULL,*ptr2=NULL,*ptr3=NULL;
int a,b,c,porcentaje1,porcentaje2,porcentaje3,p1,p2,p3;
int opc=0,resp=0,voto1=0,voto2=0,voto3=0;

int setVoto1(int voto1){
	return voto1+1;
}
int setVoto2(int voto2){
	return voto2+1;
}
int setVoto3(int voto3){
	return voto3+1;
}

int setPorcentajes1(int porcentaje1,int porcentaje2,int porcentaje3) {
porcentaje1=(voto1*100)/(voto1+voto2+voto3);
return porcentaje1;
}

int setPorcentajes2(int porcentaje1,int porcentaje2,int porcentaje3) {
porcentaje2=(voto2*100)/(voto1+voto2+voto3);
return porcentaje2;
}

int setPorcentajes3(int porcentaje1,int porcentaje2,int porcentaje3) {
porcentaje3=(voto3*100)/(voto1+voto2+voto3);
return porcentaje3;
}

int main(int argc, char** argv) {
	do {
system("cls");
cout<<"Menu"<<endl;
cout<<"Candidato -> Atlas [1]"<<endl;
cout<<"Candidato -> Chivas [2]"<<endl;
cout<<"Candidato -> Toluca [3]"<<endl;
cout<<"Seleccione opcion"<<endl;
cin>>opc;
cout<<endl;
cout<<endl;

switch(opc){
	case 1:
voto1=setVoto1(voto1);
ptr1 = &voto1;
a=*ptr1;break;

    case 2:
voto2=setVoto2(voto2);
ptr2 = &voto2;
b=*ptr2;break;

    case 3:
voto3=setVoto3(voto3);
ptr3 = &voto3;
c=*ptr3;break;
}

porcentaje1=setPorcentajes1(a,b,c);
ptr1 = &porcentaje1;
p1=*ptr1;

porcentaje2=setPorcentajes2(a,b,c);
ptr2 = &porcentaje2;
p2=*ptr2;

porcentaje3=setPorcentajes3(a,b,c);
ptr3 = &porcentaje3;
p3=*ptr3;

cout<<"*********VOTOS**********"<<endl;
cout<<" Atlas: "<<a<<endl;
cout<<" Chivas: "<<b<<endl;
cout<<" Toluca: "<<c<<endl;
cout<<endl;
cout<<endl;

cout<<"*****PORCENTAJES********"<<endl;
cout<<" % Atlas "<<p1<<endl;
cout<<" % Chivas "<<p2<<endl;
cout<<" % Toluca "<<p3<<endl;
cout<<endl;
cout<<endl;

cout<<"Ingresar nuevo voto 1 [si] 2[no]"<<endl;
cin>>resp;

}while(resp!=2);
system("pause");
return 0;
}
