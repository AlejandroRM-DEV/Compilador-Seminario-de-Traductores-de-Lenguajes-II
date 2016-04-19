#include "../AST_Tipos.h"

Entero::Entero( string simbolo ) {
    this->simbolo = simbolo;
}

Entero::~Entero() {}

TipoDato Entero::analizarTipo() {
    return T_INT;
}

string Entero::toString() {
    stringstream ss;
    ss << "<ENTERO>" << simbolo << "</ENTERO>" << endl;
    return ss.str();
}
