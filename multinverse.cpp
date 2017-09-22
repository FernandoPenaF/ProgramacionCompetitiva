/*
* Multinverse - https://omegaup.com/arena/problem/multinverse
* 50% correcto
*/

#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

ll ExtendedEuclidAlgorithm(ll a, ll b, long long & x, long long  & y, long long & d) {
	ll resp = 0;
	ll q, aux;
	ll r0 = a;
	ll r1 = b;
	ll s0 = 1;
	ll s1 = 0;
	ll t0 = 0;
	ll t1 = 1;

	while (r1) {
		q = r0/r1;
		aux = r1;
		r1 = r0 - q*r1;
		r0 = aux;
		aux = s1;
		s1 = s0 - q*s1;
		s0 = aux;
		aux = t1;
		t1 = t0 - q*t1;
		t0 = aux;
	}
	d = r0;
	x = s0;
	y = t0;
	return s0;
}

int main(int argc, char const *argv[]){
	ll a, b, x, y, d, resp;
	cin >> a >> b;
	resp = ExtendedEuclidAlgorithm(a, b, x, y, d);
	if(d == 1)
		if(resp >= 0)
			cout << resp << endl;
		else
			cout << 1 + resp << endl;
	else
		cout << -1 << endl;
	return 0;
}