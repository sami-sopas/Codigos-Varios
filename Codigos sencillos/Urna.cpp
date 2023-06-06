#include <iostream>
class Urna
{
     private:
        double voto1,voto2,voto3,prom,porcentaje1,porcentaje2,porcentaje3;
    public:
        Urna();
        //Urna(double,double,double,double,double,double);
        double setVoto1(double);
        void getVoto1();

        double setVoto2(double);
        void getVoto2();

        double setVoto3(double);
        void getVoto3();


        double setPorcentaje1(double,double,double);
        void getPorcentaje1();

        double setPorcentaje2(double,double,double);
        void getPorcentaje2();

        double setPorcentaje3(double,double,double);
        void getPorcentaje3();

};
Urna::Urna(){}
double Urna::setVoto1(double voto1)
{
    voto1+=1;
	return voto1;
}
void Urna::getVoto1()
{
    this->voto1=voto1;
}
double Urna::setVoto2(double voto2)
{
   	voto2+=1;
	return voto2;
}
void Urna::getVoto2()
{
    this->voto2=voto2;
}
double Urna::setVoto3(double voto3)
{
    voto3+=1;
	return voto3;
}
void Urna::getVoto3()
{
   this->voto3=voto3;
}
double Urna::setPorcentaje1(double voto1,double voto2,double voto3)
{
	porcentaje1=(voto1*100)/(voto1+voto2+voto3);

	return porcentaje1;
}
void Urna::getPorcentaje1()
{
    this->porcentaje1=porcentaje1;
}
double Urna::setPorcentaje2(double voto2,double voto1,double voto3)
{
	porcentaje2=(voto2*100)/(voto1+voto2+voto3);

	return porcentaje2;
}
void Urna::getPorcentaje2()
{
    this->porcentaje2=porcentaje2;
}
double Urna::setPorcentaje3(double voto3,double voto1,double voto2)
{
	porcentaje3=(voto3*100)/(voto1+voto2+voto3);

	return porcentaje3;
}
void Urna::getPorcentaje3()
{
    this->porcentaje3=porcentaje3;
}
using namespace std;

int main()
{
    double voto1=0,voto2=0,voto3=0,porcentaje1,porcentaje2,porcentaje3;
	int resp,opc;
	Urna u;
	do{
		system("cls");
		cout<<"Menu"<<endl;
		cout<<"Candidato -> Atlas [1]"<<endl;
		cout<<"Candidato -> Chivas [2]"<<endl;
		cout<<"Candidato -> Toluca [3]"<<endl;
		cout<<"Seleccione opcion"<<endl;
		cin>>opc;
		cout<<endl;
		cout<<endl;
		if(opc==1)
			voto1=u.setVoto1(voto1);

		else if(opc==2)
			voto2=u.setVoto2(voto2);


		else if(opc==3)
			voto3=u.setVoto3(voto3);

		porcentaje1=u.setPorcentaje1(voto1,voto2,voto3);


		porcentaje2=u.setPorcentaje2(voto2,voto1,voto3);


		porcentaje3=u.setPorcentaje3(voto3,voto1,voto2);

		cout<<"*VOTOS**"<<endl;
		cout<<" Atlas: "<<voto1<<endl;
		cout<<" Chivas: "<<voto2<<endl;
		cout<<" Toluca: "<<voto3<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"*PORCENTAJES**"<<endl;
		cout<<" % Atlas "<<porcentaje1<<endl;
		cout<<" % Chivas "<<porcentaje2<<endl;
		cout<<" % Toluca "<<porcentaje3<<endl;
		cout<<endl;
		cout<<endl;
		cout<<"Ingresar nuevo voto 1 [si] 2[no]"<<endl;
		cin>>resp;
	}while(resp!=2);
    return 0;
}
