#include "../AST_Tipos.h"

Asignacion::Asignacion( Identificador* id, Expresion* expresion ) {
    this->id = id;
    this->expresion = expresion;
}

TipoDato Asignacion::analizarTipo() {
    if( id->analizarTipo() == expresion->analizarTipo() ) {
        return id->analizarTipo();
    } else {
        return T_ERROR;
    }
}

Asignacion::~Asignacion() {
    if( id != nullptr ) {
        delete id;
    };
    if( expresion != nullptr ) {
        delete expresion;
    };
}

string Asignacion::toString() {
    stringstream ss;

    ss << "<ASIGNACION>" << endl;
    ss << id->toString();

    if( expresion != nullptr ) {
        ss << "<EXPRESION>" << endl;
        ss << expresion->toString( );
        ss << "</EXPRESION>" << endl;
    }
    ss << "</ASIGNACION>" << endl;

    return ss.str();
}
