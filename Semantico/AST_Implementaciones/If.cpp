#include "../AST_Tipos.h"

If::If() {
    exp = nullptr;
    proIf = nullptr;
    proElse = nullptr;
}

If::~If() {
    delete exp;
    if( proIf != nullptr ) {
        delete proIf;
    }
    if( proElse != nullptr ) {
        delete proElse;
    }
}

TipoDato If::analizarTipo() {
    if( exp->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    if( proIf != nullptr ) {
        TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proIf->analizarTipo() == T_ERROR ) {
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
    }
    if( proElse != nullptr ) {
        TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proElse->analizarTipo() == T_ERROR ) {
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
    }
    return T_VACIO;
}

string If::toString() {
    stringstream ss;
    ss << "<IF>" << endl;
    ss << "<EXPRESION>" << endl;
    ss << exp->toString();
    ss << "</EXPRESION>" << endl;
    ss << proIf->toString();

    if( proElse != nullptr ) {
        ss << "<ELSE>" << endl;
        ss << proElse->toString( );
        ss << "</ELSE>" << endl;
    }
    ss << "</IF>" << endl;
    return ss.str();
}
