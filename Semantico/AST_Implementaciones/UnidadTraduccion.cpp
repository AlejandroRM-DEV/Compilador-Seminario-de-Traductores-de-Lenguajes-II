#include "../AST_Tipos.h"

UnidadTraduccion::UnidadTraduccion() {}

UnidadTraduccion::~UnidadTraduccion() {
    for( Definicion* d : definiciones ) {
        delete d;
    }
}

TipoDato UnidadTraduccion::analizarTipo() {
    TablaSimbolos::instance()->agregaContexto( "0_PROGRAMA" );
    for( Definicion* def : definiciones ) {
        if( def->analizarTipo( ) == T_ERROR ) {
            return T_ERROR;
        }
    }
    return T_VACIO;
}

string UnidadTraduccion::toString() {
    stringstream ss;
    ss << "<PROGRAMA>" << endl;

    for( Definicion* d : definiciones ) {
        ss << d->toString();
    }
    ss << "</PROGRAMA>" << endl;

    return ss.str();
}
