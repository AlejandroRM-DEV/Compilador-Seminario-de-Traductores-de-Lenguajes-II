#include <iostream>
#include <fstream>

#include "Lexico.h"
#include "Sintactico.h"

using namespace std;

int main() {
    queue<ParToken> tokens;
    Sintactico* sintactico;
    Lexico* lexico;
    string nombre;

    cout << "Nombre archivo: ";
    getline( cin, nombre );
    lexico = new Lexico( nombre );
    tokens = lexico->dameListaTokens();
    if( !lexico->hayError() ) {
        cout << "Analisis Lexico: Aceptado" << endl;

        sintactico = new Sintactico( tokens );
        Nodo*  nodo = sintactico->analiza();

        if( !sintactico->hayError() ) {
            ofstream salida( "salida.txt" );
            if( !sintactico->hayError() ) {
                salida << nodo->toString( );
            } else {
                salida << nodo->toString( );
            }
            salida.close();
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
