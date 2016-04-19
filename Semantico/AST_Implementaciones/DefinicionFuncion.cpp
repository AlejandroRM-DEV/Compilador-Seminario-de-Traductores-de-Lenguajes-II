#include "../AST_Tipos.h"

DefinicionFuncion::DefinicionFuncion( Tipo* tipo, Identificador* id ): Definicion( tipo ) {
    this->id = id;
    cuerpo = nullptr;
}
DefinicionFuncion::~DefinicionFuncion() {
    delete id;
    for( Parametro* p : parametros ) {
        delete p;
    }
    if( cuerpo != nullptr ) {
        delete cuerpo;
    }
}

TipoDato DefinicionFuncion::analizarTipo() {
    vector<TipoDato> tiposParametros;

    for( Parametro* p : parametros  ) {
        tiposParametros.push_back( p->analizarTipo() );
    }

    TablaSimbolos::instance()->agregarFuncion( id->simbolo, tipo->analizarTipo(), tiposParametros );
    TablaSimbolos::instance()->agregaContexto( id->simbolo );

    if( tipo->analizarTipo() == T_INT ) {
        Return::permiteExpresion = true;
    } else {
        Return::permiteExpresion = false;
    }

    for( Parametro* p : parametros ) {
        TablaSimbolos::instance()->agregarVariable( p->id->simbolo, p->tipo->analizarTipo() );
    }

    if( cuerpo != nullptr ) {
        if( cuerpo->analizarTipo( ) == T_ERROR ) {
            return T_ERROR;
        }
    }

    TablaSimbolos::instance()->quitaContexto();
    return T_VACIO;
}

string DefinicionFuncion::toString() {
    stringstream ss;

    ss << "<DEFINICION_FUNCION>" << endl;
    ss << tipo->toString();
    ss << id->toString();
    for( Parametro* p : parametros ) {
        ss << p->toString();
    }
    if( cuerpo != nullptr ) {
        ss << cuerpo->toString( );
    }
    ss << "</DEFINICION_FUNCION>" << endl;

    return ss.str();
}
