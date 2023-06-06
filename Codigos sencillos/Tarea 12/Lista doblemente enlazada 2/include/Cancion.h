#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <string>

class Cancion{
    private:
        std::string nombre;
        std::string artista;
        std::string album;
        std::string genero;
        int id;
    public:
        Cancion();

        void setNombre(const std::string&);
        void setArtista(const std::string&);
        void setAlbum(const std::string&);
        void setGenero(const std::string&);
        void setId(const int&);

        std::string getNombre() const;
        std::string getArtista() const;
        std::string getAlbum() const;
        std::string getGenero() const;
        int getId() const;

        std::string toString() const;

        bool operator == (const Cancion&) const;
        bool operator != (const Cancion&) const;
        bool operator < (const Cancion&) const;
        bool operator <= (const Cancion&) const;
        bool operator > (const Cancion&) const;
        bool operator >= (const Cancion&) const;
};

#endif // CANCION_H
