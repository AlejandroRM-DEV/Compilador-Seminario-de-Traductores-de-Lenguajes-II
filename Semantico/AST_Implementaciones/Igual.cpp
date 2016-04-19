#include "../AST_Tipos.h"

Igual::Igual( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "==";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Igual::~Igual() {}

TipoDato Igual::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Igual::toString() {
    stringstream ss;
    ss << "<IGUALDAD>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</IGUALDAD>" << endl;
    return ss.str();
}
