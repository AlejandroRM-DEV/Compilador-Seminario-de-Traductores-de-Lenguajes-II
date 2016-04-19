#include "../AST_Tipos.h"

MenorIgual::MenorIgual( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "<=";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

MenorIgual::~MenorIgual() {}

TipoDato MenorIgual::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string MenorIgual::toString() {
    stringstream ss;
    ss << "<MENOR_IGUAL>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</MENOR_IGUAL>" << endl;
    return ss.str();
}
