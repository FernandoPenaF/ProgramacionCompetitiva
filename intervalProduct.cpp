#include <iostream>
#include <climits>
using namespace std;

int A[100000], n;
int st[400000];

void build( int p, int L, int R ) {
		if( L == R ) st[p] = A[L]; 
		else {
			build( 2 * p + 1, L, ( L + R )/2 );
			build( 2 * p + 2, ( L + R )/2 + 1, R );
			st[p] = st[ 2 * p + 1 ] * st[ 2 * p + 2 ];
		}
	}

int update( int p, int L, int R, int id, int v ) {
	if( id > R || id < L ) return st[p];
	if( L == id && R == id ) {
		A[L] = v;
		return st[p] = A[L];
	}
	return st[p] =  update( 2 * p + 1, L, ( L + R )/2, id, v ) * update( 2 * p + 2, ( L + R )/2 + 1, R, id, v );
}

int query( int p, int L, int R, int i, int j ) {
	if( i > R || j < L ) 
		return INT_MAX;
	if( L >= i && R <= j ) 
		return st[p];
	return query( 2 * p + 1, L, ( L + R )/2, i, j ) * query( 2 * p + 2, ( L + R )/2 + 1, R, i, j );
}

int main(int argc, char const *argv[]){
	n = 4;
	build(1, 0, n - 1);
	update(1, 0, n - 1, 1 - 1, -2);
	update(1, 0, n - 1, 2 - 1, 6);
	update(1, 0, n - 1, 3 - 1, 0);
	update(1, 0, n - 1, 4 - 1, -1);

	update(1, 0, n - 1, 1 - 1, 10);

	cout << query(1, 0, n - 1, 1 - 1, 4 - 1) << endl;
	update(1, 0, n - 1, 3 - 1, 7);
	cout << query(1, 0, n - 1, 2 - 1, 2 - 1) << endl;
	update(1, 0, n - 1, 4 - 1, -5);
	cout << query(1, 0, n - 1, 1 - 1, 4 - 1) << endl;
	cout << "OK!" << endl;
	return 0;
}