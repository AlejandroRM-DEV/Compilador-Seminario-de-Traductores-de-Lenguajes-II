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

bool TablaSimbolos::agregarFuncion ( string simbolo, TipoDato dato, vector<TipoDato>& parametros ) {
	if ( !existe ( simbolo ) ) {
		tabla.push_back ( new EntradaTS ( simbolo, T_FUNCION, contextos.front(), dato, parametros ) );
		return true;
	} else {
		cout << "Multiple declaracion de " << simbolo << endl;
		return false;
	}
}

bool TablaSimbolos::agregarVariable ( string simbolo, TipoDato dato ) {
	if ( existe ( simbolo ) ) {
		for ( EntradaTS* e : tabla ) {
			if ( e->contexto == contextos.front() && e->simbolo == simbolo ) {
				cout << "Multiple declaracion de " << simbolo << endl;
				return false;
			}
		}
	}
	tabla.push_back ( new EntradaTS ( simbolo, T_VARIABLE, contextos.front(), dato ) );
	return true;
}

string TablaSimbolos::agregaContextoAnonimo() {
	stringstream ss;
	ss << "" << ( anonimos++ ) << "_ANON";
	contextos.push_front ( ss.str() );
	return ss.str();
}

void TablaSimbolos::agregaContexto ( string contexto ) {
	contextos.push_front ( contexto );
}

void TablaSimbolos::quitaContexto() {
	contextos.pop_front();
}

string TablaSimbolos::contexto() {
	return contextos.front();
}

TipoDato TablaSimbolos::tipoSim ( string simbolo ) {
	for ( string contexto : contextos ) {
		for ( EntradaTS* e : tabla ) {
			if ( e->contexto == contexto && e->simbolo == simbolo ) {
				return e->dato;
			}
		}
	}
	cout << simbolo << " no declarado en el contexto " << contextos.front() << endl;
	return T_ERROR;
}

bool TablaSimbolos::existe ( string simbolo ) {
	for ( string contexto : contextos ) {
		for ( EntradaTS* e : tabla ) {
			if ( e->contexto == contexto && e->simbolo == simbolo ) {
				return true;
			}
		}
	}
	return false;
}

TipoDato TablaSimbolos::existe ( string simbolo, vector<TipoDato>& parametros ) {
	for ( string contexto : contextos ) {
		for ( EntradaTS* e : tabla ) {
			if ( e->contexto == contexto && e->simbolo == simbolo && e->parametros == parametros ) {
				return e->dato;
			}
		}
	}
	cout << "La llamada a la funcion: " << simbolo << " no concuerda con los parametros" << endl;
	return T_ERROR;
}

void TablaSimbolos::print() {
	stringstream ss;
	string tipoDef[] = {"Variable", "Funcion"};
	string tipoDato[] = {"int", "void"};

	ss << setw ( 40 ) << "Tabla de simbolos" << std::left << endl;
	ss << setw ( 20 )  << "SIMBOLO" << setw ( 10 ) << "TIPO" << setw ( 20 ) << "CONTEXTO" << setw (
	       10 ) << "T_DATO" << "PARAMETROS" << endl;

	for ( EntradaTS* e : tabla ) {
		ss << setw ( 20 )  << e->simbolo << setw ( 10 ) << tipoDef[e->tipo] << setw (
		       20 ) << e->contexto << setw ( 10 ) << tipoDato[e->dato];
		for ( TipoDato td : e->parametros ) {
			ss << tipoDato[td] << " - ";
		}
		ss << endl;
	}

	cout << ss.str() << endl;
}

vector<EntradaTS*> TablaSimbolos::totalVariables ( string contexto ) {
	vector<EntradaTS*> lista;
	for ( EntradaTS* e : tabla ) {
		if ( e->tipo == T_VARIABLE && e->contexto == contexto ) {
			lista.push_back ( e );
		}
	}
	return lista;
}
