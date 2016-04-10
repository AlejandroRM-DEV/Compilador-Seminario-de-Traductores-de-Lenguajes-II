#ifndef AST_TIPOS_H_INCLUDED
#define AST_TIPOS_H_INCLUDED

#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class Nodo {
public:
    string simbolo;
    Nodo() {}
    virtual ~Nodo() {}
    virtual string toString() = 0;
};

class Tipo: public Nodo {
public:
    Tipo( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Tipo() {}

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

    string toString() = 0;
};

class Identificador: public Expresion {
public:
    Identificador( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Identificador() {}

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
            ss << expresion->toString( );
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

    string toString() {
        stringstream ss;

        ss << "<DEFINICION_VARIABLE>" << endl;
        ss << tipo->toString();
        for( Asignacion* a: asignaciones ) {
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

    string toString() {
        stringstream ss;
        ss << "<IF>" << endl;
        ss << exp->toString();
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

    string toString() {
        stringstream ss;

        ss << "<PROPOSICION_COMPUESTA>" << endl;
        for( Nodo* n: cuerpo ) {
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

    string toString() {
        stringstream ss;
        ss << "<DO_WHILE>" << endl;
        ss << proposicion->toString();
        ss << exp->toString( );
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

    string toString() {
        stringstream ss;
        ss << "<WHILE>" << endl;
        ss << exp->toString();
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

    string toString() {
        stringstream ss;

        ss << "<DEFINICION_FUNCION>" << endl;
        ss << tipo->toString();
        ss << id->toString();
        for( Parametro* p : parametros) {
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

    string toString() {
        stringstream ss;

        ss << "<LLAMADA_FUNCION>" << endl;
        ss << id->toString( );
        for( Expresion* p : parametros) {
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
