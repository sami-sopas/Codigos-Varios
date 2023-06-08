///Definicion de clase
#ifndef INTERPRETE_H_INCLUDED
#define INTERPRETE_H_INCLUDED

#include<string> ///Libreria para hacer uso del tipo de dato string

using namespace std;

class Interprete{
    private: ///Atributos (Lo que define a una clase)
        string solista;
        string banda;
    public: ///Metodos (Comportamiento del objeto)
        ///Setters
        void setSolista(const string&);
        void setBanda(const string&);
        ///Getters
        string getSolista();
        string getBanda();

};


#endif // INTERPRETE_H_INCLUDED
