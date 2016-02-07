#ifndef ENTRATABLASIMBOLO_H_INCLUDED
#define ENTRATABLASIMBOLO_H_INCLUDED

#include <iostream>

using namespace std;

class EntradaTablaSimbolo{
private:
    static int cuentaID;
public:
    int id;
    string nombre;

    EntradaTablaSimbolo(string nombre);
    ~EntradaTablaSimbolo();
};

#endif // ENTRATABLASIMBOLO_H_INCLUDED
