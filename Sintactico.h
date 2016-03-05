#ifndef SINTACTICO_H_INCLUDED
#define SINTACTICO_H_INCLUDED

#include "Constantes.h"
#include <queue>

class Sintactico {
private:
    bool error;
    queue<ParToken> tokens;

    void comprueba( string simbolo );
    void comprueba( Token tipo );
    void marcarError( string mensaje );

public:
    Sintactico( queue<ParToken> tokens );
    ~Sintactico();
    bool hayError();
    void analiza();
    void unidad_traduccion();
    void unidad_traduccion_prima();
    void definicion();
    void definicion_prima();
    void cuerpo_funcion();
    void lista_vars();
    void lista_de_declaraciones();
    void declarador_init();
    void declarador_init_prima();
    void lista_param();
    void lista_param_prima();
    void especificador_tipo();
    void expresion();
    void expresion_prima();
    void expresion_de_asignacion();
    void expresion_logica_OR();
    void expresion_logica_OR_prima();
    void expresion_logica_AND();
    void expresion_logica_AND_prima();
    void expresion_de_igualdad();
    void expresion_de_igualdad_prima();
    void expresion_relacional();
    void expresion_relacional_prima();
    void expresion_aditiva();
    void expresion_aditiva_prima();
    void expresion_multiplicativa();
    void expresion_multiplicativa_prima();
    void expresion_unaria();
    void expresion_posfija();
    void expresion_posfija_prima();
    void expresion_primaria();
    void lista_expresiones_argumento();
    void lista_expresiones_argumento_prima();
    void proposicion_de_seleccion();
    void proposicion_de_seleccion_else();
    void proposicion();
    void proposicion_compuesta();
    void lista_de_proposiciones();
    void proposicion_expresion();
    void proposicion_de_iteracion();
    void for_post();
    void proposicion_de_salto();
};

#endif // SINTACTICO_H_INCLUDED
