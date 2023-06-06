#ifndef URNA_H_INCLUDED
#define URNA_H_INCLUDED

class Urna{
private:
    int voto;

public:

    Urna();
    Urna(const Urna&);
    void setVoto(const int&);
    int getVoto();

};


#endif // URNA_H_INCLUDED
