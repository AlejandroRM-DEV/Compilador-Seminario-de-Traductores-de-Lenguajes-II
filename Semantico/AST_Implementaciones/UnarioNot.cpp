#include "../AST_Tipos.h"

UnarioNot::UnarioNot( Expresion* exp ) {
    this->exp = exp;
}

UnarioNot::~UnarioNot( ) {
    delete exp;
}

TipoDato UnarioNot::analizarTipo() {
    return exp->analizarTipo();
}

string UnarioNot::toString() {
    stringstream ss;
    ss << "<UNARIO_NOT>" << endl;

    if( exp != nullptr ) {
        ss << exp->toString( );
    }
    ss << "</UNARIO_NOT>" << endl;
    return ss.str();
}
