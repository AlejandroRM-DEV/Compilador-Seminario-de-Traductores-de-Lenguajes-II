#include "../AST_Tipos.h"

Break::Break() {
    simbolo = "break";
}

Break::~Break() {}

TipoDato Break::analizarTipo() {
    return T_VACIO;
}

string Break::toString() {
    stringstream ss;
    ss << "<BREAK></BREAK>" << endl;
    return ss.str();
}

string Break::generarCodigo(){
    stringstream ss;

    return ss.str();
}
