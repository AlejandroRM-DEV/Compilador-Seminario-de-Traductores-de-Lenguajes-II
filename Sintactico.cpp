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

void Sintactico::analiza() {
    unidad_traduccion();
}

void Sintactico::unidad_traduccion() {
    definicion();
    unidad_traduccion_prima();
}

void Sintactico::unidad_traduccion_prima() {
    if( error ) return;
    if( tokens.front().second != FIN_ENTRADA ) {
        definicion();
        unidad_traduccion_prima();
    }
}

void Sintactico::definicion() {
    if( error ) return;
    especificador_tipo();
    comprueba( IDENTIFICADOR );
    definicion_prima();
}

void Sintactico::definicion_prima() {
    if( error ) return;
    if( tokens.front().second == PARENTESIS_IZQ ) {
        tokens.pop();
        if( tokens.front().second == PARENTESIS_DER ) {
            tokens.pop();
            cuerpo_funcion();
        } else {
            lista_param();
            comprueba( PARENTESIS_DER );
            cuerpo_funcion();
        }
    } else {
        declarador_init_prima();
        lista_vars();
    }
}

void Sintactico::cuerpo_funcion() {
    if( error ) return;
    if( tokens.front().second == DELIMITADOR ) {
        tokens.pop();
    } else {
        proposicion_compuesta();
    }
}

void Sintactico::lista_vars() {
    if( error ) return;
    switch( tokens.front().second ) {
    case DELIMITADOR:
        tokens.pop();
        break;
    case COMA:
        tokens.pop();
        declarador_init();
        lista_vars();
        break;
    default:
        marcarError( "Se esperaba un \";\" o una \",\"" );
    }
}

void Sintactico::lista_de_declaraciones() {
    if( error ) return;
    switch( reservados.find( tokens.front().first )->second ) {
    case INT:
        especificador_tipo();
        declarador_init();
        lista_vars();
        lista_de_declaraciones();
        break;
    case VOID:
        marcarError( "La variable no puede ser de tipo \"void\", se esperaba un tipo \"int\"" );
        break;
    default:
        break;
    }
}

void Sintactico::declarador_init() {
    if( error ) return;
    comprueba( IDENTIFICADOR );
    declarador_init_prima();
}

void Sintactico::declarador_init_prima() {
    if( error ) return;
    if( tokens.front().second == OP_ASIGNACION ) {
        tokens.pop();
        expresion_de_asignacion();
    }
}

void Sintactico::lista_param() {
    if( error ) return;
    especificador_tipo();
    declarador_init();
    lista_param_prima();
}

void Sintactico::lista_param_prima() {
    if( error ) return;
    if( tokens.front().second == COMA ) {
        tokens.pop();
        especificador_tipo();
        declarador_init();
        lista_param_prima();
    }
}

void Sintactico::especificador_tipo() {
    if( error ) return;
    switch( reservados.find( tokens.front().first )->second ) {
    case INT:
    case VOID:
        tokens.pop();
        break;
    default:
        marcarError( "Se esperaba el especificador int o void" );
        break;
    }
}

void Sintactico::expresion() {
    if( error ) return;
    expresion_de_asignacion();
    expresion_prima();
}

void Sintactico::expresion_prima() {
    if( error ) return;
    if( tokens.front().second == COMA ) {
        tokens.pop();
        expresion_de_asignacion();
        expresion_prima();
    }
}

void Sintactico::expresion_de_asignacion() {
    if( error ) return;
    expresion_unaria();
    switch( tokens.front().second ) {
    case OP_ASIGNACION:
        tokens.pop();
        expresion_de_asignacion();
        break;
    case OP_MULTIPLICATIVO:
        expresion_multiplicativa_prima();
    case OP_ADITIVO :
        expresion_aditiva_prima();
    case OP_RELACIONAL:
        expresion_relacional_prima();
    case OP_IGUALDAD:
        expresion_de_igualdad_prima();
    case LOGICO_AND:
        expresion_logica_AND_prima();
    case LOGICO_OR:
        expresion_logica_OR_prima();
        break;
    default:
        break;
    }
}

void Sintactico::expresion_logica_OR() {
    if( error ) return;
    expresion_logica_AND();
    expresion_logica_OR_prima();
}

void Sintactico::expresion_logica_OR_prima() {
    if( error ) return;
    if( tokens.front().second == LOGICO_OR ) {
        tokens.pop();
        expresion_logica_AND();
        expresion_logica_OR_prima();
    }
}

void Sintactico::expresion_logica_AND() {
    if( error ) return;
    expresion_de_igualdad();
    expresion_logica_AND_prima();
}

void Sintactico::expresion_logica_AND_prima() {
    if( error ) return;
    if( tokens.front().second == LOGICO_AND ) {
        tokens.pop();
        expresion_de_igualdad();
        expresion_logica_AND_prima();
    }
}

void Sintactico::expresion_de_igualdad() {
    if( error ) return;
    expresion_relacional();
    expresion_de_igualdad_prima();
}

void Sintactico::expresion_de_igualdad_prima() {
    if( error ) return;
    if( tokens.front().second == OP_IGUALDAD ) {
        tokens.pop();
        expresion_relacional();
        expresion_de_igualdad_prima();
    }
}

void Sintactico::expresion_relacional() {
    if( error ) return;
    expresion_aditiva();
    expresion_relacional_prima();
}

void Sintactico::expresion_relacional_prima() {
    if( error ) return;
    if( tokens.front().second == OP_RELACIONAL ) {
        tokens.pop();
        expresion_aditiva();
        expresion_relacional_prima();
    }
}

void Sintactico::expresion_aditiva() {
    if( error ) return;
    expresion_multiplicativa();
    expresion_aditiva_prima();
}

void Sintactico::expresion_aditiva_prima() {
    if( error ) return;
    if( tokens.front().second == OP_ADITIVO ) {
        tokens.pop();
        expresion_multiplicativa();
        expresion_aditiva_prima();
    }
}

void Sintactico::expresion_multiplicativa() {
    if( error ) return;
    expresion_unaria();
    expresion_multiplicativa_prima();
}

void Sintactico::expresion_multiplicativa_prima() {
    if( error ) return;
    if( tokens.front().second == OP_MULTIPLICATIVO ) {
        tokens.pop();
        expresion_unaria();
        expresion_multiplicativa_prima();
    }
}

void Sintactico::expresion_unaria() {
    if( error ) return;
    switch( tokens.front().second ) {
    case OP_INCREMENTO:
    case OP_DECREMENTO:
    case OP_ADITIVO:
    case LOGICO_NOT:
        tokens.pop();
        expresion_unaria();
        break;
    default:
        expresion_posfija();
    }
}

void Sintactico::expresion_posfija() {
    if( error ) return;
    expresion_primaria();
    expresion_posfija_prima();
}

void Sintactico::expresion_posfija_prima() {
    if( error ) return;
    switch( tokens.front().second ) {
    case OP_INCREMENTO:
    case OP_DECREMENTO:
        tokens.pop();
        expresion_posfija_prima();
        break;
    default:
        break;
    }
}

void Sintactico::expresion_primaria() {
    if( error ) return;
    switch( tokens.front().second ) {
    case IDENTIFICADOR:
    case ENTERO:
        tokens.pop();
        break;
    case PARENTESIS_IZQ:
        tokens.pop();
        expresion();
        comprueba( PARENTESIS_DER );
        break;
    default:
        marcarError( "Se esperaba un Identificador, Numero o Parentesis de apertura" );
    }
}

void Sintactico::lista_expresiones_argumento() {
    if( error ) return;
    expresion_de_asignacion();
    lista_expresiones_argumento_prima();
}

void Sintactico::lista_expresiones_argumento_prima() {
    if( error ) return;
    if( tokens.front().second == COMA ) {
        tokens.pop();
        expresion_de_asignacion();
        lista_expresiones_argumento_prima();
    }
}

void Sintactico::proposicion_de_seleccion() {
    if( error ) return;
    if( tokens.front().first == "if" ) {
        tokens.pop();
        comprueba( PARENTESIS_IZQ );
        expresion();
        comprueba( PARENTESIS_DER );
        proposicion();
        proposicion_de_seleccion_else();
    }
}

void Sintactico::proposicion_de_seleccion_else() {
    if( error ) return;
    if( tokens.front().first == "else" ) {
        tokens.pop();
        proposicion();
    }
}

void Sintactico::proposicion() {
    if( error ) return;
    proposicion_compuesta();
    proposicion_de_seleccion();
    proposicion_de_iteracion();
    proposicion_de_salto();
    /**
        Las siguiente condiciones provocarian un falso error:

        (*) '}' Se verifica que exista en proposicion_compuesta();
        (*) P. Reservada: las unicas palabras reservadas admitidas por las proposiciones ya
                se contemplaron en las funciones anteriores, ademas excluir las P.R. que en la
                gramatica aparezcan despues de proposicion() (p. ej. "else")
    **/
    if( tokens.front().second != LLAVE_DER && tokens.front().second != RESERVADO ) {
        proposicion_expresion();
    }
}

void Sintactico::proposicion_compuesta() {
    if( error ) return;
    if( tokens.front().second == LLAVE_IZQ ) {
        tokens.pop();
        lista_de_declaraciones();
        lista_de_proposiciones();
    }
}

void Sintactico::lista_de_proposiciones() {
    if( error ) return;
    if( tokens.front().second == LLAVE_DER ) {
        tokens.pop();
    } else {
        proposicion();
        lista_de_declaraciones();
        lista_de_proposiciones();
    }
}

void Sintactico::proposicion_expresion() {
    if( error ) return;
    if( tokens.front().second == DELIMITADOR ) {
        tokens.pop();
    } else {
        expresion();
        comprueba( DELIMITADOR );
    }
}

void Sintactico::proposicion_de_iteracion() {
    if( error ) return;
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

void Sintactico::proposicion_de_salto() {
    if( error ) return;
    switch( reservados.find( tokens.front().first )->second ) {
    case CONTINUE:
    case BREAK:
        tokens.pop();
        comprueba( DELIMITADOR );
        break;
    case RETURN:
        tokens.pop();
        if( tokens.front().second == DELIMITADOR ) {
            tokens.pop();
        } else {
            expresion();
            comprueba( DELIMITADOR );
        }
        break;
    default:
        break;
    }
}
