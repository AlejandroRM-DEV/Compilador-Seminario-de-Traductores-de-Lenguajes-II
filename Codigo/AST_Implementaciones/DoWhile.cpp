#include "../AST_Tipos.h"

DoWhile::DoWhile() {
	exp = nullptr;
	proposicion = nullptr;
}

DoWhile::~DoWhile() {
	delete exp;
	delete proposicion;
}

TipoDato DoWhile::analizarTipo() {
	contexto = TablaSimbolos::instance()->agregaContextoAnonimo();
	if ( proposicion->analizarTipo() == T_ERROR ) {
		return T_ERROR;
	}
	if ( exp->analizarTipo() == T_ERROR ) {
		return T_ERROR;
	}
	TablaSimbolos::instance()->quitaContexto();
	return T_VACIO;
}

string DoWhile::toString() {
	stringstream ss;
	ss << "<DO_WHILE>" << endl;
	ss << proposicion->toString();
	ss << "<EXPRESION>" << endl;
	ss << exp->toString( );
	ss << "</EXPRESION>" << endl;
	ss << "</DO_WHILE>" << endl;
	return ss.str();
}

string DoWhile::generarCodigo() {
	stringstream ss;
    ManejadorVariables::instance()->agregaContexto ( contexto );
	ss << proposicion->generarCodigo();
	ss << exp->generarCodigo();
	ss << "EVAL COND" << endl;
	ManejadorVariables::instance()->quitaContexto();
	return ss.str();
}

void DoWhile::buscarVariables() {
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
