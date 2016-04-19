#ifndef AST_TIPOS_H_INCLUDED
#define AST_TIPOS_H_INCLUDED

#include <vector>
#include <iostream>
#include <sstream>

#include "TablaSimbolos.h"

using namespace std;

class Nodo {
public:
    string simbolo;
    TipoDato dato;
    Nodo() {}
    virtual ~Nodo() {}
    virtual TipoDato analizarTipo() = 0;
    virtual string toString() = 0;
};

class Tipo: public Nodo {
public:
    Tipo( string simbolo );
    ~Tipo();
    TipoDato analizarTipo();
    string toString() ;
};

class Expresion: public Nodo {
public:
    Expresion* izquierda;
    Expresion* derecha;

    Expresion();
    virtual ~Expresion();
    TipoDato analizarTipo() = 0;
    string toString() = 0;
};

class Identificador: public Expresion {
public:
    Identificador( string simbolo );
    ~Identificador();
    TipoDato analizarTipo();
    string toString();
};

class Entero: public Expresion {
public:
    Entero( string simbolo );
    ~Entero();
    TipoDato analizarTipo();
    string toString();
};

class OR: public Expresion {
public:
    OR( Expresion* izquierda, Expresion* derecha );
    ~OR();
    TipoDato analizarTipo();
    string toString();
};

class AND: public Expresion {
public:
    AND( Expresion* izquierda, Expresion* derecha ) ;
    ~AND();
    TipoDato analizarTipo();
    string toString();
};

class Igual: public Expresion {
public:
    Igual( Expresion* izquierda, Expresion* derecha );
    ~Igual();
    TipoDato analizarTipo();
    string toString();
};

class Diferente: public Expresion {
public:
    Diferente( Expresion* izquierda, Expresion* derecha );
    ~Diferente();
    TipoDato analizarTipo();
    string toString() ;
};

class Menor: public Expresion {
public:
    Menor( Expresion* izquierda, Expresion* derecha );
    ~Menor();
    TipoDato analizarTipo();
    string toString();
};

class MenorIgual: public Expresion {
public:
    MenorIgual( Expresion* izquierda, Expresion* derecha );
    ~MenorIgual();
    TipoDato analizarTipo();
    string toString();
};

class Mayor: public Expresion {
public:
    Mayor( Expresion* izquierda, Expresion* derecha );
    ~Mayor();
    TipoDato analizarTipo();
    string toString();
};

class MayorIgual: public Expresion {
public:
    MayorIgual( Expresion* izquierda, Expresion* derecha );
    ~MayorIgual();
    TipoDato analizarTipo();
    string toString();
};

class Suma: public Expresion {
public:
    Suma( Expresion* izquierda, Expresion* derecha );
    ~Suma();
    TipoDato analizarTipo();
    string toString();
};

class Resta: public Expresion {
public:
    Resta( Expresion* izquierda, Expresion* derecha );
    ~Resta();
    TipoDato analizarTipo();
    string toString();
};

class Multiplicacion: public Expresion {
public:
    Multiplicacion( Expresion* izquierda, Expresion* derecha );
    ~Multiplicacion();
    TipoDato analizarTipo();
    string toString();
};

class Division: public Expresion {
public:
    Division( Expresion* izquierda, Expresion* derecha );
    ~Division();
    TipoDato analizarTipo();
    string toString() ;
};

class Modulo: public Expresion {
public:
    Modulo( Expresion* izquierda, Expresion* derecha );
    ~Modulo();
    TipoDato analizarTipo();
    string toString();
};

class Asignacion: public Expresion {
public:
    Identificador* id;
    Expresion* expresion;

    Asignacion( Identificador* id, Expresion* expresion );
    TipoDato analizarTipo();
    ~Asignacion();
    string toString();
};

class PosfijoIncremento: public Expresion {
public:
    Expresion* exp;

    PosfijoIncremento( Expresion* exp );
    ~PosfijoIncremento( );
    TipoDato analizarTipo();
    string toString();
};

class PosfijoDecremento: public Expresion {
public:
    Expresion* exp;

    PosfijoDecremento( Expresion* exp );
    ~PosfijoDecremento( );
    TipoDato analizarTipo();
    string toString();
};

class UnarioIncremento: public Expresion {
public:
    Expresion* exp;

    UnarioIncremento( Expresion* exp ) ;
    ~UnarioIncremento( );
    TipoDato analizarTipo();
    string toString();
};

class UnarioDecremento: public Expresion {
public:
    Expresion* exp;

    UnarioDecremento( Expresion* exp ) ;
    ~UnarioDecremento( );
    TipoDato analizarTipo();
    string toString();
};

class UnarioNot: public Expresion {
public:
    Expresion* exp;

    UnarioNot( Expresion* exp ) ;
    ~UnarioNot( );
    TipoDato analizarTipo();
    string toString();
};

class UnarioNegativo: public Expresion {
public:
    Expresion* exp;

    UnarioNegativo( Expresion* exp ) ;
    ~UnarioNegativo( );
    TipoDato analizarTipo();
    string toString();
};

class UnarioPositivo: public Expresion {
public:
    Expresion* exp;

    UnarioPositivo( Expresion* exp );
    ~UnarioPositivo( ) ;
    TipoDato analizarTipo();
    string toString();
};

class Definicion: public Nodo {
public:
    Tipo* tipo;

    Definicion( Tipo* tipo );
    virtual ~Definicion();
    virtual TipoDato analizarTipo() = 0;
    virtual string toString() = 0;
};

class Parametro: public Nodo {
public:
    Tipo* tipo;
    Identificador* id;

    Parametro( Tipo* tipo, Identificador* id );
    ~Parametro();
    TipoDato analizarTipo();
    string toString();
};

class DefinicionVariable: public Definicion {
public:
    vector<Asignacion*> asignaciones;

    DefinicionVariable( Tipo* tipo ): Definicion( tipo ) {}

    ~DefinicionVariable();
    TipoDato analizarTipo();
    string toString();
};

class Proposicion: public Nodo {
public:
    Proposicion() {}
    virtual ~Proposicion() {}
    virtual string toString() = 0;
};

class If: public Proposicion {
public:
    Expresion* exp;
    Nodo* proIf;
    Nodo* proElse;

    If();
    ~If();
    TipoDato analizarTipo();
    string toString();
};

class Continue: public Proposicion {
public:
    Continue();
    ~Continue();
    TipoDato analizarTipo();
    string toString();
};

class Break: public Proposicion {
public:
    Break();
    ~Break();
    TipoDato analizarTipo();
    string toString();
};

class Return: public Proposicion {
public:
    static bool permiteExpresion;
    Expresion* exp;

    Return();
    ~Return();
    TipoDato analizarTipo();
    string toString() ;
};

class ProposicionCompuesta: public Proposicion {
public:
    vector<Nodo*> cuerpo;

    ProposicionCompuesta( vector<Nodo*> cuerpo );
    ~ProposicionCompuesta() ;
    TipoDato analizarTipo();
    string toString();
};

class DoWhile: public Proposicion {
public:
    Expresion* exp;
    ProposicionCompuesta* proposicion;

    DoWhile();
    ~DoWhile();
    TipoDato analizarTipo();
    string toString();
};

class For: public Proposicion {
public:
    Expresion* pre;
    Expresion* exp;
    Expresion* post;
    Nodo* proposicion;

    For();
    ~For();
    TipoDato analizarTipo();
    string toString();
};

class While: public Proposicion {
public:
    Expresion* exp;
    Nodo* proposicion;

    While();
    ~While();
    TipoDato analizarTipo();
    string toString();
};

class DefinicionFuncion: public Definicion {
public:
    Identificador* id;
    vector<Parametro*> parametros;
    ProposicionCompuesta* cuerpo;

    DefinicionFuncion( Tipo* tipo, Identificador* id );
    ~DefinicionFuncion();
    TipoDato analizarTipo();
    string toString();
};

class LlamadaFuncion: public Expresion {
public:
    Identificador* id;
    vector<Expresion*> parametros;

    LlamadaFuncion( Identificador* id );
    ~LlamadaFuncion();
    TipoDato analizarTipo();
    string toString();
};

class UnidadTraduccion: public Nodo {
public:
    vector<Definicion*> definiciones;

    UnidadTraduccion();
    ~UnidadTraduccion();
    TipoDato analizarTipo();
    string toString();
};

#endif // AST_TIPOS_H_INCLUDED
