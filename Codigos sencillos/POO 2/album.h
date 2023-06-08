#ifndef ALBUM_H_INCLUDED
#define ALBUM_H_INCLUDED
#include"interprete.h" //Se incluye la liberria interpete. porque haremos uso de esa clase dentro de otra

///Definicion de Album
class Album{
    private: ///ATRIBUTOS
        Interprete creador; ///Tipo de dato abstracto "Interprete" (Anidacion de clases)
        string nombre;
        string autor;
        int anio;
        int cantidad;
        float precio;
    public:
        ///SETTERS
        void setInterprete(Interprete&);
        void setNombre(const string&);
        void setAutor(const string&);
        void setAnio(const int&);
        void setCantidad(const int&);
        void setPrecio(const float&);

        ///GETTERS
        Interprete getInterprete();
        string getNombre();
        string getAutor();
        int getAnio();
        int getCantidad();
        float getPrecio();
};

#endif // ALBUM_H_INCLUDED
