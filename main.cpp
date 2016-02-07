#include <iostream>
#include <fstream>
#include "Lexico.h"

using namespace std;

int main() {
    Lexico lex;

    while( !lex.fin() ) {
        lex.sigSimbolo();
        cout << lex.toString() << endl;
    }

    if( !lex.hayError() ) {
        cout << "Sin error" << endl;
    } else {
        cout << "Error" << endl;
    }

    return 0;
}
