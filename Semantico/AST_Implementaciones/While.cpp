#include "../AST_Tipos.h"

While::While() {
    exp = nullptr;
    proposicion = nullptr;
}

While::~While() {
    delete exp;
    delete proposicion;
}

TipoDato While::analizarTipo() {
    if( exp->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    TablaSimbolos::instance()->agregaContextoAnonimo();
    if( proposicion->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    TablaSimbolos::instance()->quitaContexto();
    return T_VACIO;
}

string While::toString() {
    stringstream ss;
    ss << "<WHILE>" << endl;
    ss << "<EXPRESION>" << endl;
    ss << exp->toString();
    ss << "</EXPRESION>" << endl;
    ss << proposicion->toString( );
    ss << "</WHILE>" << endl;
    return ss.str();
}
