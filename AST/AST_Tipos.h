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
    virtual string toString( string prefijo, bool esHoja ) = 0;
};

class Tipo: public Nodo {
public:
    Tipo( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Tipo() {}

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Tipo: " << simbolo << endl;
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

    string toString( string prefijo, bool esHoja ) = 0;
};

class Identificador: public Expresion {
public:
    Identificador( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Identificador() {}

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "ID: " << simbolo << endl;
        return ss.str();
    }
};

class Entero: public Expresion {
public:
    Entero( string simbolo ) {
        this->simbolo = simbolo;
    }

    ~Entero() {}

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << simbolo << endl;
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "OR " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "AND " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Igualdad " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Diferente " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Menor " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "MenorIgual " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Mayor " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "MayorIgual " << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Suma" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Resta" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Multiplicacion" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Division" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "Modulo" << endl;
        if( izquierda != nullptr ) {
            ss << izquierda->toString( prefijo + ( esHoja ? "    " : "|   " ), ( derecha == nullptr ) );
        }
        if( derecha != nullptr ) {
            ss << derecha->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;

        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "Asignacion" << endl;
        ss << id->toString( prefijo + ( esHoja ? "    " : "|   " ), ( expresion == nullptr ) );

        if( expresion != nullptr ) {
            ss << expresion->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }

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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "PosfijoIncremento ++ " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "PosfijoDecremento -- " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "UnarioIncremento ++ " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "UnarioDecremento -- " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "UnarioNot ! " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "UnarioNegativo - " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << "UnarioPositivo + " << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    virtual string toString( string prefijo, bool esHoja ) = 0;
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;

        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "Parametro" << endl;

        ss << tipo->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << id->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        int i, j;

        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "DefinicionVariable" << endl;
        ss << tipo->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        for( i = 0, j = asignaciones.size() - 1; i < j; i++ ) {
            ss << asignaciones.at( i )->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        }
        ss << asignaciones.at( j )->toString( prefijo + ( esHoja ? "    " : "|   " ), true );


        return ss.str();
    }
};

class Proposicion: public Nodo {
public:
    Proposicion() {}
    virtual ~Proposicion() {}
    virtual string toString( string prefijo, bool esHoja ) = 0;
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "IF" << endl;
        ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << proIf->toString( prefijo + ( esHoja ? "    " : "|   " ), ( proElse == nullptr ) );

        if( proElse != nullptr ) {
            ss << proElse->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
        return ss.str();
    }
};

class Continue: public Proposicion {
public:
    Continue() {
        simbolo = "continue";
    }

    ~Continue() {}

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << simbolo << endl;
        return ss.str();
    }
};

class Break: public Proposicion {
public:
    Break() {
        simbolo = "break";
    }

    ~Break() {}

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << simbolo << endl;
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo << ( esHoja ? "\\---" : "|---" ) << simbolo << endl;

        if( exp != nullptr ) {
            ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        int i, j;
        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "ProposicionCompuesta" << endl;
        for( i = 0, j = cuerpo.size() - 1; i < j; i++ ) {
            ss << cuerpo.at( i )->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        }
        if( j >= 0 ) {
            ss << cuerpo.at( j )->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "DoWhile" << endl;
        ss << proposicion->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "For" << endl;
        if( pre != nullptr ) ss << pre->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        if( exp != nullptr ) ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        if( post != nullptr ) ss << post->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << proposicion->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "While" << endl;
        ss << exp->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << proposicion->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        int i, j;

        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "DefinicionFuncion" << endl;
        ss << tipo->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        ss << id->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        for( i = 0, j = parametros.size() - 1; i < j; i++ ) {
            ss << parametros.at( i )->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        }
        if( j >= 0 ) {
            ss << parametros.at( j )->toString( prefijo + ( esHoja ? "    " : "|   " ), ( cuerpo == nullptr ) );
        }
        if( cuerpo != nullptr ) {
            ss << cuerpo->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }

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

    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        int i, j;

        ss << prefijo + ( esHoja ? "\\---" : "|---" ) << "LlamadaFuncion" << endl;
        ss << id->toString( prefijo + ( esHoja ? "    " : "|   " ), parametros.empty() );
        for( i = 0, j = parametros.size() - 1; i < j; i++ ) {
            ss << parametros.at( i )->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        }
        if( j >= 0 ) {
            ss << parametros.at( j )->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }

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
    string toString( string prefijo, bool esHoja ) {
        stringstream ss;
        ss << "\\---UnidadTraduccion" << endl;

        int i, j;
        for( i = 0, j = definiciones.size() - 1; i < j; i++ ) {
            ss << definiciones.at( i )->toString( prefijo + ( esHoja ? "    " : "|   " ), false );
        }
        if( j >= 0 ) {
            ss << definiciones.at( j )->toString( prefijo + ( esHoja ? "    " : "|   " ), true );
        }
        return ss.str();
    }
};

#endif // AST_TIPOS_H_INCLUDED
