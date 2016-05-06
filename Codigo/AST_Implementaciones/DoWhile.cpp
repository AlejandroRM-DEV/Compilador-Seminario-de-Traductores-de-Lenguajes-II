#include "../AST_Tipos.h"

DoWhile::DoWhile() {
    exp = nullptr;
    proposicion = nullptr;
}

DoWhile::~DoWhile() {
    delete exp;
    delete proposicion;
}

TipoDato DoWhile::analizarTipo() {
    TablaSimbolos::instance()->agregaContextoAnonimo();
    if( proposicion->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    TablaSimbolos::instance()->quitaContexto();
    if( exp->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    return T_VACIO;
}

string DoWhile::toString() {
    stringstream ss;
    ss << "<DO_WHILE>" << endl;
    ss << proposicion->toString();
    ss << "<EXPRESION>" << endl;
    ss << exp->toString( );
    ss << "</EXPRESION>" << endl;
    ss << "</DO_WHILE>" << endl;
    return ss.str();
}

string DoWhile::generarCodigo(){
    stringstream ss;

    return ss.str();
}
