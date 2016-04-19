#include "../AST_Tipos.h"

MayorIgual::MayorIgual( Expresion* izquierda, Expresion* derecha ) {
    simbolo = ">=";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

MayorIgual::~MayorIgual() {}

TipoDato MayorIgual::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string MayorIgual::toString() {
    stringstream ss;
    ss << "<MAYOR_IGUAL>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</MAYOR_IGUAL>" << endl;
    return ss.str();
}
