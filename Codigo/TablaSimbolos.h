#ifndef TABLASIMBOLOS_H_INCLUDED
#define TABLASIMBOLOS_H_INCLUDED

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

enum TipoDef {T_VARIABLE, T_FUNCION};
enum TipoDato {T_INT, T_VOID, T_VACIO, T_ERROR};

class EntradaTS {
private:
public:
    string simbolo;
    TipoDef tipo;
    string contexto;
    TipoDato dato;
    vector<TipoDato> parametros;

    EntradaTS( string simbolo, TipoDef tipo, string contexto, TipoDato dato, vector<TipoDato>& parametros ):
         EntradaTS( simbolo, tipo, contexto, dato ) {
        this->parametros = parametros;
    }

    EntradaTS( string simbolo, TipoDef tipo, string contexto, TipoDato dato ) {
        this->simbolo = simbolo;
        this->tipo = tipo;
        this->contexto = contexto;
        this->dato = dato;
    }
};

class TablaSimbolos {
private:
    static TablaSimbolos* instancia;
    vector<EntradaTS*> tabla;
    deque<string> contextos;
    unsigned long anonimos;

    TablaSimbolos() {
        anonimos = 0;
    }
public:
    static TablaSimbolos* instance();
    bool agregarFuncion( string simbolo, TipoDato dato, vector<TipoDato>& parametros );
    bool agregarVariable( string simbolo, TipoDato dato );
    string agregaContextoAnonimo();
    void agregaContexto( string contexto );
    void quitaContexto() ;
    TipoDato tipoSim( string simbolo );
    bool existe( string simbolo );
    TipoDato existe( string simbolo, vector<TipoDato>& parametros );
    void print() ;
    vector<EntradaTS*> totalVariables(string contexto);
    string contexto();
};


#endif // TABLASIMBOLOS_H_INCLUDED
