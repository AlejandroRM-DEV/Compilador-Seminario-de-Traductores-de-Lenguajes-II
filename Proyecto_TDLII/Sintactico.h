#ifndef SINTACTICO_H_INCLUDED
#define SINTACTICO_H_INCLUDED

#include "Lexico.h"
#include "Clases.h"

class Sintactico {
private:
    Lexico lex;
    bool error;

    void comprueba( string simbolo ) {
        if( lex.dameSimbolo() == simbolo ) {
            lex.sigSimbolo();
        } else {
            reportaError();
        }
    }

    void comprueba( Token tipo ) {
        if( lex.dameTipo() == tipo ) {
            lex.sigSimbolo();
        } else {
            reportaError();
        }
    }

    void reportaError() {
        error = true;
    }

public:
    Sintactico() {
        error = false;
    }
    bool hayError() {
        return error;
    }

    Nodo* analiza() {
        lex.sigSimbolo();
        Nodo* nodo = listaSentencias();
        comprueba( FIN_ENTRADA );

        return nodo;
    }

    Nodo* listaSentencias() {
        if( error ) return nullptr;

        Nodo* sentencia = nullptr;
        if( lex.dameTipo() != FIN_ENTRADA ) {
            if( lex.dameTipo() == TIPO_VARIABLE ) {
                sentencia = definicionVariable();
            } else if ( lex.dameTipo() == IDENTIFICADOR ) {
                sentencia = asiganacion();
            } else {
                return nullptr;
            }
            sentencia->siguente = listaSentencias();
        }
        return sentencia;
    }

    Asignacion* asiganacion() {
        if( error ) return nullptr;

        Identificador* id = new Identificador( lex.dameSimbolo() );
        comprueba( IDENTIFICADOR );

        comprueba( OP_ASIGNACION );

        Expresion* exp = expresionAditiva();

        comprueba( DELIMITADOR );

        Asignacion* asign = new Asignacion( id, exp );
        return asign;
    }

    Expresion* expresionAditiva() {
        Expresion* exp = nullptr;

        exp = expresionMultiplicativa();

        while( lex.dameTipo() == OP_ADITIVO ) {
            if( lex.dameSimbolo() == "+" ) {
                exp = new Suma( exp, nullptr );
            } else { //if(lex.dameSimbolo() == "-"){
                exp = new Resta( exp, nullptr );
            }
            lex.sigSimbolo();

            if( lex.dameTipo() == OP_ADITIVO ) {
                exp->derecha =  expresionAditiva();
            } else {
                exp->derecha =  expresionMultiplicativa();
            }
        }

        return exp;
    }

    Expresion* expresionMultiplicativa() {
        Expresion* exp = nullptr;

        exp = expresionUnaria();
        while( lex.dameTipo() == OP_MULTIPLICATIVO ) {
            if( lex.dameSimbolo() == "*" ) {
                exp = new Multiplicacion( exp, nullptr );
            } else if( lex.dameSimbolo() == "/" ) {
                exp = new Division( exp, nullptr );
            } else { //if(lex.dameSimbolo() == "*"){
                exp = new Modulo( exp, nullptr );
            }
            lex.sigSimbolo();

            if( lex.dameTipo() == OP_ADITIVO ) {
                exp->derecha = expresionAditiva();
            } else{
                exp->derecha = expresionUnaria() ;
            }
        }

        return exp;
    }

    Expresion* expresionUnaria() {
        Expresion* exp = nullptr;

        if( lex.dameTipo() == IDENTIFICADOR ) {
            exp = new Identificador( lex.dameSimbolo() );
            lex.sigSimbolo();
        } else if( lex.dameTipo() == ENTERO ) {
            exp = new Entero( lex.dameSimbolo() );
            lex.sigSimbolo();
        } else if( lex.dameTipo() == FLOTANTE ) {
            exp = new Flotante( lex.dameSimbolo() );
            lex.sigSimbolo();
        } else if( lex.dameTipo() == PARENTESIS_IZQ ) {
            lex.sigSimbolo();
            cout << "Parentesis" << endl;
            exp = expresionAditiva();
            comprueba( PARENTESIS_DER );
            cout << "FIN Parentesis" << endl;
        } else {
            //reportaError();
        }

        return exp;
    }

    DefinicionVariable* definicionVariable() {
        if( error ) return nullptr;
        DefinicionVariable* aux = nullptr;

        Tipo* tipo = new Tipo( lex.dameSimbolo() );
        comprueba( TIPO_VARIABLE );

        Identificador* id = new Identificador( lex.dameSimbolo() );
        comprueba( IDENTIFICADOR );
        id->siguente = listaVar();

        comprueba( DELIMITADOR );

        aux = new DefinicionVariable( tipo, id );
        return aux;
    }

    Identificador* listaVar() {
        Identificador* aux = nullptr;

        if( error ) return nullptr;

        if( lex.dameTipo() == COMA ) {
            lex.sigSimbolo();
            aux = new Identificador( lex.dameSimbolo() );
            comprueba( IDENTIFICADOR );
            aux->siguente = listaVar();
        }
        return aux;
    }

};

#endif // SINTACTICO_H_INCLUDED
