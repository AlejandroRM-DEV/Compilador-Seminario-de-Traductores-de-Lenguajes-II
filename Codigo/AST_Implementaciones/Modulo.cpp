#include "../AST_Tipos.h"

Modulo::Modulo( Expresion* izquierda, Expresion* derecha ) {
    simbolo = "%";
    this->izquierda = izquierda;
    this->derecha = derecha;
}

Modulo::~Modulo() {}

TipoDato Modulo::analizarTipo() {
    if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
        return izquierda->analizarTipo();
    } else {
        return T_ERROR;
    }
}

string Modulo::toString() {
    stringstream ss;
    ss << "<MODULO>" << endl;
    if( izquierda != nullptr ) {
        ss << izquierda->toString( );
    }
    if( derecha != nullptr ) {
        ss << derecha->toString( );
    }
    ss << "</MODULO>" << endl;
    return ss.str();
}

string Modulo::generarCodigo(){
    stringstream ss;

    return ss.str();
}

bool Modulo::analizarTipoConstante() {
	return ( izquierda->analizarTipoConstante() &&  derecha->analizarTipoConstante() );
}

int Modulo::evaluar() {
	return izquierda->evaluar() % derecha->evaluar();
}
