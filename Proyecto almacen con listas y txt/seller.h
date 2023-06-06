#ifndef SELLER_H_INCLUDED
#define SELLER_H_INCLUDED

#include <fstream>
#include <string>
#include "Product.h"

class Seller{
private:
    int password;

public:
    Seller();
    Seller(const Seller&);

    int getPassword();
    void registerSale(Product&,const int&);
    std::string getInventory();

};

#endif // SELLER_H_INCLUDED
