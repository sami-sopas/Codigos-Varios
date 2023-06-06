#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

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


#endif // PILA_H_INCLUDED
