#include "../AST_Tipos.h"

Resta::Resta ( Expresion* izquierda, Expresion* derecha ) {
	simbolo = "-";
	this->izquierda = izquierda;
	this->derecha = derecha;
}

Resta::~Resta() {}

TipoDato Resta::analizarTipo() {
	if ( izquierda->analizarTipo() == derecha->analizarTipo() ) {
		return izquierda->analizarTipo();
	} else {
		return T_ERROR;
	}
}

string Resta::toString() {
	stringstream ss;
	ss << "<RESTA>" << endl;
	if ( izquierda != nullptr ) {
		ss << izquierda->toString( );
	}
	if ( derecha != nullptr ) {
		ss << derecha->toString( );
	}
	ss << "</RESTA>" << endl;
	return ss.str();
}

string Resta::generarCodigo() {
	stringstream ss;

	return ss.str();
}

bool Resta::analizarTipoConstante() {
	return ( izquierda->analizarTipoConstante() &&  derecha->analizarTipoConstante() );
}

int Resta::evaluar() {
	return izquierda->evaluar() - derecha->evaluar();
}
