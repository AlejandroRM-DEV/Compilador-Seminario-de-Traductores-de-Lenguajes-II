#include "../AST_Tipos.h"

Menor::Menor( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "<";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Menor::~Menor() {}

TipoDato Menor::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Menor::toString() {
    stringstream ss;
    ss << "<MENOR>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</MENOR>" << endl;
    return ss.str();
}
