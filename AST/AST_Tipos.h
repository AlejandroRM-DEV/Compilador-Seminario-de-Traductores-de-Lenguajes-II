#ifndef AST_TIPOS_H_INCLUDED
#define AST_TIPOS_H_INCLUDED

#include <vector>
#include <iostream>

using namespace std;

class Nodo {
public:
    string simbolo;
    Nodo* siguente;

    Nodo() {
        siguente = nullptr;
    }

    virtual ~Nodo() {
        if( siguente != nullptr ) {
            delete siguente;
        };
    }

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
    ~Expresion() {
        if( izquierda != nullptr ) {
            delete izquierda;
        };
        if( derecha != nullptr ) {
            delete derecha;
        };
    }

    virtual string toString() {
        return izquierda->toString() + " " + simbolo + " " + derecha->toString();
    }
};

class Identificador: public Expresion {
public:
    Identificador( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Identificador() {}

    virtual string toString() {
        return simbolo;
    }
};

class Entero: public Expresion {
public:
    Entero( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Entero() {}
    virtual string toString() {
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

    ~OR() {};
    virtual string toString() {
        return simbolo;
    }
};
class AND: public Expresion {
public:
    AND( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "&&";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~AND() {};
    virtual string toString() {
        return simbolo;
    }
};

class Igual: public Expresion {
public:
    Igual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "==";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Igual() {};
    virtual string toString() {
        return simbolo;
    }
};

class Diferente: public Expresion {
public:
    Diferente( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "!=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Diferente() {};
    virtual string toString() {
        return simbolo;
    }
};

class Menor: public Expresion {
public:
    Menor( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "<";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Menor() {};
    virtual string toString() {
        return simbolo;
    }
};

class MenorIgual: public Expresion {
public:
    MenorIgual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "<=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~MenorIgual() {};
    virtual string toString() {
        return simbolo;
    }
};

class Mayor: public Expresion {
public:
    Mayor( Expresion* izquierda, Expresion* derecha ) {
        simbolo = ">";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Mayor() {};
    virtual string toString() {
        return simbolo;
    }
};

class MayorIgual: public Expresion {
public:
    MayorIgual( Expresion* izquierda, Expresion* derecha ) {
        simbolo = ">=";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~MayorIgual() {};
    virtual string toString() {
        return simbolo;
    }
};

class Suma: public Expresion {
public:
    Suma( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "+";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Suma() {};
    virtual string toString() {
        return simbolo;
    }
};

class Resta: public Expresion {
public:
    Resta( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "-";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Resta() {};
    virtual string toString() {
        return simbolo;
    }
};

class Multiplicacion: public Expresion {
public:
    Multiplicacion( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "*";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Multiplicacion() {};
    virtual string toString() {
        return simbolo;
    }
};

class Division: public Expresion {
public:
    Division( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "/";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Division() {};
    virtual string toString() {
        return simbolo;
    }
};

class Modulo: public Expresion {
public:
    Modulo( Expresion* izquierda, Expresion* derecha ) {
        simbolo = "%";
        this->izquierda = izquierda;
        this->derecha = derecha;
    }

    ~Modulo() {};
    virtual string toString() {
        return simbolo;
    }
};


class Asignacion: public Nodo {
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
        cout << "toString() Asignacion" << endl;
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
    virtual string toString() {
        return exp->toString() + "++";
    }
};

class PosfijoDecremento: public Expresion {
public:
    Expresion* exp;
    PosfijoDecremento( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return exp->toString() + "--";
    }
};

class UnarioIncremento: public Expresion {
public:
    Expresion* exp;
    UnarioIncremento( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return "++" + exp->toString();
    }
};

class UnarioDecremento: public Expresion {
public:
    Expresion* exp;
    UnarioDecremento( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return "--" + exp->toString();
    }
};

class UnarioNot: public Expresion {
public:
    Expresion* exp;
    UnarioNot( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return "!" + exp->toString();
    }
};

class UnarioNegativo: public Expresion {
public:
    Expresion* exp;
    UnarioNegativo( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return "-" + exp->toString();
    }
};

class UnarioPositivo: public Expresion {
public:
    Expresion* exp;
    UnarioPositivo( Expresion* exp ) {
        this->exp = exp;
    }
    virtual string toString() {
        return "+" + exp->toString();
    }
};

class Definicion: public Nodo {
public:
    Tipo* tipo;

    Definicion( Tipo* tipo ) {
        this->tipo = tipo;
    }

    ~Definicion() {
        if( tipo != nullptr ) {
            delete tipo;
        };
    }

};

class Parametro: public Nodo {
public:
    Tipo* tipo;
    Asignacion* asignacion;

    Parametro( Tipo* tipo, Asignacion* asignacion ) {
        this->tipo = tipo;
        this->asignacion = asignacion;
    }

    string toString() {
        return tipo->toString() + " " + asignacion->toString();
    }
};

class DefinicionVariable: public Definicion {
public:
    vector<Asignacion*> asignaciones;
    DefinicionVariable( Tipo* tipo ): Definicion( tipo ) {}
    ~DefinicionVariable() {}

    string toString() {
        cout << "toString() DefinicionVariable" << endl;
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
    ~Proposicion() {}
    string toString() {
        return "";
    }
};

class If: public Proposicion {
public:
    Expresion* exp;
    Proposicion* proIf;
    Proposicion* proElse;

    If() {}
    ~If() {}
    string toString() {
        return "";
    }
};


class Return: public Proposicion {
public:
    Expresion* exp;

    Return() {
        exp = nullptr;
    }
    ~Return() {}
    string toString() {
        string str = "return ";
        if(exp!=nullptr){
            str+=exp->toString();
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

    ~ProposicionCompuesta() {}

    string toString() {
        string str;

        for( Nodo* a : cuerpo ) {
            if( DefinicionVariable* dv = dynamic_cast<DefinicionVariable*>( a ) ) {
                str += "\r\n\t" + dv->toString();
            }else if( Return* dv = dynamic_cast<Return*>( a ) ) {
                cout << "LOG" << endl;
                str += "\r\n\t" + dv->toString();
            }
        }

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
    ~DefinicionFuncion() {}

    string toString() {
        cout << "toString() DefinicionVariable" << endl;
        string str = tipo->toString() + " ";

        str += id->toString();
        for( Parametro* a : parametros ) {
            str += " " + a->toString() + " ";
        }

        if( cuerpo != nullptr ) {
            str += cuerpo->toString();
        }

        return str;
    }
};

class UnidadTraduccion: public Nodo {
public:
    vector<Definicion*> definiciones;

    string toString() {
        cout << "toString() UnidadTraduccion" << endl;
        string str;
        for( Definicion* a : definiciones ) {
            if( DefinicionVariable* dv = dynamic_cast<DefinicionVariable*>( a ) ) {
                str += dv->toString() + "\r\n";
            } else if( DefinicionFuncion* df = dynamic_cast<DefinicionFuncion*>( a ) ) {
                str += df->toString() + "\r\n";
            }
        }
        return str;
    }
};

#endif // AST_TIPOS_H_INCLUDED
