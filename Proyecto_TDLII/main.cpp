#include <iostream>
#include <fstream>
#include "Lexico.h"

using namespace std;

int main() {
    Lexico lex;

    while(true){
        lex.sigSimbolo();
        if(lex.fin()){
            break;
        }
        cout << "[" << lex.dameSimbolo() << "] " << endl;
    }

    if(lex.hayError()){
        cout << "E R R O R" << endl;
    } else {
        cout << "A C E P T A D O" << endl;
    }
    return 0;
}
