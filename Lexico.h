#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include "EntradaTablaSimbolo.h"

using namespace std;

typedef pair<string,int> EntradaTS;

enum Estado {
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12, Q13, Q14, Q15, Q16,
    Q17, Q18, Q19, Q20, Q21, Q22, Q23, Q24, Q25, Q26, Q27, Q28, K, NUMERO_ESTADOS
};

enum Entrada {
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16,
    E17, E18, E19, E20, E21, NUMERO_ENTRADAS
} ;

enum Token {
    IDENTIFICADOR, RESERVADO, ENTERO, OP_ADITIVO, OP_INCREMENTO, OP_DECREMENTO, OP_MULTIPLICATIVO,
    LOGICO_AND, LOGICO_OR, LOGICO_NOT, OP_ASIGNACION, OP_IGUALDAD, OP_RELACIONAL, COMA, DELIMITADOR,
    COMENTARIO, PARENTESIS_IZQ, PARENTESIS_DER, LLAVE_IZQ, LLAVE_DER, FIN_ENTRADA, ERROR,
    NUMERO_TOKENS
};

enum Salida {
    NO, SI
};

class Lexico {
private:
    int matriz[NUMERO_ESTADOS][NUMERO_ENTRADAS] = {
        {Q0, Q12, Q1, Q2, Q3, Q4, Q8, Q7, Q7, Q9, Q11, Q13, Q14, Q16, Q18, Q19, Q24, Q25, Q26, Q27, Q28, K},
        {K, K, Q1, Q1, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, Q2, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, Q5, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, Q6, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, Q23, Q20, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, Q10, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, Q12, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, Q15, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, Q15, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, Q17, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q21, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20},
        {Q20, Q20, Q20, Q20, Q20, Q20, Q22, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20, Q20},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {Q23, Q22, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23, Q23},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K}
    };
    /** Estando es un estado terminal, la entrada determina si el token ha finalizado */
    int salidas[NUMERO_ESTADOS][NUMERO_ENTRADAS] = {
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO}
    };
    set<string> reservados = {"auto", "break", "case", "char", "const", "continue", "default",
                              "do", "double", "else", "enum", "extern", "float", "for", "goto",
                              "if", "inline", "int", "long",  "register", "return", "short",
                              "signed",  "sizeof", "static", "struct", "switch", "typedef",
                              "union", "unsigned", "void", "volatile", "while"
                             };
    map<string, int> tablaSimbolos;
    string etiquetas[NUMERO_TOKENS];

    char caracter;
    int estado;
    int tipo;
    bool error;
    string simbolo;
    ifstream archivo;
    int idTabla;

    void fijaTipo( int );
    int transicion( char );
public:
    Lexico();
    ~Lexico();
    void sigSimbolo();
    void insertaSimbolo( string );
    bool hayError();
    bool fin();
    string dameSimbolo();
    int dameTipo();
    void generaEtiquetas();
    string toString();
    string toStringTablaSimbolos();
};
#endif // LEXICO_H_INCLUDED
