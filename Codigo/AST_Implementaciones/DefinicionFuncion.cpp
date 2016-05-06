#include "../AST_Tipos.h"

DefinicionFuncion::DefinicionFuncion ( Tipo* tipo, Identificador* id ) : Definicion ( tipo ) {
	this->id = id;
	cuerpo = nullptr;
}
DefinicionFuncion::~DefinicionFuncion() {
	delete id;
	for ( Parametro* p : parametros ) {
		delete p;
	}
	if ( cuerpo != nullptr ) {
		delete cuerpo;
	}
}

TipoDato DefinicionFuncion::analizarTipo() {
	vector<TipoDato> tiposParametros;

	for ( Parametro* p : parametros  ) {
		tiposParametros.push_back ( p->analizarTipo() );
	}

	TablaSimbolos::instance()->agregarFuncion ( id->simbolo, tipo->analizarTipo(), tiposParametros );
	TablaSimbolos::instance()->agregaContexto ( id->simbolo );

	if ( tipo->analizarTipo() == T_INT ) {
		Return::permiteExpresion = true;
	} else {
		Return::permiteExpresion = false;
	}

	for ( Parametro* p : parametros ) {
		TablaSimbolos::instance()->agregarVariable ( p->id->simbolo, p->tipo->analizarTipo() );
	}

	if ( cuerpo != nullptr ) {
		if ( cuerpo->analizarTipo( ) == T_ERROR ) {
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
	for ( Parametro* p : parametros ) {
		ss << p->toString();
	}
	if ( cuerpo != nullptr ) {
		ss << cuerpo->toString( );
	}
	ss << "</DEFINICION_FUNCION>" << endl;

	return ss.str();
}

int DefinicionFuncion::roundUp ( int numToRound, int multiple ) {
	return ( ( numToRound + multiple - 1 ) / multiple ) * multiple;
}

string DefinicionFuncion::generarCodigo() {
    stringstream ss;
	int pilaDecremento = -4;
	int pilaIncremento = 16;
	int variables = TablaSimbolos::instance()->totalVariables ( id->simbolo );
	string regsParam[] = {"%edi", "%esi", "%edx", "%ecx", "%r8d", "%r9d"};

	ss << id->simbolo << ":" << endl;
	ss << TABULADOR << "pushq" << TABULADOR << "%rbp" << endl;
	ss << TABULADOR << "movq" << TABULADOR << "%rsp," << TABULADOR << "%rbp" << endl;
	ss << TABULADOR << "subq" << TABULADOR << "%" << roundUp ( variables * 4, 16 ) << "," << TABULADOR << "%rsp" << endl;
	for ( unsigned int i = 0; i < parametros.size(); i++ ) {
		switch ( i ) {
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			ss << TABULADOR << "movl" << TABULADOR << regsParam[i] << "," << TABULADOR << pilaDecremento << "(%rbp)" << endl;
			pilaDecremento -= 4;
			break;
		default:
			ss << TABULADOR << "movl" << TABULADOR << pilaIncremento << "(%rbp)," << TABULADOR << "%eax" << endl;
			ss << TABULADOR << "movl" << TABULADOR << "%eax," << TABULADOR  << pilaDecremento << "(%rbp)" << endl;
			pilaDecremento -= 4;
			pilaIncremento += 4;
			break;
		}
	}
	ss << TABULADOR << "# Codigo DefinicionFuncion" << endl;
	ss << TABULADOR << "movq" << TABULADOR << "%rbp," << TABULADOR << "%rsb" << endl;
	ss << TABULADOR << "popq" << TABULADOR << "%rbp" << endl;
	ss << TABULADOR << "ret" << endl;
	ss << endl;
	return ss.str();
}
