/*
int global = 1;

void aritmeticaBasica() {
	int a, b, c, d, e, f, x;
	a = 1;
	b = a + 2;
	c = b - 1;
	d = c * 2;
	e = d / 1;
	f = e % 2;
	x = a = b = c = d = 0;
}

int operacionX ( int a, int b ) {
	int res = a % b * ( ( a + b ) / ( a - b ) );
	// Algo de codigo
	return res;
}

void unarios() {
	int a = +1;
	int b = -1;
	int c = !1;
	int d = !0;

	int e = ++a;
	int f = --a;
	int x = a++;
	int y = a--;
	int z = a;
}
*/
int main() {
    int z;
	int x = 0, y = 1;

	//aritmeticaBasica();
	//x = operacionX ( 2, 3 );
	//unarios();
    if ( x == y ){
        z = 1;
    }
    if ( x != y ){
        z = 1;
    }
    if ( x > y ){
        z = 1;
    }
    if ( x >= y ){
        z = 1;
    }
    if ( x < y ){
        z = 1;
    }
    if ( x <= y ){
        z = 1;
    }
	return 0;
}

