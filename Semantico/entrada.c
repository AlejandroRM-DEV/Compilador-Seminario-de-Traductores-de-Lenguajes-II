
/*
    Archivo de prueba para el analizador sintactico, s�lo se revisa que sea sintacticamente
    correcto.
*/

int global_0;
int global_1, global_2;
int global_3 = 1;
int global_4 = 1, global_5;
int global_6 = 1, global_7, global_8;
int global_9 = 1, global_10, global_11 = 1;
int global_12 = 1, global_13 = 1;
int global_14 = 1, global_15 = 1, global_16;
int global_17, global_18 = 1, global_19;

void func();
int func2();
int func3( int a );
int func4( int a, int b );
int func5( int a, int b, int c );

int func6() {}
int func7( int a ) {}
int func8( int a, int b ) {}

int func9() {
    int a;
    int b, c;
    int d = 1, e;
    int f, g = 1;
    int h = 1, i = 1;
    int asig = func2();

    return;
    return 1;
    return -1;
    return -a;
    return a;
    return !a;
}

int func10() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    int var_0 = a + 1 - c * 2 / e;
    int var_1 = 1 - b * c / 2 + e;
    int var_2 = a * b / 1 + d - e;
    int var_3 = a / 1 + c - d * 2;

    int var_4 = ( 1 + b / func2() ) * 2 / e;
    int var_5 = ( a - 2 ) * c / ( 2 + e );
    int var_6 = a * func2() / ( 1 + d - e );
    int var_7 = a / ( b + func2() - d ) * 2;
    int var_8 = a % b % ( ( c * d ) / 2 );
    int var_9 = ( ( a - b ) * 2 ) / ( d + e );
    int var_10 = a * ( 10 / ( c + d - e ) );
    int var_11 = a / ( ( b + c - func2() ) * 2 );
    int var_12 = func2() % ( ( b + c - d ) * 2 );

    if( a ) {}
    if( !a ) {}
    if( a && func2() || c ) {}
    if( !a && !func2() || c ) {}
    if( a || b && c ) {}
    if( a && b || c && d ) {}
    if( a || func2() && c || d ) {}
    if( a < b ) {}
    if( a <= b ) {}
    if( a > b ) {}
    if( a >= b ) {}
    if( a == b ) {}
    if( a != b ) {}
    if( ( a == b ) && ( c != d ) && ( e < f ) && ( g > h ) && ( i <= j ) && ( k <= l ) ) {}
    if( ( a == func2() ) && ( func2() != d ) && ( e < func2() ) && ( func2() > h ) && ( i <= func2() ) && ( func2() <= l ) ) {}
    if( a ) {
        int varIF;

        varIF = 0;
    } else {
        int varELSE;

        varELSE = func2();
    }
}

int func11() {
    int if_0, if_1, if_2, if_3, if_4, if_5;
    if( if_0 < 0 ) {
        return 0;
    }

    if( if_1 < 0 ) {
        return 1;
    } else {
        return 2;
    }

    if( if_2 < 0 ) {
        int varIF_2;

        varIF_2 = 0;
        if( if_3 < 0 ) {
            int varIF_3;

            varIF_3 = 0;
            return 3;
        } else {
            return 4;
        }
    } else {
        return 5;
    }

    if( if_4 < 0 ) {
        return 6;
    } else if( if_5 > 0 ) {
        return 7;
    } else {
        return 8;
    }

}

int func12() {
    int var;
    while( 1 ) {
        int varWHILE_0;

        varWHILE_0 = 0;
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    while( global_0 ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }
    while( global_0 == 0 ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    while( global_0 == 0 ) {
        int varWHILE_0;

        varWHILE_0 = 0;
        while( global_1 == 0 ) {
            int varWHILE_1;

            varWHILE_1 = 0;
            if( var < 0 ) {
                continue;
            } else {
                break;
            }
        }
    }
}

int func13() {
    int var;
    do {
        int varDO_WHILE_0;

        varDO_WHILE_0 = 0;
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    } while( 1 );

    do {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    } while( global_0 );

    do {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    } while( global_0 == 0 );

    do {
        int varDO_WHILE_0;

        varDO_WHILE_0 = 0;
        do {
            int varDO_WHILE_1;

            varDO_WHILE_1 = 0;
            if( var < 0 ) {
                continue;
            } else {
                break;
            }
        } while( global_2 == 0 );
    } while( global_0 == 0 );
}

int func14() {
    int i, c, n, var;
    for( i = 0; i < 10; i++ ) {
        int varFOR_0;

        varFOR_0 = 0;
        if( var < 1 ) {
            continue;
        } else {
            break;
        }
    }

    for( i = 0; i < 10; ) {
        if( var < 2 ) {
            continue;
        } else {
            break;
        }
    }

    for( i = 0; ; ) {
        if( var < 3 ) {
            continue;
        } else {
            break;
        }
    }

    for( ; i < 10; ) {
        if( var < 4 ) {
            continue;
        } else {
            break;
        }
    }

    for( ; ; ) {
        if( var < 5 ) {
            continue;
        } else {
            break;
        }
    }
    for( c = n = 1; i < 10; i++ ) {
        if( var < 6 ) {
            continue;
        } else {
            break;
        }
    }

}

int func15() {
    int a = 0, b = 1, c = 2;
    int x, y, z;

    if( a >= 0 ) {
        int var_0  = 0;
        for( x = 0; x <= 20; x++ ) {

            int var_1  = 0;
            while( b == 1 ) {

                int var_2  = 0;
                do {

                    int var_3  = 0;
                    y = c + b;
                    z = c * 2;
                    if( z > 100 ) {

                        int var_4  = 0;
                        break;
                    } else if( y < 100 ) {
                        int var_5  = 0;
                        a++;
                    } else {
                        continue;
                    }
                    c--;
                } while( c != 0 );
            }
        }
        while( b == 1 ) {
            do {
                z = c * 2;
                for( x = 100; x > 0; x-- ) {
                    y = c + b;
                }
                c--;
            } while( c != 0 );
        }
    }
    if( z > 100 ) {
        return 1;
    } else {
        return 0;
    }

}

int func16() {
    int a, b, i;
    int a_0 = func2();
    int a_1 = func3( a );
    int a_2 = func4( a, b );

    a = func2();
    a = func3( a );
    a = func4( a, b );

    func2();
    func3( a );
    func4( a, b );

    int a_3 = func3( func2() );
    int a_4 = func4( a, func2() );
    int a_5 = func5( a, func2(), b );

    a = func3( func2() );
    a = func4( a, func2() );
    a = func5( a, func2(), b );

    func3( func2() );
    func4( a, func2() );
    func5( a, func2(), b );

    func3( func2() + 1 );
    func4( a++, func2() );
    func5( ++a, func2(), b-- );

    while( 1 ) {
        i = 1;
    }
    i = 0;
}
