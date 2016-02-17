#include <iostream>
#include <fstream>
#include "Lexico.h"

using namespace std;

int main() {
    Lexico lex;

    while( true ) {
        lex.sigSimbolo();

        if( !lex.fin() ) {
            cout << lex.toString() << endl;
        } else {
            break;
        }
    }

    cout << "\r\n" << lex.toStringTablaSimbolos() << endl;

    if( lex.hayError() ) {
        cout << "Error" << endl;
        cout << lex.toString() << endl;
    } else {
        cout << "Sin error" << endl;
    }

    return 0;
}
