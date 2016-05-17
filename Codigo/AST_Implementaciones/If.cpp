#include "../AST_Tipos.h"

If::If() {
    exp = nullptr;
    proIf = nullptr;
    proElse = nullptr;
}

If::~If() {
    delete exp;
    if( proIf != nullptr ) {
        delete proIf;
    }
    if( proElse != nullptr ) {
        delete proElse;
    }
}

TipoDato If::analizarTipo() {
    if( exp->analizarTipo() == T_ERROR ) {
        return T_ERROR;
    }
    if( proIf != nullptr ) {
        contextoIf = TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proIf->analizarTipo() == T_ERROR ) {
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
    }
    if( proElse != nullptr ) {
        contextoElse = TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proElse->analizarTipo() == T_ERROR ) {
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
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

    if( proElse != nullptr ) {
        ss << "<ELSE>" << endl;
        ss << proElse->toString( );
        ss << "</ELSE>" << endl;
    }
    ss << "</IF>" << endl;
    return ss.str();
}

string If::generarCodigo(){
    stringstream ss;

    return ss.str();
}

void If::buscarVariables() {
	ManejadorVariables::instance()->agregaContexto ( contextoIf );
	ManejadorVariables::instance()->agregar ( TablaSimbolos::instance()->totalVariables ( contextoIf ) );

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
	ManejadorVariables::instance()->quitaContexto();

	ManejadorVariables::instance()->agregaContexto ( contextoElse );
	ManejadorVariables::instance()->agregar ( TablaSimbolos::instance()->totalVariables ( contextoElse ) );

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
	ManejadorVariables::instance()->quitaContexto();
}
