#include "../AST_Tipos.h"

Identificador::Identificador ( string simbolo ) {
	this->simbolo = simbolo;
}

Identificador::~Identificador() {}

TipoDato Identificador::analizarTipo() {
	return TablaSimbolos::instance()->tipoSim ( simbolo );
}

string Identificador::toString() {
	stringstream ss;
	ss << "<ID>" << simbolo << "</ID>" << endl;
	return ss.str();
}

string Identificador::generarCodigo() {
	stringstream ss;

	return ss.str();
}

bool Identificador::analizarTipoConstante() {
	return false;
}

int Identificador::evaluar() {
	return 0;
}
