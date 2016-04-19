#include "../AST_Tipos.h"

UnarioIncremento::UnarioIncremento( Expresion* exp ) {
    this->exp = exp;
}

UnarioIncremento::~UnarioIncremento( ) {
    delete exp;
}

TipoDato UnarioIncremento::analizarTipo() {
    return exp->analizarTipo();
}

string UnarioIncremento::toString() {
    stringstream ss;
    ss << "<UNARIO_INCREMENTO>" << endl;

    if( exp != nullptr ) {
        ss << exp->toString( );
    }
    ss << "</UNARIO_INCREMENTO>" << endl;
    return ss.str();
}
