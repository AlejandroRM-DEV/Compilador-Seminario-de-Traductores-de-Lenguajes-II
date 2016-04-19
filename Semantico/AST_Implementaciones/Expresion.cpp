#include "../AST_Tipos.h"

Expresion::Expresion() {
    izquierda = nullptr;
    derecha = nullptr;
}

Expresion::~Expresion() {
    if( izquierda != nullptr ) {
        delete izquierda;
    }
    if( derecha != nullptr ) {
        delete derecha;
    }
}
