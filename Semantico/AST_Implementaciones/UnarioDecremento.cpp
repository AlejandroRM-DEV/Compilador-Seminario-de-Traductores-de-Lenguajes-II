#include "../AST_Tipos.h"

UnarioDecremento::UnarioDecremento( Expresion* exp ) {
    this->exp = exp;
}

UnarioDecremento::~UnarioDecremento( ) {
    delete exp;
}

TipoDato UnarioDecremento::analizarTipo() {
    return exp->analizarTipo();
}

string UnarioDecremento::toString() {
    stringstream ss;
    ss << "<UNARIO_DECREMENTO>" << endl;

    if( exp != nullptr ) {
        ss << exp->toString( );
    }
    ss << "</UNARIO_DECREMENTO>" << endl;
    return ss.str();
}
