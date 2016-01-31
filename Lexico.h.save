#ifndef LEXICO_H_INCLUDED
#define LEXICO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

enum Estado {
    Q0, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11, Q12, Q13, Q14, Q15, Q16,
    Q17, Q18, Q19, Q20, K, NUMERO_ESTADOS
};

enum Entrada {
    E0, E1, E2, E3, E4, E5, E6, E7, E8, E9, E10, E11, E12, E13, E14, E15, E16,
    E17, NUMERO_ENTRADAS
} ;

enum Token {
    IDENTIFICADOR, ENTERO, COMENTARIO, SEPARADOR, OP_ADICION, OP_MULTIPLICACION,
    PARENTESIS, DELIMITADOR, FIN_ENTRADA, OP_LOGICO, OP_ASIGNACION,
    OP_RELACIONAL, RESERVADO, ERROR, NUMERO_TOKENS
};

enum Salida {
    NO, SI
};

class Lexico {
private:
    int matriz[NUMERO_ESTADOS][NUMERO_ENTRADAS] = {
        {Q0, Q0, Q1, Q2, Q6, Q7, Q3, Q8, Q8, Q9, Q10, Q11, Q12, Q14, Q15, Q16, Q17, K},
        {K, K, Q1, Q1, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, Q2, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, Q4, Q19, K, K, K, K, K, K, K, K, K, K},
        {Q4, Q5, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4, Q4},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, Q13, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, Q13, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, Q18, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, Q18, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, Q18, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K},
        {Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q20, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19, Q19},
        {K, K, K, K, K, K, Q5, K, K, K, K, K, K, K, K, K, K, K},
        {K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K, K}
    };
    /** Estando es un estado terminal, la entrada determina si el token a finalizado */
    int salidas[NUMERO_ESTADOS][NUMERO_ENTRADAS] = {
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, NO, NO, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, NO, SI, SI},
        {SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI, SI},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
        {NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO}
    };
    set<string> reservados = {"int", "if", "else", "while", "do", "for", "void",
                              "return"
                             };
    char caracter;
    int estado;
    int tipo;
    bool error;
    string simbolo;
    ifstream archivo;

    void fijaTipo( int estado );
    int transicion( char c );
public:
    Lexico();
    ~Lexico();
    void sigSimbolo();
    bool hayError();
    bool fin();
    string dameSimbolo();
    int dameTipo();
    string toString();
};
#endif // LEXICO_H_INCLUDED
