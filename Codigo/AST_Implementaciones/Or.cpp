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
		stringstream ss, fin;
	fin << "FIN_AND_" << ( ++contador );

    ss << TABULADOR << "pushq" << TABULADOR << "%rbx" << endl;

	ss << izquierda->generarCodigo();
	// Si lado izquierdo es verdadero, producios corto circuito
	ss << TABULADOR << "cmp" << TABULADOR << "$1," << TABULADOR << "%eax" << endl;
	ss << TABULADOR << "jge" << TABULADOR << fin.str()  << endl;

	ss << derecha->generarCodigo();

	ss << fin.str() << ": " << endl;
	ss << TABULADOR << "popq" << TABULADOR << "%rbx" << endl;
	return ss.str();
}

bool OR::analizarTipoConstante() {
	return ( izquierda->analizarTipoConstante() &&  derecha->analizarTipoConstante() );
}

int OR::evaluar() {
	return izquierda->evaluar() || derecha->evaluar();
}
