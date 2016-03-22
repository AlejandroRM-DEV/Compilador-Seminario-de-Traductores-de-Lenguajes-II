#include <iostream>
#include <fstream>

#include "Lexico.h"
#include "Sintactico.h"

using namespace std;

int main() {
    queue<ParToken> tokens;
    Sintactico* sintactico;
    Lexico* lexico = new Lexico();

    tokens = lexico->dameListaTokens();
    if( !lexico->hayError() ) {
        cout << "Analisis Lexico: Aceptado" << endl;

        sintactico = new Sintactico( tokens );
        Nodo*  nodo = sintactico->analiza();

        if( !sintactico->hayError() ) {
            cout << nodo->toString( "", true ) << endl;
            cout << "Analisis Sintactico: Aceptado" << endl;
        } else {
            cout << "Analisis Sintactico: Rechazado" << endl;
        }

        delete sintactico;
        delete nodo;
    } else {
        cout << "Analisis Lexico: Rechazado" << endl;
    }

    delete lexico;
    return 0;
}
