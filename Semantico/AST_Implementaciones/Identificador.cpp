#include "../AST_Tipos.h"

Identificador::Identificador( string simbolo ) {
    this->simbolo = simbolo;
}

Identificador::~Identificador() {}

TipoDato Identificador::analizarTipo() {
    return TablaSimbolos::instance()->tipoSim( simbolo );
}

string Identificador::toString() {
    stringstream ss;
    ss << "<ID>" << simbolo << "</ID>" << endl;
    return ss.str();
}
