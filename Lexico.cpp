#include "Lexico.h"

void Lexico::fijaTipo( int estado ) {
    switch( estado ) {
    case Q1:
        if( reservados.find( simbolo ) != reservados.end() ) {
            tipo = RESERVADO;
        } else {
            tipo = IDENTIFICADOR;
        }
        break;
    case Q2:
        tipo = ENTERO;
        break;
    case Q5:
        tipo = COMENTARIO;
        break;
    case Q6:
        tipo = SEPARADOR;
        break;
    case Q7:
        tipo = OP_ADICION;
        break;
    case Q3:
    case Q8:
        tipo = OP_MULTIPLICACION;
        break;
    case Q9:
        tipo = PARENTESIS;
        break;
    case Q10:
        tipo = DELIMITADOR;
        break;
    case Q11:
        tipo = FIN_ENTRADA;
        break;
    case Q13:
    case Q15:
        tipo = OP_LOGICO;
        break;
    case Q16:
        tipo = OP_ASIGNACION;
        break;
    case Q17:
    case Q18:
        tipo = OP_RELACIONAL;
        break;
    default:
        tipo = ERROR;
        break;
    }
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
    } else if( c == ',' ) {
        return E4;
    } else if( c == '+' || c == '-' ) {
        return E5;
    } else if( c == '/'  ) {
        return E6;
    } else if( c == '*' ) {
        return E7;
    } else if( c == '%' ) {
        return E8;
    } else if( c == '(' || c == ')' || c == '{' || c == '}' ) {
        return E9;
    } else if( c == ';' ) {
        return E10;
    } else if( c == '$' ) {
        return E11;
    } else if( c == '|' ) {
        return E12;
    } else if( c == '&' ) {
        return E13;
    } else if( c == '!' ) {
        return E14;
    } else if( c == '=' ) {
        return E15;
    } else if( c == '<' || c == '>' ) {
        return E16;
    } else { // RESTO DE ASCII
        return E17;
    }
}

Lexico::Lexico() {
    archivo.open( "entrada.txt" );
    if ( !archivo.is_open() ) {
        error = true;
    } else {
        error = false;
    }
}

Lexico::~Lexico() {
    archivo.close();
}

void Lexico::sigSimbolo() {
    int columna;
    char temp = transicion( archivo.peek() );

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
        if( estado == K ) {
            error = true;
            break;
        }
        archivo.get( caracter );
        simbolo += caracter;
    }
    fijaTipo( estado );
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
    string strTipo;
    switch( tipo ) {
    case IDENTIFICADOR:
        strTipo = "Identificador";
        break;
    case ENTERO:
        strTipo = "Entero";
        break;
    case COMENTARIO:
        strTipo = "Comentario";
        break;
    case SEPARADOR:
        strTipo = "Separador";
        break;
    case OP_ADICION:
        strTipo = "Operador de adicion (+, -)";
        break;
    case OP_MULTIPLICACION:
        strTipo = "Operador de multiplicacion (*, /, %)";
        break;
    case PARENTESIS:
        strTipo = "Parentesis";
        break;
    case DELIMITADOR:
        strTipo = "Delimitador";
        break;
    case FIN_ENTRADA:
        strTipo = "Fin de entrada";
        break;
    case OP_LOGICO:
        strTipo = "Operador logico";
        break;
    case OP_ASIGNACION:
        strTipo = "Operador de asignacion";
        break;
    case OP_RELACIONAL:
        strTipo = "Operador relacional";
        break;
    case RESERVADO:
        strTipo = "Palabra reservada";
        break;
    default:
        strTipo = "Error";
        break;
    }
    return "Tipo:\t " + strTipo + "\r\nSimbolo: " + simbolo;
}
