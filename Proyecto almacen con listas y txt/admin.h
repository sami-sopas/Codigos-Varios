#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <fstream>
#include <string>
#include "seller.h"
#include "LDLCCED.h"

class Admin{
private:
    int password;

public:
    Admin();
    Admin(const Admin&);

    void setPassword(const int&);
    void setInventory(std::string&);
    void setHistory(std::string&);
    int getPassword();
    std::string getHistory();
    std::string getInventory();


};

#endif // ADMIN_H_INCLUDED
