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

    //cout << "Nombre archivo: ";
    //getline( cin, nombre );
    nombre = "entrada.c";
    lexico = new Lexico( nombre );
    tokens = lexico->dameListaTokens();
    if( !lexico->hayError() ) {
        cout << "Analisis Lexico: Aceptado" << endl;

        sintactico = new Sintactico( tokens );
        Nodo*  nodo = sintactico->analiza();

        if( !sintactico->hayError() ) {
            ofstream salida( "salida.xml" );
            cout << "Analisis Sintactico: Aceptado" << endl;

            if( !sintactico->hayError() ) {
                salida << nodo->toString( );
                if( nodo->analizarTipo( ) != T_ERROR ) {
                    cout << "Analisis Semantico: Aceptado" << endl;
                    TablaSimbolos::instance()->print();
                } else {
                    cout << "Analisis Semantico: Rechazado" << endl;
                }
            } else {
                cout << nodo->toString( );
                salida << nodo->toString( );
            }
            salida.close();
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
