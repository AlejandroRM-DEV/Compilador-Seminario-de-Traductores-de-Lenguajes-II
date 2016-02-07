#include "Lexico.h"

Lexico::Lexico() {
    archivo.open( "entrada.c" );
    if ( archivo.is_open() ) {
        error = false;
        generaEtiquetas();
    } else {
        error = true;
    }
}

Lexico::~Lexico() {
    archivo.close();
    for( EntradaTablaSimbolo* entrada : tablaSimbolos ) {
        delete entrada;
    }
}

void Lexico::sigSimbolo() {
    int columna;
    char temp;

    do {
        temp = transicion( archivo.peek() );
        while ( temp == E0 || temp == E1 ) {
            archivo.get( caracter );
            temp = transicion( archivo.peek() );
        }

        estado = Q0;
        simbolo = "";
        error = false;

        while( true ) {
            columna = transicion( archivo.peek() );
            if( salidas[estado][columna] == SI ) {
                break;
            }
            estado = matriz[estado][columna];
            archivo.get( caracter );
            simbolo += caracter;

            if( estado == K ) {
                error = true;
                break;
            }
        }
    } while ( estado == Q19 ); // Ignora comentarios
    fijaTipo( estado );
}

int Lexico::transicion( char c ) {
    if( c == ' ' || c == '\t' || c == '\v' || c == '\f' ) {
        return E0;
    } else if( c == '\r' || c == '\n' ) {
        return E1;
    } else if( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) ||  c == '_' ) {
        return E2;
    } else if( c >= '0' && c <= '9' ) {
        return E3;
    } else if( c == '+' || c == '-' ) {
        return E4;
    } else if( c == '/'  ) {
        return E5;
    } else if( c == '*' ) {
        return E6;
    } else if( c == '%' ) {
        return E7;
    } else if( c == '&' ) {
        return E8;
    } else if( c == '|' ) {
        return E9;
    } else if( c == '!' ) {
        return E10;
    } else if( c == '=' ) {
        return E11;
    } else if( c == '<' || c == '>' ) {
        return E12;
    } else if( c == ',' ) {
        return E13;
    } else if( c == ';' ) {
        return E14;
    } else if( c == '(' ) {
        return E15;
    } else if( c == ')' ) {
        return E16;
    } else if( c == '{' ) {
        return E17;
    } else if( c == '}' ) {
        return E18;
    } else if( c == '$' ) {
        return E19;
    } else { // RESTO DE ASCII
        return E20;
    }
}

void Lexico::insertaSimbolo( string simbolo ) {
    for( EntradaTablaSimbolo* entrada : tablaSimbolos ) {
        if( entrada->nombre == simbolo ) {
            return;
        }
    }
    tablaSimbolos.push_back( new EntradaTablaSimbolo( simbolo ) );
}

void Lexico::fijaTipo( int estado ) {
    switch( estado ) {
    case Q1:
        if( reservados.find( simbolo ) != reservados.end() ) {
            tipo = RESERVADO;
        } else {
            tipo = IDENTIFICADOR;
            insertaSimbolo( simbolo );
        }
        break;
    case Q2:
        tipo = ENTERO;
        break;
    case Q3:
        tipo = OP_ADITIVO;
        break;
    case Q4:
    case Q5:
        tipo = OP_MULTIPLICATIVO;
        break;
    case Q7:
        tipo = LOGICO_AND;
        break;
    case Q9:
        tipo = LOGICO_OR;
        break;
    case Q10:
        tipo = LOGICO_NOT;
        break;
    case Q11:
        tipo = OP_ASIGNACION;
        break;
    case Q12:
        tipo = OP_IGUALDAD;
        break;
    case Q13:
    case Q14:
        tipo = OP_RELACIONAL;
        break;
    case Q15:
        tipo = COMA;
        break;
    case Q16:
        tipo = DELIMITADOR;
        break;
    case Q19:
        tipo = COMENTARIO;
        break;
    case Q21:
        tipo = PARENTESIS_IZQ;
        break;
    case Q22:
        tipo = PARENTESIS_DER;
        break;
    case Q23:
        tipo = LLAVE_IZQ;
        break;
    case Q24:
        tipo = LLAVE_DER;
        break;
    case Q25:
        tipo = FIN_ENTRADA;
        break;
    default:
        tipo = ERROR;
        break;
    }
}

bool Lexico::hayError() {
    return error;
}

bool Lexico::fin() {
    return simbolo == "$" || hayError();
}

string Lexico::dameSimbolo() {
    return simbolo;
}

int Lexico::dameTipo() {
    return tipo;
}

string Lexico::toString() {
    stringstream ss;

    ss << "[ " << etiquetas[tipo];
    if( tipo == IDENTIFICADOR ) {
        for( EntradaTablaSimbolo* entrada : tablaSimbolos ) {
            if( entrada->nombre == simbolo ) {
                ss << ", " << entrada->id;
                break;
            }
        }
    }
    ss << " ] [ " << simbolo << " ]";
    return ss.str();
}

void Lexico::generaEtiquetas() {
    etiquetas[IDENTIFICADOR] = "Identificador";
    etiquetas[RESERVADO] = "Reservado";
    etiquetas[ENTERO] = "Entero";
    etiquetas[OP_ADITIVO] = "OP Aditivo";
    etiquetas[OP_MULTIPLICATIVO] = "OP Multiplicativo";
    etiquetas[LOGICO_AND] = "Logico AND";
    etiquetas[LOGICO_OR] = "Logico OR";
    etiquetas[LOGICO_NOT] = "Logico NOT";
    etiquetas[OP_ASIGNACION] = "OP Asignacion";
    etiquetas[OP_IGUALDAD] = "OP Igualdad";
    etiquetas[OP_RELACIONAL] = "OP Relacional";
    etiquetas[COMA] = "Coma";
    etiquetas[DELIMITADOR] = "Delimitador";
    etiquetas[COMENTARIO] = "Comentario";
    etiquetas[PARENTESIS_IZQ] = "Parentesis izq.";
    etiquetas[PARENTESIS_DER] = "Parentesis der.";
    etiquetas[LLAVE_IZQ] = "Llave izq.";
    etiquetas[LLAVE_DER] = "Llave der.";
    etiquetas[FIN_ENTRADA] = "Fin de entrada";
    etiquetas[ERROR] = "Error";

}
