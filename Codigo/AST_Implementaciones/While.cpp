#include "../AST_Tipos.h"

While::While() {
	exp = nullptr;
	proposicion = nullptr;
}

While::~While() {
	delete exp;
	delete proposicion;
}

TipoDato While::analizarTipo() {
	if ( exp->analizarTipo() == T_ERROR ) {
		return T_ERROR;
	}
	contexto =  TablaSimbolos::instance()->agregaContextoAnonimo();
	if ( proposicion->analizarTipo() == T_ERROR ) {
		return T_ERROR;
	}
	TablaSimbolos::instance()->quitaContexto();
	return T_VACIO;
}

string While::toString() {
	stringstream ss;
	ss << "<WHILE>" << endl;
	ss << "<EXPRESION>" << endl;
	ss << exp->toString();
	ss << "</EXPRESION>" << endl;
	ss << proposicion->toString( );
	ss << "</WHILE>" << endl;
	return ss.str();
}

string While::generarCodigo() {
	stringstream ss;
	ss << exp->generarCodigo();
	ss << "EVAL COND" << endl;
	ManejadorVariables::instance()->agregaContexto ( contexto );
	ss << proposicion->generarCodigo();
	ManejadorVariables::instance()->quitaContexto();
	return ss.str();
}


void While::buscarVariables() {
	ManejadorVariables::instance()->agregaContexto ( contexto );
	ManejadorVariables::instance()->agregar ( TablaSimbolos::instance()->totalVariables ( contexto ) );

	if ( ProposicionCompuesta* cuerpo = dynamic_cast<ProposicionCompuesta*> ( proposicion ) ) {
		for ( Nodo* nodo : cuerpo->cuerpo ) {
			if ( DoWhile* dv = dynamic_cast<DoWhile*> ( nodo ) ) {
				dv->buscarVariables();
			} else if ( For* dv = dynamic_cast<For*> ( nodo ) ) {
				dv->buscarVariables();
			} else if ( If* dv = dynamic_cast<If*> ( nodo ) ) {
				dv->buscarVariables();
			} else if ( While* dv = dynamic_cast<While*> ( nodo ) ) {
				dv->buscarVariables();
			}
		}
	}
	ManejadorVariables::instance()->quitaContexto();
}
