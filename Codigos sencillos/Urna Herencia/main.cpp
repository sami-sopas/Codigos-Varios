#include"iostream"
#include"urna.h"
#include"candidato1.h"
#include"candidato2.h"
#include"candidato3.h"

using namespace std;

bool validacion(char* abc){
    bool isValid=false;
    if(int(*abc)>=46 && int(*abc)<=57){
        isValid=true;
    }
    return isValid;
}

int main()
{
    int cont=0;
    int voto1=0,voto2=0,voto3=0;
	char opc[100];
	int opc2=0;
	char resp[100];
	int respu=0;
	Candidato1 c1;
	Candidato2 c2;
	Candidato3 c3;
	do{
		system("cls");
		cout<<"Menu"<<endl;
		cout<<"Candidato -> Atlas [1]"<<endl;
		cout<<"Candidato -> Chivas [2]"<<endl;
		cout<<"Candidato -> Toluca [3]"<<endl;
		cout<<"Seleccione opcion"<<endl;
		cin>>opc;
            if(validacion(opc)){
            opc2=atoi(opc);}
            else {cout<<"Ingrese un caracter valido"<<endl;
            system("pause");
            return main();
            }
		cout<<endl;
		switch(opc2){

    case 1:{
            cont++;
			voto1++;
			c1.setVoto(voto1);
			c2.setVoto(voto2);
			c3.setVoto(voto3);

			c1.CalcularPorcentaje(voto1,voto2,voto3);
            c2.CalcularPorcentaje(voto1,voto2,voto3);
            c3.CalcularPorcentaje(voto1,voto2,voto3);
			break;
        }
    case 2:{
            cont++;
			voto2++;
			c1.setVoto(voto1);
			c2.setVoto(voto2);
			c3.setVoto(voto3);

            c1.CalcularPorcentaje(voto1,voto2,voto3);
			c2.CalcularPorcentaje(voto1,voto2,voto3);
			c3.CalcularPorcentaje(voto1,voto2,voto3);
			break;
            }
    case 3:{
        cont++;
        voto3++;
        c1.setVoto(voto1);
        c2.setVoto(voto2);
        c3.setVoto(voto3);

            c1.CalcularPorcentaje(voto1,voto2,voto3);
			c2.CalcularPorcentaje(voto1,voto2,voto3);
			c3.CalcularPorcentaje(voto1,voto2,voto3);
        break;
    }
            }


		cout<<"*VOTOS**"<<endl;
		cout<<" Atlas: "<<c1.getVoto()<<endl;
		cout<<" Chivas: "<<c2.getVoto()<<endl;
		cout<<" Toluca: "<<c3.getVoto()<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"*PORCENTAJES**"<<endl;
		cout<<" % Atlas "<<c1.getPorcentaje()<<endl;
		cout<<" % Chivas "<<c2.getPorcentaje()<<endl;
		cout<<" % Toluca "<<c3.getPorcentaje()<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"Ingresar nuevo voto 1 [si] 2[no]"<<endl;
		cin>>resp;
		if(validacion(resp)){
            respu=atoi(resp);}
            else {cout<<"Ingrese un caracter valido"<<endl;
            }

		}
	while(respu!=2);
	}
