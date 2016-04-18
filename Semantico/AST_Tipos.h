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
    Tipo( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Tipo() {}

    TipoDato analizarTipo() {
        if( simbolo == "int" ) {
            return T_INT;
        } else {
            return T_VOID;
        }
    }

    string toString() {
        stringstream ss;
        ss << "<TIPO>" << simbolo << "</TIPO>" << endl;
        return ss.str();
    }
};

class Expresion: public Nodo {
public:
    Expresion* izquierda;
    Expresion* derecha;

    Expresion() {
        izquierda = nullptr;
        derecha = nullptr;
    }

    virtual ~Expresion() {
        if( izquierda != nullptr ) {
            delete izquierda;
        };
        if( derecha != nullptr ) {
            delete derecha;
        };
    }

    TipoDato analizarTipo() = 0;
    string toString() = 0;
};

class Identificador: public Expresion {
public:
    Identificador( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Identificador() {}

    TipoDato analizarTipo() {
        return TablaSimbolos::instance()->tipoSim( simbolo );
    }

    string toString() {
        stringstream ss;
        ss << "<ID>" << simbolo << "</ID>" << endl;
        return ss.str();
    }
};

class Entero: public Expresion {
public:
    Entero( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Entero() {}

    TipoDato analizarTipo() {
        return T_INT;
    }

    string toString() {
        stringstream ss;
        ss << "<ENTERO>" << simbolo << "</ENTERO>" << endl;
        return ss.str();
    }
};

class OR: public Expresion {
public:
    OR( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "||";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~OR() {}

    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }

    string toString() {
        stringstream ss;
        ss << "<OR>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</OR>" << endl;
        return ss.str();
    }
};

class AND: public Expresion {
public:
    AND( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "&&";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~AND() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<AND>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</AND>" << endl;
        return ss.str();
    }
};

class Igual: public Expresion {
public:
    Igual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "==";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Igual() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<IGUALDAD>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</IGUALDAD>" << endl;
        return ss.str();
    }
};

class Diferente: public Expresion {
public:
    Diferente( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "!=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Diferente() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<DIFERENTE>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</DIFERENTE>" << endl;
        return ss.str();
    }
};

class Menor: public Expresion {
public:
    Menor( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "<";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Menor() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MENOR>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MENOR>" << endl;
        return ss.str();
    }
};

class MenorIgual: public Expresion {
public:
    MenorIgual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "<=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~MenorIgual() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MENOR_IGUAL>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MENOR_IGUAL>" << endl;
        return ss.str();
    }
};

class Mayor: public Expresion {
public:
    Mayor( Expresion* izquierda, Expresion* derecha ) {
        simbolo = ">";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Mayor() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MAYOR>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MAYOR>" << endl;
        return ss.str();
    }
};

class MayorIgual: public Expresion {
public:
    MayorIgual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = ">=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~MayorIgual() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MAYOR_IGUAL>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MAYOR_IGUAL>" << endl;
        return ss.str();
    }
};

class Suma: public Expresion {
public:
    Suma( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "+";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Suma() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<SUMA>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</SUMA>" << endl;
        return ss.str();
    }
};

class Resta: public Expresion {
public:
    Resta( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "-";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Resta() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<RESTA>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</RESTA>" << endl;
        return ss.str();
    }
};

class Multiplicacion: public Expresion {
public:
    Multiplicacion( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "*";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Multiplicacion() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MULTIPLICACION>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MULTIPLICACION>" << endl;
        return ss.str();
    }
};

class Division: public Expresion {
public:
    Division( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "/";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Division() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<DIVISION>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</DIVISION>" << endl;
        return ss.str();
    }
};

class Modulo: public Expresion {
public:
    Modulo( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "%";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Modulo() {}
    TipoDato analizarTipo() {
        if( izquierda->analizarTipo() == derecha->analizarTipo() ) {
            return izquierda->analizarTipo();
        } else {
            return T_ERROR;
        }
    }
    string toString() {
        stringstream ss;
        ss << "<MODULO>" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( );
        }
        ss << "</MODULO>" << endl;
        return ss.str();
    }
};

class Asignacion: public Expresion {
public:
    Identificador* id;
    Expresion* expresion;

    Asignacion( Identificador* id, Expresion* expresion ) {
        this->id = id;
        this->expresion = expresion;
    }

    TipoDato analizarTipo() {
        if( id->analizarTipo() == expresion->analizarTipo() ) {
            return id->analizarTipo();
        } else {
            return T_ERROR;
        }
    }

    ~Asignacion() {
        if( id != nullptr ) {
            delete id;
        };
        if( expresion != nullptr ) {
            delete expresion;
        };
    }

    string toString() {
        stringstream ss;

        ss << "<ASIGNACION>" << endl;
        ss << id->toString();

        if( expresion != nullptr ) {
            ss << "<EXPRESION>" << endl;
            ss << expresion->toString( );
            ss << "</EXPRESION>" << endl;
        }
        ss << "</ASIGNACION>" << endl;

        return ss.str();
    }
};

class PosfijoIncremento: public Expresion {
public:
    Expresion* exp;

    PosfijoIncremento( Expresion* exp ) {
        this->exp = exp;
    }

    ~PosfijoIncremento( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<POSFIJO_INCREMENTO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</POSFIJO_INCREMENTO>" << endl;
        return ss.str();
    }
};

class PosfijoDecremento: public Expresion {
public:
    Expresion* exp;

    PosfijoDecremento( Expresion* exp ) {
        this->exp = exp;
    }

    ~PosfijoDecremento( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<POSFIJO_DECREMENTO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</POSFIJO_DECREMENTO>" << endl;
        return ss.str();
    }
};

class UnarioIncremento: public Expresion {
public:
    Expresion* exp;

    UnarioIncremento( Expresion* exp ) {
        this->exp = exp;
    }

    ~UnarioIncremento( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<UNARIO_INCREMENTO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</UNARIO_INCREMENTO>" << endl;
        return ss.str();
    }
};

class UnarioDecremento: public Expresion {
public:
    Expresion* exp;

    UnarioDecremento( Expresion* exp ) {
        this->exp = exp;
    }

    ~UnarioDecremento( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<UNARIO_DECREMENTO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</UNARIO_DECREMENTO>" << endl;
        return ss.str();
    }
};

class UnarioNot: public Expresion {
public:
    Expresion* exp;

    UnarioNot( Expresion* exp ) {
        this->exp = exp;
    }

    ~UnarioNot( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<UNARIO_NOT>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</UNARIO_NOT>" << endl;
        return ss.str();
    }
};

class UnarioNegativo: public Expresion {
public:
    Expresion* exp;

    UnarioNegativo( Expresion* exp ) {
        this->exp = exp;
    }

    ~UnarioNegativo( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<UNARIO_NEGATIVO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</UNARIO_NEGATIVO>" << endl;
        return ss.str();
    }
};

class UnarioPositivo: public Expresion {
public:
    Expresion* exp;

    UnarioPositivo( Expresion* exp ) {
        this->exp = exp;
    }

    ~UnarioPositivo( ) {
        delete exp;
    }
    TipoDato analizarTipo() {
        return exp->analizarTipo();
    }
    string toString() {
        stringstream ss;
        ss << "<UNARIO_POSITIVO>" << endl;

        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</UNARIO_POSITIVO>" << endl;
        return ss.str();
    }
};

class Definicion: public Nodo {
public:
    Tipo* tipo;

    Definicion( Tipo* tipo ) {
        this->tipo = tipo;
    }

    virtual ~Definicion() {
        if( tipo != nullptr ) {
            delete tipo;
        };
    }

    virtual TipoDato analizarTipo() = 0;
    virtual string toString() = 0;
};

class Parametro: public Nodo {
public:
    Tipo* tipo;
    Identificador* id;

    Parametro( Tipo* tipo, Identificador* id ) {
        this->tipo = tipo;
        this->id = id;
    }

    ~Parametro() {
        delete tipo;
        delete id;
    }
    TipoDato analizarTipo() {
        return tipo->analizarTipo();
    }
    string toString() {
        stringstream ss;

        ss << "<PARAMETRO>" << endl;

        ss << tipo->toString();
        ss << id->toString( );
        ss << "</PARAMETRO>" << endl;
        return ss.str();
    }
};

class DefinicionVariable: public Definicion {
public:
    vector<Asignacion*> asignaciones;

    DefinicionVariable( Tipo* tipo ): Definicion( tipo ) {}

    ~DefinicionVariable() {
        for( Asignacion* a : asignaciones ) {
            delete a;
        }
    }

    TipoDato analizarTipo() {
        for( Asignacion* a : asignaciones ) {
            TablaSimbolos::instance()->agregarVariable( a->id->simbolo, tipo->analizarTipo() );
            if( a->expresion != nullptr ) {
                if( a->analizarTipo( ) == T_ERROR ) {
                    return T_ERROR;
                }
            }
        }
        return T_VACIO;
    }
    string toString() {
        stringstream ss;

        ss << "<DEFINICION_VARIABLE>" << endl;
        ss << tipo->toString();
        for( Asignacion* a : asignaciones ) {
            ss << "<ELEMENTO>"  << endl << a->id->toString() << "</ELEMENTO>" << endl;
            if( a->expresion != nullptr )
                ss << a->toString();
        }
        ss << "</DEFINICION_VARIABLE>" << endl;


        return ss.str();
    }
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

    If() {
        exp = nullptr;
        proIf = nullptr;
        proElse = nullptr;
    }

    ~If() {
        delete exp;
        if( proIf != nullptr ) {
            delete proIf;
        }
        if( proElse != nullptr ) {
            delete proElse;
        }
    }

    TipoDato analizarTipo() {
        if( exp->analizarTipo() == T_ERROR ){
            return T_ERROR;
        }
        if( proIf != nullptr ){
            TablaSimbolos::instance()->agregaContextoAnonimo();
            if( proIf->analizarTipo() == T_ERROR){
                return T_ERROR;
            }
            TablaSimbolos::instance()->quitaContexto();
        }
        if( proElse != nullptr ){
            TablaSimbolos::instance()->agregaContextoAnonimo();
            if( proElse->analizarTipo() == T_ERROR){
                return T_ERROR;
            }
            TablaSimbolos::instance()->quitaContexto();
        }
        return T_VACIO;
    }

    string toString() {
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
};

class Continue: public Proposicion {
public:
    Continue() {
        simbolo = "continue";
    }

    ~Continue() {}

    TipoDato analizarTipo() {
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<CONTINUE></CONTINUE>" << endl;
        return ss.str();
    }
};

class Break: public Proposicion {
public:
    Break() {
        simbolo = "break";
    }

    ~Break() {}

    TipoDato analizarTipo() {
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<BREAK></BREAK>" << endl;
        return ss.str();
    }
};

class Return: public Proposicion {
public:
    Expresion* exp;

    Return() {
        simbolo = "return";
        exp = nullptr;
    }

    ~Return() {
        if( exp != nullptr ) {
            delete exp;
        }
    }

    TipoDato analizarTipo() {
        if( exp != nullptr ) {
            return exp->analizarTipo();
        }
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<RETURN>" << endl;
        if( exp != nullptr ) {
            ss << exp->toString( );
        }
        ss << "</RETURN>" << endl;
        return ss.str();
    }
};

class ProposicionCompuesta: public Proposicion {
public:
    vector<Nodo*> cuerpo;

    ProposicionCompuesta( vector<Nodo*> cuerpo ) {
        this->cuerpo = cuerpo;
    }

    ~ProposicionCompuesta() {
        for( Nodo* nodo : cuerpo ) {
            delete nodo;
        }
    }

    TipoDato analizarTipo() {
        for( Nodo* n : cuerpo ) {
            if( n->analizarTipo( ) == T_ERROR ) {
                return T_ERROR;
            }
        }
        return T_VACIO;
    }

    string toString() {
        stringstream ss;

        ss << "<PROPOSICION_COMPUESTA>" << endl;
        for( Nodo* n : cuerpo ) {
            ss << n->toString();
        }
        ss << "</PROPOSICION_COMPUESTA>" << endl;
        return ss.str();
    }
};

class DoWhile: public Proposicion {
public:
    Expresion* exp;
    ProposicionCompuesta* proposicion;

    DoWhile() {
        exp = nullptr;
        proposicion = nullptr;
    }

    ~DoWhile() {
        delete exp;
        delete proposicion;
    }

    TipoDato analizarTipo() {
        TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proposicion->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
        if( exp->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<DO_WHILE>" << endl;
        ss << proposicion->toString();
        ss << "<EXPRESION>" << endl;
        ss << exp->toString( );
        ss << "</EXPRESION>" << endl;
        ss << "</DO_WHILE>" << endl;
        return ss.str();
    }
};

class For: public Proposicion {
public:
    Expresion* pre;
    Expresion* exp;
    Expresion* post;
    Nodo* proposicion;

    For() {
        pre = nullptr;
        exp = nullptr;
        post = nullptr;
        proposicion = nullptr;
    }

    ~For() {
        if( pre != nullptr ) delete pre;
        if( exp != nullptr )  delete exp;
        if( post != nullptr ) delete post;
        delete proposicion;
    }

    TipoDato analizarTipo() {
        if( pre != nullptr && pre->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
         if( exp != nullptr && exp->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
         if( post != nullptr && post->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proposicion->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<FOR>" << endl;
        if( pre != nullptr ) ss << pre->toString();
        if( exp != nullptr ) ss << exp->toString();
        if( post != nullptr ) ss << post->toString();
        ss << proposicion->toString( );
        ss << "</FOR>" << endl;
        return ss.str();
    }
};

class While: public Proposicion {
public:
    Expresion* exp;
    Nodo* proposicion;

    While() {
        exp = nullptr;
        proposicion = nullptr;
    }

    ~While() {
        delete exp;
        delete proposicion;
    }

    TipoDato analizarTipo() {
        if( exp->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        TablaSimbolos::instance()->agregaContextoAnonimo();
        if( proposicion->analizarTipo() == T_ERROR){
            return T_ERROR;
        }
        TablaSimbolos::instance()->quitaContexto();
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<WHILE>" << endl;
        ss << "<EXPRESION>" << endl;
        ss << exp->toString();
        ss << "</EXPRESION>" << endl;
        ss << proposicion->toString( );
        ss << "</WHILE>" << endl;
        return ss.str();
    }
};

class DefinicionFuncion: public Definicion {
public:
    Identificador* id;
    vector<Parametro*> parametros;
    ProposicionCompuesta* cuerpo;

    DefinicionFuncion( Tipo* tipo, Identificador* id ): Definicion( tipo ) {
        this->id = id;
        cuerpo = nullptr;
    }
    ~DefinicionFuncion() {
        delete id;
        for( Parametro* p : parametros ) {
            delete p;
        }
        if( cuerpo != nullptr ) {
            delete cuerpo;
        }
    }

    TipoDato analizarTipo() {
        vector<TipoDato> tiposParametros;

        for( Parametro* p : parametros  ) {
            tiposParametros.push_back( p->analizarTipo() );
        }

        TablaSimbolos::instance()->agregarFuncion( id->simbolo, tipo->analizarTipo(), tiposParametros );
        TablaSimbolos::instance()->agregaContexto( id->simbolo );

        for( Parametro* p : parametros ) {
            TablaSimbolos::instance()->agregarVariable( p->id->simbolo, p->tipo->analizarTipo() );
        }

        if( cuerpo != nullptr ) {
            if( cuerpo->analizarTipo( ) == T_ERROR ) {
                return T_ERROR;
            }
        }

        TablaSimbolos::instance()->quitaContexto();
        return T_VACIO;
    }

    string toString() {
        stringstream ss;

        ss << "<DEFINICION_FUNCION>" << endl;
        ss << tipo->toString();
        ss << id->toString();
        for( Parametro* p : parametros ) {
            ss << p->toString();
        }
        if( cuerpo != nullptr ) {
            ss << cuerpo->toString( );
        }
        ss << "</DEFINICION_FUNCION>" << endl;

        return ss.str();
    }
};

class LlamadaFuncion: public Expresion {
public:
    Identificador* id;
    vector<Expresion*> parametros;

    LlamadaFuncion( Identificador* id ) {
        this->id = id;
    }
    ~LlamadaFuncion() {
        delete id;
        for( Expresion* p : parametros ) {
            delete p;
        }
    }

    TipoDato analizarTipo() {
        vector<TipoDato> tiposParametros;
        for( Expresion* p : parametros  ) {
                tiposParametros.push_back( p->analizarTipo() );
        }

        return TablaSimbolos::instance()->existe(id->simbolo, tiposParametros);
    }

    string toString() {
        stringstream ss;

        ss << "<LLAMADA_FUNCION>" << endl;
        ss << id->toString( );
        for( Expresion* p : parametros ) {
            ss << p->toString();
        }
        ss << "</LLAMADA_FUNCION>" << endl;

        return ss.str();
    }
};

class UnidadTraduccion: public Nodo {
public:
    vector<Definicion*> definiciones;

    UnidadTraduccion() {}

    ~UnidadTraduccion() {
        for( Definicion* d : definiciones ) {
            delete d;
        }
    }

    TipoDato analizarTipo() {
        TablaSimbolos::instance()->agregaContexto( "0_PROGRAMA" );
        for( Definicion* def : definiciones ) {
            if( def->analizarTipo( ) == T_ERROR ) {
                return T_ERROR;
            }
        }
        return T_VACIO;
    }

    string toString() {
        stringstream ss;
        ss << "<PROGRAMA>" << endl;

        for( Definicion* d : definiciones ) {
            ss << d->toString();
        }
        ss << "</PROGRAMA>" << endl;

        return ss.str();
    }
};

#endif // AST_TIPOS_H_INCLUDED
