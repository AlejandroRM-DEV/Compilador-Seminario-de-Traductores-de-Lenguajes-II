#ifndef MANEJADORVARIABLES_H_INCLUDED
#define MANEJADORVARIABLES_H_INCLUDED

#include <iostream>
#include <vector>
#include "TablaSimbolos.h"

using namespace std;

class ManejadorVariables{
private:
    static ManejadorVariables* instancia;
    vector<EntradaTS*> variables;
    deque<string> contextos;

    ManejadorVariables(){}
public:
    static ManejadorVariables* instance();
    void agregar (vector<EntradaTS*> vars );
    int buscar(string simbolo);
    void vaciar();
    int total();
    void agregaContexto( string contexto );
    void quitaContexto();
    string contexto();
};

#endif // MANEJADORVARIABLES_H_INCLUDED
