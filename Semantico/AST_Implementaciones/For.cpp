#include "../AST_Tipos.h"

For::For() {
    pre = nullptr;
    exp = nullptr;
    post = nullptr;
    proposicion = nullptr;
}

For::~For() {
    if( pre != nullptr ) delete pre;
    if( exp != nullptr )  delete exp;
    if( post != nullptr ) delete post;
    delete proposicion;
}

TipoDato For::analizarTipo() {
    if( pre != nullptr && pre->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    if( exp != nullptr && exp->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    if( post != nullptr && post->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    TablaSimbolos::instance()->agregaContextoAnonimo();
    if( proposicion->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    TablaSimbolos::instance()->quitaContexto();
    return T_VACIO;
}

string For::toString() {
    stringstream ss;
    ss << "<FOR>" << endl;
    if( pre != nullptr ) ss << pre->toString();
    if( exp != nullptr ) ss << exp->toString();
    if( post != nullptr ) ss << post->toString();
    ss << proposicion->toString( );
    ss << "</FOR>" << endl;
    return ss.str();
}
