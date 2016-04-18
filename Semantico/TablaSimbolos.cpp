#include "TablaSimbolos.h"

#include <sstream>
#include <iomanip>

TablaSimbolos* TablaSimbolos::instancia = nullptr;

TablaSimbolos* TablaSimbolos::instance() {
    if ( !instancia ) {
        instancia = new TablaSimbolos;
    }
    return instancia;
}

bool TablaSimbolos::agregarFuncion( string simbolo, TipoDato dato, vector<TipoDato>& parametros ) {
    if( !existe( simbolo ) ) {
        tabla.push_back( new EntradaTS( simbolo, T_FUNCION, contextos.front(), dato, parametros ) );
        return true;
    } else {
        cout << "Multiple declaracion de " << simbolo << endl;
        return false;
    }
}

bool TablaSimbolos::agregarVariable( string simbolo, TipoDato dato ) {
    if( !existe( simbolo ) ) {
        tabla.push_back( new EntradaTS( simbolo, T_VARIABLE, contextos.front(), dato ) );
        return true;
    } else {
        cout << "Multiple declaracion de " << simbolo << endl;
        return false;
    }
}

void TablaSimbolos::agregaContextoAnonimo() {
    stringstream ss;
    ss << "" << (anonimos++) << "_ANON";
    contextos.push_front( ss.str() );
}

void TablaSimbolos::agregaContexto( string contexto ) {
    contextos.push_front( contexto );
}

void TablaSimbolos::quitaContexto() {
    contextos.pop_front();
}

TipoDato TablaSimbolos::tipoSim( string simbolo ) {
    for( string contexto : contextos ) {
        for( EntradaTS* e : tabla ) {
            if( e->contexto == contexto && e->simbolo == simbolo ) {
                return e->dato;
            }
        }
    }
    return T_ERROR;
}

bool TablaSimbolos::existe( string simbolo ) {
    for( string contexto : contextos ) {
        for( EntradaTS* e : tabla ) {
            if( e->contexto == contexto && e->simbolo == simbolo ) {
                return true;
            }
        }
    }
    return false;
}

TipoDato TablaSimbolos::existe( string simbolo, vector<TipoDato>& parametros ) {
    for( string contexto : contextos ) {
        for( EntradaTS* e : tabla ) {
            if( e->contexto == contexto && e->simbolo == simbolo && e->parametros == parametros) {
                return e->dato;
            }
        }
    }
    return T_ERROR;
}

void TablaSimbolos::print() {
    stringstream ss;
    string tipoDef[] = {"Variable", "Funcion"};
    string tipoDato[] = {"int", "void"};

    ss << setw( 40 ) << "Tabla de simbolos" << std::left << endl;
    ss << setw( 20 )  << "SIMBOLO" << setw( 10 ) << "TIPO" << setw( 20 ) << "CONTEXTO" << setw( 10 ) << "T_DATO" << "PARAMETROS" << endl;

    for( EntradaTS* e : tabla ) {
        ss << setw( 20 )  << e->simbolo << setw( 10 ) << tipoDef[e->tipo] << setw( 20 ) << e->contexto << setw( 10 ) << tipoDato[e->dato];
        for( TipoDato td : e->parametros ) {
            ss << tipoDato[td] << " - ";
        }
        ss << endl;
    }

    cout << ss.str() << endl;
}
