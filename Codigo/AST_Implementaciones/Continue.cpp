#include "../AST_Tipos.h"

Continue::Continue() {
    simbolo = "continue";
}

Continue::~Continue() {}

TipoDato Continue::analizarTipo() {
    return T_VACIO;
}

string Continue::toString() {
    stringstream ss;
    ss << "<CONTINUE></CONTINUE>" << endl;
    return ss.str();
}

string Continue::generarCodigo(){
    stringstream ss;

    return ss.str();
}
