#include "Sintactico.h"

void Sintactico::comprueba( string simbolo ) {
    if( tokens.front().first == simbolo ) {
        tokens.pop();
    } else {
        marcarError( "Se esperaba un: " + simbolo );
    }
}

void Sintactico::comprueba( Token tipo ) {
    if( tokens.front().second == tipo ) {
        tokens.pop();
    } else {
        marcarError( "Se esperaba un: " + etiquetas[tipo] );
    }
}

void Sintactico::marcarError( string mensaje ) {
    cout << "ERROR: " << tokens.front().first << endl;
    cout << "NOTA:  "  << mensaje << endl;
    error = true;
}

Sintactico::Sintactico( queue<ParToken> tokens ) {
    error = false;
    this->tokens = tokens;
}

Sintactico::~Sintactico() {}

bool Sintactico::hayError() {
    return error;
}

Nodo* Sintactico::analiza() {
    Nodo* nodo = unidad_traduccion();
    comprueba( FIN_ENTRADA );
    return nodo;
}

UnidadTraduccion* Sintactico::unidad_traduccion() {
    UnidadTraduccion* ut = new UnidadTraduccion();

    ut->definiciones.push_back( definicion() );
    unidad_traduccion_prima( ut );

    return ut;
}

void Sintactico::unidad_traduccion_prima( UnidadTraduccion* ut ) {
    if( error ) return;

    if( tokens.front().second != FIN_ENTRADA ) {
        ut->definiciones.push_back( definicion() );
        unidad_traduccion_prima( ut );
    }
}

Definicion* Sintactico::definicion() {
    if( error ) return nullptr;

    Tipo* tipo = especificador_tipo();

    Identificador* id = new Identificador( tokens.front().first );
    comprueba( IDENTIFICADOR );

    return definicion_prima( tipo, id );
}

Definicion* Sintactico::definicion_prima( Tipo* tipo, Identificador* id ) {
    if( error ) return nullptr;

    if( tokens.front().second == PARENTESIS_IZQ ) {
        tokens.pop();
        DefinicionFuncion* def = new DefinicionFuncion( tipo, id );
        if( tokens.front().second == PARENTESIS_DER ) {
            tokens.pop();
            cuerpo_funcion( def );
        } else {
            lista_param( def );
            comprueba( PARENTESIS_DER );
            cuerpo_funcion( def );
        }
        return def;
    } else {
        DefinicionVariable* def = new DefinicionVariable( tipo );
        //  declarador_init_prima() puede ser nullptr
        def->asignaciones.push_back( new Asignacion( id, declarador_init_prima() ) );
        lista_vars( def );
        return def;
    }
}

void Sintactico::cuerpo_funcion( DefinicionFuncion* def ) {
    if( error ) return;

    if( tokens.front().second == DELIMITADOR ) {
        tokens.pop();
    } else {
        def->cuerpo = proposicion_compuesta();
    }
}

void Sintactico::lista_vars( DefinicionVariable* dv ) {
    if( error ) return;

    switch( tokens.front().second ) {
    case DELIMITADOR:
        tokens.pop();
        break;
    case COMA:
        tokens.pop();
        dv->asignaciones.push_back( declarador_init() );
        lista_vars( dv );
        break;
    default:
        marcarError( "Se esperaba un \";\" o una \",\"" );
    }
}

void Sintactico::lista_de_declaraciones( vector<Nodo*>& vec ) {
    if( error ) return;
    Tipo* tipo = nullptr;
    DefinicionVariable* def = nullptr;

    switch( reservados.find( tokens.front().first )->second ) {
    case INT:
        tipo = especificador_tipo();
        def = new DefinicionVariable( tipo );

        def->asignaciones.push_back( declarador_init() );
        lista_vars( def );

        vec.push_back( def );
        lista_de_declaraciones( vec );

        break;
    case VOID:
        marcarError( "La variable no puede ser de tipo \"void\", se esperaba un tipo \"int\"" );
        break;
    default:
        break;
    }
}

Asignacion* Sintactico::declarador_init() {
    if( error ) return nullptr;

    Identificador* id = new Identificador( tokens.front().first );
    comprueba( IDENTIFICADOR );

    return new Asignacion( id, declarador_init_prima() );
}

Expresion* Sintactico::declarador_init_prima() {
    Expresion* exp = nullptr;

    if( error ) return exp;

    if( tokens.front().second == OP_ASIGNACION ) {
        tokens.pop();
        exp = expresion_de_asignacion();
    }
    return exp;
}

void Sintactico::lista_param( DefinicionFuncion* def ) {
    if( error ) return;

    Tipo* tipo = especificador_tipo();
    def->parametros.push_back( new Parametro( tipo, declarador_init() ) );
    lista_param_prima( def );
}

void Sintactico::lista_param_prima( DefinicionFuncion* def ) {
    if( error ) return;

    if( tokens.front().second == COMA ) {
        tokens.pop();
        Tipo* tipo = especificador_tipo();
        def->parametros.push_back( new Parametro( tipo, declarador_init() ) );
        lista_param_prima( def );
    }
}

Tipo* Sintactico::especificador_tipo() {
    Tipo* exp = nullptr;
    if( error ) return exp;

    switch( reservados.find( tokens.front().first )->second ) {
    case INT:
    case VOID:
        exp = new Tipo( tokens.front().first );
        tokens.pop();
        break;
    default:
        marcarError( "Se esperaba el especificador int o void" );
        break;
    }
    return exp;
}

Expresion* Sintactico::expresion() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_de_asignacion();
    expresion_prima( exp );
    return exp;
}

/**
*   ¿Realmente se utiliza, donde y como solucionar?
*/
void Sintactico::expresion_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == COMA ) {
        tokens.pop();
        exp = expresion_de_asignacion();
        expresion_prima( exp );
    }
}

Expresion* Sintactico::expresion_de_asignacion() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_unaria();
    switch( tokens.front().second ) {
    case OP_ASIGNACION:
        tokens.pop();
        /** FALTA **/
        expresion_de_asignacion();
        break;
    case OP_MULTIPLICATIVO:
        expresion_multiplicativa_prima( exp );
    case OP_ADITIVO :
        expresion_aditiva_prima( exp );
    case OP_RELACIONAL:
        expresion_relacional_prima( exp );
    case OP_IGUALDAD:
        expresion_de_igualdad_prima( exp );
    case LOGICO_AND:
        expresion_logica_AND_prima( exp );
    case LOGICO_OR:
        expresion_logica_OR_prima( exp );
        break;
    default:
        break;
    }
    return exp;
}

Expresion* Sintactico::expresion_logica_OR() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_logica_AND();
    expresion_logica_OR_prima( exp );
    return exp;
}

void Sintactico::expresion_logica_OR_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == LOGICO_OR ) {
        tokens.pop();
        exp = new OR( exp, expresion_logica_AND() );
        expresion_logica_OR_prima( exp );
    }
}

Expresion* Sintactico::expresion_logica_AND() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_de_igualdad();
    expresion_logica_AND_prima( exp );
    return exp;
}

void Sintactico::expresion_logica_AND_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == LOGICO_AND ) {
        tokens.pop();
        exp = new AND( exp, expresion_de_igualdad() );
        expresion_logica_AND_prima( exp );
    }
}

Expresion* Sintactico::expresion_de_igualdad() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_relacional();
    expresion_de_igualdad_prima( exp );
    return exp;
}

void Sintactico::expresion_de_igualdad_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == OP_IGUALDAD ) {
        tokens.pop();
        if( tokens.front().first == "==" ) {
            exp = new Igual( exp, expresion_relacional() );
        } else {
            exp = new Diferente( exp, expresion_relacional() );
        }
        expresion_de_igualdad_prima( exp );
    }
}

Expresion* Sintactico::expresion_relacional() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_aditiva();
    expresion_relacional_prima( exp );
    return exp;
}

void Sintactico::expresion_relacional_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == OP_RELACIONAL ) {
        tokens.pop();
        if( tokens.front().first == "<" ) {
            exp = new Menor( exp, expresion_aditiva() );
        } else if( tokens.front().first == "<=" ) {
            exp = new MenorIgual( exp, expresion_aditiva() );
        } else if( tokens.front().first == ">" ) {
            exp = new Mayor( exp, expresion_aditiva() );
        } else {
            exp = new MayorIgual( exp, expresion_aditiva() );
        }
        expresion_relacional_prima( exp );
    }
}

Expresion* Sintactico::expresion_aditiva() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_multiplicativa();
    expresion_aditiva_prima( exp );

    return exp;
}

void Sintactico::expresion_aditiva_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == OP_ADITIVO ) {
        tokens.pop();
        if( tokens.front().first == "+" ) {
            exp = new Suma( exp, expresion_multiplicativa() );
        } else {
            exp = new Resta( exp, expresion_multiplicativa() );
        }
        expresion_aditiva_prima( exp );
    }
}

Expresion* Sintactico::expresion_multiplicativa() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_unaria();
    expresion_multiplicativa_prima( exp );

    return exp;
}

void Sintactico::expresion_multiplicativa_prima( Expresion* exp ) {
    if( error ) return;

    if( tokens.front().second == OP_MULTIPLICATIVO ) {
        tokens.pop();
        if( tokens.front().first == "*" ) {
            exp = new Multiplicacion( exp, expresion_unaria() );
        } else if( tokens.front().first == "/" ) {
            exp = new Division( exp, expresion_unaria() );
        } else {
            exp = new Modulo( exp, expresion_unaria() );
        }
        expresion_multiplicativa_prima( exp );
    }
}

Expresion* Sintactico::expresion_unaria() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    switch( tokens.front().second ) {
    case OP_INCREMENTO:
        tokens.pop();
        exp = new UnarioIncremento( expresion_unaria() );
        break;
    case OP_DECREMENTO:
        tokens.pop();
        exp = new UnarioDecremento( expresion_unaria() );
        break;
    case OP_ADITIVO:
        tokens.pop();
        /**  Falta el positivo */
        exp = new UnarioNegativo( expresion_unaria() );
        break;
    case LOGICO_NOT:
        tokens.pop();
        exp = new UnarioNot( expresion_unaria() );
        break;
    default:
        exp = expresion_posfija();
    }
    return exp;
}

Expresion* Sintactico::expresion_posfija() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    exp = expresion_primaria();
    expresion_posfija_prima( exp );

    return exp;
}

void Sintactico::expresion_posfija_prima( Expresion* exp ) {
    if( error ) return;

    switch( tokens.front().second ) {
    case OP_INCREMENTO:
        tokens.pop();
        exp = new PosfijoIncremento( exp );
        expresion_posfija_prima( exp );
        break;
    case OP_DECREMENTO:
        tokens.pop();
        exp = new PosfijoDecremento( exp );
        expresion_posfija_prima( exp );
        break;
    default:
        break;
    }
}

Expresion* Sintactico::expresion_primaria() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    switch( tokens.front().second ) {
    case IDENTIFICADOR:
        exp = new Identificador( tokens.front().first );
        tokens.pop();
        break;
    case ENTERO:
        exp = new Entero( tokens.front().first );
        tokens.pop();
        break;
    case PARENTESIS_IZQ:
        tokens.pop();
        exp = expresion();
        comprueba( PARENTESIS_DER );
        break;
    default:
        marcarError( "Se esperaba un Identificador, Numero o Parentesis de apertura" );
    }
    return exp;
}

If* Sintactico::proposicion_de_seleccion() {
    If* _if = nullptr;
    if( error ) return _if;

    if( tokens.front().first == "if" ) {
        tokens.pop();
        comprueba( PARENTESIS_IZQ );
        expresion();
        comprueba( PARENTESIS_DER );
        proposicion();
        proposicion_de_seleccion_else();
    }
    return _if;
}

void Sintactico::proposicion_de_seleccion_else() {
    if( error ) return;

    if( tokens.front().first == "else" ) {
        tokens.pop();
        proposicion();
    }
}

Nodo* Sintactico::proposicion() {
    Nodo* p = nullptr;
    if( error ) return p;

    if( p == nullptr ) p = proposicion_compuesta();
    if( p == nullptr ) p = proposicion_de_seleccion();
    if( p == nullptr ) p = proposicion_de_iteracion();
    if( p == nullptr ) p = proposicion_de_salto();
    /**
        Las siguiente condiciones provocarian un falso error:

        (*) '}' Se verifica que exista en proposicion_compuesta() por lista_de_proposiciones()
        (*) P. Reservada: las unicas palabras reservadas admitidas por las proposiciones ya
                se contemplaron en las funciones anteriores, si hay una P.R. debe validarla quien
                llamo a proposicion()
    **/
    if( tokens.front().second != LLAVE_DER && tokens.front().second != RESERVADO ) {
        if( p == nullptr ) p = proposicion_expresion();
    }
    return p;
}

ProposicionCompuesta* Sintactico::proposicion_compuesta() {
    ProposicionCompuesta* pc = nullptr;
    vector<Nodo*> vec;
    if( error ) return pc;

    if( tokens.front().second == LLAVE_IZQ ) {
        tokens.pop();
        lista_de_declaraciones( vec );
        lista_de_proposiciones( vec );
        pc = new ProposicionCompuesta( vec );
    }
    return pc;
}

void Sintactico::lista_de_proposiciones( vector<Nodo*>& vec ) {
    if( error ) return;

    if( tokens.front().second == LLAVE_DER ) {
        tokens.pop();
    } else {
        Nodo* p = proposicion();
        if( p != nullptr ) {
            vec.push_back( p );
        }
        lista_de_declaraciones( vec );
        lista_de_proposiciones( vec );
    }
}

Expresion* Sintactico::proposicion_expresion() {
    Expresion* exp = nullptr;
    if( error ) return exp;

    if( tokens.front().second == DELIMITADOR ) {
        tokens.pop();
    } else {
        expresion();
        comprueba( DELIMITADOR );
    }
    return exp;
}

Proposicion* Sintactico::proposicion_de_iteracion() {
    Proposicion* p = nullptr;
    if( error ) return p;

    switch( reservados.find( tokens.front().first )->second ) {
    case WHILE:
        tokens.pop();
        comprueba( PARENTESIS_IZQ );
        expresion();
        comprueba( PARENTESIS_DER );
        proposicion();
        break;
    case DO:
        tokens.pop();
        proposicion_compuesta();
        if( tokens.front().first == "while" ) {
            tokens.pop();
            comprueba( PARENTESIS_IZQ );
            expresion();
            comprueba( PARENTESIS_DER );
            comprueba( DELIMITADOR );
        } else {
            marcarError( "Se esperaba un \"while\" al termino de un \"do\"" );
        }
        break;
    case FOR:
        tokens.pop();
        comprueba( PARENTESIS_IZQ );
        proposicion_expresion();
        proposicion_expresion();
        for_post();
    default:
        break;
    }
    return p;

}

void Sintactico::for_post() {
    if( error ) return;

    if( tokens.front().second == PARENTESIS_DER ) {
        tokens.pop();
        proposicion();
    } else {
        expresion();
        if( tokens.front().second == PARENTESIS_DER ) {
            tokens.pop();
            proposicion();
        } else {
            marcarError( "Se esperaba un parentesis de cierre" );
        }
    }
}

Proposicion*  Sintactico::proposicion_de_salto() {
    if( error ) return nullptr;

    switch( reservados.find( tokens.front().first )->second ) {
    case CONTINUE:
    case BREAK:
        tokens.pop();
        comprueba( DELIMITADOR );
        break;
    case RETURN: {
        tokens.pop();
        Return* p = new Return();
        if( tokens.front().second == DELIMITADOR ) {
            tokens.pop();
        } else {
            p->exp = expresion();
            comprueba( DELIMITADOR );
        }
        return p;
    }
    default:
        break;
    }
    return nullptr;
}
