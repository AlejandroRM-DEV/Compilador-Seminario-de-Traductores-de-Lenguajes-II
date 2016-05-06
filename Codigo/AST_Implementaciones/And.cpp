#include "../AST_Tipos.h"

AND::AND ( Expresion* izquierda, Expresion* derecha ) {
	simbolo = "&&";
	this->izquierda = izquierda;
	this->derecha = derecha;
}

AND::~AND() {}

TipoDato AND::analizarTipo() {
	if ( izquierda->analizarTipo() == derecha->analizarTipo() ) {
		return izquierda->analizarTipo();
	} else {
		return T_ERROR;
	}
}

string AND::toString() {
	stringstream ss;
	ss << "<AND>" << endl;
	if ( izquierda != nullptr ) {
		ss << izquierda->toString( );
	}
	if ( derecha != nullptr ) {
		ss << derecha->toString( );
	}
	ss << "</AND>" << endl;
	return ss.str();
}

string AND::generarCodigo() {
	stringstream ss;

	return ss.str();
}

bool AND::analizarTipoConstante() {
	return ( izquierda->analizarTipoConstante() &&  derecha->analizarTipoConstante() );
}

int AND::evaluar() {
	return izquierda->evaluar() && derecha->evaluar();
}
