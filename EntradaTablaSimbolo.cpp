#include "EntradaTablaSimbolo.h"

int EntradaTablaSimbolo::cuentaID = 0;

EntradaTablaSimbolo::EntradaTablaSimbolo( string nombre ) {
    this->nombre = nombre;
    this->id = cuentaID++;
}

EntradaTablaSimbolo::~EntradaTablaSimbolo() {}

