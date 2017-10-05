/*
* RSA - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4664
* ID : 20122006
*/

#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

ll binaryExp(ll a, ll n, ll MOD) {
	ll res = 1;
	while (n) {
		if (n % 2) {
			res = (res * a) % MOD;
		}
		a = (a * a) % MOD;
		n = n / 2;
	}
	return res;
}

ll ExtendedEuclidAlgorithm(ll a, ll b, ll & x, ll & y, ll & d) {
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

	while(s0 < 0)
		s0 += b;
	return s0;
}

int main(int argc, char const *argv[]){
	ll N, E, C;
	while(scanf("%ld %ld %ld", &N, &E, &C) == 3){
		int lim = (int) sqrt(N);
		ll phiEu = N;
		for(unsigned p = 1; p < lim; p++) {
			if(N % p == 0)
				phiEu = (p - 1) * (N/p - 1);
		}

		ll x, y, d, inv;
		inv = ExtendedEuclidAlgorithm(E, phiEu, x, y, d);

		cout << binaryExp(C, inv, N) << endl;
	}
	return 0;
}