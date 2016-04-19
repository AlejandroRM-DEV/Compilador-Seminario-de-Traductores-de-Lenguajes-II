#include "../AST_Tipos.h"

PosfijoDecremento::PosfijoDecremento( Expresion* exp ) {
    this->exp = exp;
}

PosfijoDecremento::~PosfijoDecremento( ) {
    delete exp;
}

TipoDato PosfijoDecremento::analizarTipo() {
    return exp->analizarTipo();
}

string PosfijoDecremento::toString() {
    stringstream ss;
    ss << "<POSFIJO_DECREMENTO>" << endl;

    if( exp != nullptr ) {
        ss << exp->toString( );
    }
    ss << "</POSFIJO_DECREMENTO>" << endl;
    return ss.str();
}
