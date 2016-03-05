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
        sintactico->analiza();

        if( !sintactico->hayError() ) {
            cout << "Analisis sintactico: Aceptado" << endl;
        } else {
            cout << "Analisis sintactico: Rechazado" << endl;
        }

        delete sintactico;
    } else {
        cout << "Analisis Lexico: Rechazado" << endl;
    }

    delete lexico;
    return 0;
}
