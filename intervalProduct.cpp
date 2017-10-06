#include <iostream>
#include <climits>
using namespace std;

int a[100000], n;
int m[400000];

void build(int x, int l, int r){ //build(0, 0, n - 1)
	if(l == r){
		m[x] = a[l];
		return;
	}
	build(2*x + 1, l, (l + r) / 2);
	build(2*x + 2, (l + r) / 2 + 1, r);
	m[x] = m[2*x + 1] * m[2*x + 2];
}

int query(int x, int l, int r, int i, int j){
	if(r < i || j < l)
		return INT_MAX;
	if(i <= l && r <= j)
		return m[x];
	return query(2*x + 1, l, (l + r) / 2, i, j) * query(2*x + 2, (l + r) / 2 + 1, r, i, j);
}

void update(int x, int l, int r, int i, int v){
	if(i < l || r < i)
		return;
	if(l == r){
		m[x] = v;
		return;
	}
	update(2*x + 1, l, (l + r) / 2, i, v);
	update(2*x + 1, (l + r)/ 2 + 1, r, i, v);
	m[x] = m[2*x + 1] * m[2*x + 2];
}

int main(int argc, char const *argv[]){
	n = 4;
	build(0, 0, n - 1);
	
	
	
	return 0;
}