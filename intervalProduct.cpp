/*
* Interval Product - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3977
* ID : 20141001
*/

#include <iostream>
#include <climits>
using namespace std;

int a[100000], n;
int m[400000];

int getSign(int x){
	if(x > 0)
		return 1;
	else if (x < 0)
		return -1;
	return x;
}

void build(int x, int l, int r) {
	if(l == r){
		m[x] = a[l];
		return; 
	}
	build(2*x + 1, l, (l + r)/2);
	build(2*x + 2, (l + r)/2 + 1, r);
	m[x] = m[2*x + 1] * m[2*x + 2];
}

int query(int x, int l, int r, int i, int j) {
	if(r < i || j < l) 
		return INT_MAX;
	if(l >= i && r <= j)
		return m[x];
	return query(2*x + 1, l, (l + r) / 2, i, j) * query(2*x + 2, (l + r) / 2 + 1, r, i, j);
}

int update(int x, int l, int r, int i, int v) {
	if(i < l || r < i) 
		return m[x];
	if(l == i && r == i) {
		a[l] = v;
		return m[x] = a[l];
	}
	return m[x] = update(2*x + 1, l, (l + r) / 2, i, v) * update(2*x + 2, (l + r) / 2 + 1, r, i, v);
}

int main(int argc, char const *argv[]){
	int k, value, a, b;
	char c;
	while(scanf("%d %d", &n, &k) != EOF){
		build(1, 0, n - 1);
		for (int i = 1; i <= n; i++){
			scanf("%d", &value);
			update(1, 0, n - 1, i - 1, getSign(value));
		}

		for (int i = 0; i < k; i++){
			scanf(" %c %d %d", &c, &a, &b);

			if(c == 'C')
				update(1, 0, n - 1, a - 1, getSign(b));
			else{
				int resp = query(1, 0, n - 1, a - 1, b - 1);
				cout << (resp == 0 ? '0' : (resp < 0 ? '-' : '+'));
			}
		}
		cout << endl;
	}
	return 0;
}