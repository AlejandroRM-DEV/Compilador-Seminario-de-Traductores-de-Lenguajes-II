#include "../AST_Tipos.h"

Suma::Suma( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "+";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Suma::~Suma() {}

TipoDato Suma::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Suma::toString() {
    stringstream ss;
    ss << "<SUMA>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</SUMA>" << endl;
    return ss.str();
}
