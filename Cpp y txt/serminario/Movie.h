#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED
#include<string.h>
#include<fstream>
#include<iostream>

class Movie{

    private:
        std::string name;
        std::string category;
        std::string clasification;
        int points;

    public:
        Movie();
        Movie(const Movie&);

        void setName(const std::string&);
        void setCategory(const std::string&);
        void setClasification(const std::string&);
        void setPoints(const int&);

        std::string getName();
        std::string getCategory();
        std::string getClasification();
        int getPoints();

        void capturar(Movie&);
        void imprimir(Movie&);
        void buscar(Movie&);
        void modificar(Movie&);
        void eliminar(Movie&);

        Movie& operator = (const Movie&);
};

#endif // MOVIE_H_INCLUDED
