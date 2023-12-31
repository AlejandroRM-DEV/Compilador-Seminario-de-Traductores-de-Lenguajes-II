#include "../AST_Tipos.h"

Multiplicacion::Multiplicacion( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "*";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Multiplicacion::~Multiplicacion() {}

TipoDato Multiplicacion::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Multiplicacion::toString() {
    stringstream ss;
    ss << "<MULTIPLICACION>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</MULTIPLICACION>" << endl;
    return ss.str();
}
