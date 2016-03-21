/*
    Archivo de prueba para el analizador sintactico, sólo se revisa que sea sintacticamente
    correcto.
*/
int global;
int global, global2;
int global = 1;
int global = 1, global2;
int global = 1, global2, global3;
int global = 1, global2, global3 = 1;
int global = 1, global2 = 1;
int global = 1, global2 = 1, global3;
int global, global2 = 1, global3;

void func();
int func();
int func( int a );
int func( int a, int b );
int func( int a, int b, int c );

int func() {}
int func( int a ) {}
int func( int a, int b ) {}

int func() {
    int a;
    int b, c;
    int d = 1, e;
    int f, g = 1;
    int h = 1, i = 1;

    return;
    return 1;
    return -1;
    return a;
    return !a;
}
/*
int func() {
    if( global < 0 ) {
        return -1;
    }

    if( global < 0 ) {
        //Codigo
    } else {
        //Codigo
    }

    if( global < 0 ) {
        if( global < 0 ) {
            //Codigo
        } else {
            //Codigo
        }
    } else {
        //Codigo
    }

    if( global < 0 ) {
        //Codigo
    } else if( global > 0 ) {
        //Codigo
    } else {
        //Codigo
    }
}

int func() {
    while( 1 ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    while( global ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }
    while( global == 0 ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    while( global == 0 ) {
        while( global == 0 ) {
            if( var < 0 ) {
                continue;
            } else {
                break;
            }
        }
    }
}

int func() {
    do {
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
    } while( global );

    do {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    } while( global == 0 );

    do {
        do {
            if( var < 0 ) {
                continue;
            } else {
                break;
            }
        } while( globa2 == 0 );
    } while( global == 0 );
}

int func() {
    for( i = 0; i < 10; i++ ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    for( i = 0; i < 10; ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    for( i = 0; ; ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    for( ; i < 10; ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }

    for( ; ; ) {
        if( var < 0 ) {
            continue;
        } else {
            break;
        }
    }
}

int func() {
    int var = a + 1 - c * 2 / e;
    int var = 1 - b * c / 2 + e;
    int var = a * b / 1 + d - e;
    int var = a / 1 + c - d * 2;

    int var = ( 1 + b - c ) * 2 / e;
    int var = ( a - 2 ) * c / ( 2 + e );
    int var = a * b / ( 1 + d - e );
    int var = a / ( b + c - d ) * 2;
    int var = a + b - ( ( c * d ) / 2 );
    int var = ( ( a - b ) * 2 ) / ( d + e );
    int var = a * ( 10 / ( c + d - e ) );
    int var = a / ( ( b + c - d ) * 2 );

    if( a ) {}
    if( !a ) {}
    if( a && b || c ) {}
    if( !a && !b || c ) {}
    if( a || b && c ) {}
    if( a && b || c && d ) {}
    if( a || b && c || d ) {}
    if( a < b ) {}
    if( a <= b ) {}
    if( a > b ) {}
    if( a >= b ) {}
    if( a == b ) {}
    if( a != b ) {}
    if( ( a == b ) && ( c != d ) && ( e < f ) && ( g > h ) && ( i <= j ) && ( k <= l ) ) {}
}

int func() {
    int a = 0, b = 1, c = 2;
    int x, y, z;

    if( a >= 0 ) {
        for( x = 0; x <= 20; x++ ) {
            while( b == 1 ) {
                do {
                    y = c + b;
                    z = c * 2;
                    if( z > 100 ) {
                        break;
                    } else if( y < 100 ) {
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
*/
