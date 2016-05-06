#include "../AST_Tipos.h"

OR::OR ( Expresion* izquierda, Expresion* derecha ) {
	simbolo = "||";
	this->izquierda = izquierda;
	this->derecha = derecha;
}

OR::~OR() {}

TipoDato OR::analizarTipo() {
	if ( izquierda->analizarTipo() == derecha->analizarTipo() ) {
		return izquierda->analizarTipo();
	} else {
		return T_ERROR;
	}
}

string OR::toString() {
	stringstream ss;
	ss << "<OR>" << endl;
	if ( izquierda != nullptr ) {
		ss << izquierda->toString( );
	}
	if ( derecha != nullptr ) {
		ss << derecha->toString( );
	}
	ss << "</OR>" << endl;
	return ss.str();
}

string OR::generarCodigo() {
	stringstream ss;

	return ss.str();
}

bool OR::analizarTipoConstante() {
	return ( izquierda->analizarTipoConstante() &&  derecha->analizarTipoConstante() );
}

int OR::evaluar() {
	return izquierda->evaluar() || derecha->evaluar();
}
