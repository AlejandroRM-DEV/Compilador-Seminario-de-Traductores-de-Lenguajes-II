#include "../AST_Tipos.h"

LlamadaFuncion::LlamadaFuncion( Identificador* id ) {
    this->id = id;
}
LlamadaFuncion::~LlamadaFuncion() {
    delete id;
    for( Expresion* p : parametros ) {
        delete p;
    }
}

TipoDato LlamadaFuncion::analizarTipo() {
    vector<TipoDato> tiposParametros;
    for( Expresion* p : parametros  ) {
        tiposParametros.push_back( p->analizarTipo() );
    }

    return TablaSimbolos::instance()->existe( id->simbolo, tiposParametros );
}

string LlamadaFuncion::toString() {
    stringstream ss;

    ss << "<LLAMADA_FUNCION>" << endl;
    ss << id->toString( );
    for( Expresion* p : parametros ) {
        ss << p->toString();
    }
    ss << "</LLAMADA_FUNCION>" << endl;

    return ss.str();
}
