#ifndef AST_TIPOS_H_INCLUDED
#define AST_TIPOS_H_INCLUDED

#include <vector>
#include <iostream>

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
        return simbolo;
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
        return simbolo;
    }
};

class Entero: public Expresion {
public:
    Entero( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Entero() {}

    string toString() {
        return simbolo;
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        return izquierda->toString() + simbolo + derecha->toString();
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
        string strExp;
        if( expresion != nullptr ) {
            strExp = " = " + expresion->toString();
        }

        return id->toString() + strExp;
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
        return exp->toString() + "++";
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
        return exp->toString() + "--";
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
        return "++" + exp->toString();
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
        return "--" + exp->toString();
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
        return "!" + exp->toString();
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
        return "-" + exp->toString();
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
        return "+" + exp->toString();
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
    Asignacion* asignacion;

    Parametro( Tipo* tipo, Asignacion* asignacion ) {
        this->tipo = tipo;
        this->asignacion = asignacion;
    }

    ~Parametro() {
        delete tipo;
        delete asignacion;
    }

    string toString() {
        return tipo->toString() + " " + asignacion->toString();
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
        string str = tipo->toString();

        for( Asignacion* a : asignaciones ) {
            str += " " + a->toString() + " ";
        }

        return str;
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
        string str = "if (" + exp->toString() + ") ";
        if( proIf != nullptr ) {
            str +=  proIf->toString();
        }
        if( proElse != nullptr ) {
            str += "\r\nelse ";
            str +=  proElse->toString();
        }
        return str + "\r\n";
    }
};

class Continue: public Proposicion {
    string toString() {
        return "continue ";
    }
};

class Break: public Proposicion {
    string toString() {
        return "break ";
    }
};

class Return: public Proposicion {
public:
    Expresion* exp;

    Return() {
        exp = nullptr;
    }

    ~Return() {
        if( exp != nullptr ) {
            delete exp;
        }
    }

    string toString() {
        string str = "return ";
        if( exp != nullptr ) {
            str += exp->toString();
        }
        return str;
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
        string str = "{";

        for( Nodo* a : cuerpo ) {
            str += "\r\n" + a->toString();
        }
        str += "\r\n}";
        return str;
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
        string str = "Do \r\n" + proposicion->toString() + "while( " + exp->toString() + " )";

        return str;
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
        string str = "for( ";
        if( pre != nullptr ) str += pre->toString();
        str += ";";
        if( exp != nullptr ) str += exp->toString() ;
        str += ";";
        if( post != nullptr ) str += post->toString() ;
        str += ")";
        str += proposicion->toString();

        return str;
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
        string str = "while( " + exp->toString() + " )" + proposicion->toString();

        return str;
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
        string str = tipo->toString() + " ";

        str += id->toString() + "(";

        for( Parametro* a : parametros ) {
            str += " " + a->toString() + " ";
        }
        str += ")";

        if( cuerpo != nullptr ) {
            str += cuerpo->toString();
        }

        return str;
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
        string str;
        for( Definicion* a : definiciones ) {
            str += a->toString() + "\r\n";
        }
        return str;
    }
};

#endif // AST_TIPOS_H_INCLUDED
