#include "../AST_Tipos.h"

Diferente::Diferente( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "!=";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Diferente::~Diferente() {}

TipoDato Diferente::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Diferente::toString() {
    stringstream ss;
    ss << "<DIFERENTE>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</DIFERENTE>" << endl;
    return ss.str();
}
