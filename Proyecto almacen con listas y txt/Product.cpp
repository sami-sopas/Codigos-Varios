#include"Product.h"

using namespace std;

///Constructores---------------------------------------
Product::Product() { }

Product::Product(const Product& p) :  name(p.name), category(p.category), price(p.price), code(p.code), amount(p.amount) {}

///Setters----------------------------------------------
void Product::setName(const std::string& n)
{
    this->name = n;
}

void Product::setCategory(const std::string& c)
{
    this->category = c;
}

void Product::setPrice(const float& p)
{
    this->price = p;
}

void Product::setCode(const int& c)
{
    this->code = c;
}

void Product::setAmount(const int& a)
{
    this->amount = a;
}

///Getters---------------------------------------
string Product::getName()
{
    return name;
}

string Product::getCategory()
{
    return category;
}

float Product::getPrice()
{
    return price;
}

int Product::getCode()
{
    return code;
}

int Product::getAmount()
{
    return amount;
}


string Product::toString()
{
    string impresion;
    char myPrice[16];
    sprintf(myPrice,"%0.2f",price);

    impresion = "\t";
    impresion += to_string(code);
    impresion += "|";
    impresion += name;
    impresion += "|";
    impresion += category;
    impresion += "|";
    impresion += to_string(amount);
    impresion += "|";
    impresion += myPrice;

    return impresion;

}


///Sobrecargas-----------------------------------
Product& Product::operator=(const Product& p)
{
    this->code = p.code;
    this->name = p.name;
    this->category = p.category;
    this->price = p.price;
    this->amount = p.amount;
    return *this;
}

bool Product::operator==(const Product& p)
{
    return this->code == p.code;
}

bool Product::operator!=(const Product& p)
{
    return this->code != p.code;
}

bool Product::operator<(const Product& p)
{
    return this->code < p.code;
}

bool Product::operator<=(const Product& p)
{
    return this->code <= p.code;
}

bool Product::operator>(const Product& p)
{
    return this->code > p.code;
}

bool Product::operator>=(const Product& p)
{
    return this->code >= p.code;
}


