#include "../AST_Tipos.h"

If::If() {
	exp = nullptr;
	proIf = nullptr;
	proElse = nullptr;
}

If::~If() {
	delete exp;
	if ( proIf != nullptr ) {
		delete proIf;
	}
	if ( proElse != nullptr ) {
		delete proElse;
	}
}

TipoDato If::analizarTipo() {
	if ( exp->analizarTipo() == T_ERROR ) {
		return T_ERROR;
	}
	if ( proIf != nullptr ) {
		contextoIf = tablaSimbolos->agregaContextoAnonimo();
		if ( proIf->analizarTipo() == T_ERROR ) {
			return T_ERROR;
		}
		tablaSimbolos->quitaContexto();
	}
	if ( proElse != nullptr ) {
		contextoElse = tablaSimbolos->agregaContextoAnonimo();
		if ( proElse->analizarTipo() == T_ERROR ) {
			return T_ERROR;
		}
		tablaSimbolos->quitaContexto();
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

	if ( proElse != nullptr ) {
		ss << "<ELSE>" << endl;
		ss << proElse->toString( );
		ss << "</ELSE>" << endl;
	}
	ss << "</IF>" << endl;
	return ss.str();
}

string If::generarCodigo() {
	stringstream ss, sel, fin, otro;
	sel << "IF_" << ( ++contadorIf );
	fin << "FIN_IF_" << ( contadorIf );
	otro << "ELSE_" << ( contadorIf );

	ss << sel.str() << ": " << endl;
	ss << exp->generarCodigo();
	ss << TABULADOR << "cmp" << TABULADOR << "$1," << TABULADOR << "%eax" << endl;
	ss << TABULADOR << "jl" << TABULADOR << ( ( proElse != nullptr ) ? otro.str() : fin.str() ) << endl;
	manejadorVariables->agregaContexto ( contextoIf );
	ss << proIf->generarCodigo();
	if ( proElse != nullptr ) {
		manejadorVariables->quitaContexto();
		ss << TABULADOR << "jmp" << TABULADOR << fin.str() << endl;
		ss << otro.str() << ": " << endl;
		manejadorVariables->agregaContexto ( contextoElse );
		ss << proElse->generarCodigo();
	}
	manejadorVariables->quitaContexto();
	ss << fin.str() << ": " << endl;
	return ss.str();
}

void If::buscarVariables() {
	manejadorVariables->agregaContexto ( contextoIf );
	manejadorVariables->agregar ( tablaSimbolos->totalVariables ( contextoIf ) );

	if ( ProposicionCompuesta* cuerpo = dynamic_cast<ProposicionCompuesta*> ( proIf ) ) {
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
	manejadorVariables->quitaContexto();

	manejadorVariables->agregaContexto ( contextoElse );
	manejadorVariables->agregar ( tablaSimbolos->totalVariables ( contextoElse ) );

	if ( ProposicionCompuesta* cuerpo = dynamic_cast<ProposicionCompuesta*> ( proElse ) ) {
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
	manejadorVariables->quitaContexto();
}
