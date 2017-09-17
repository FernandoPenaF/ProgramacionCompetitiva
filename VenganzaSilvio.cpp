/*
* La venganza de Silvio - https://omegaup.com/arena/problem/VenganzaDeSilvio
* 25% correcto
*/

#include <iostream>
using namespace std;

long long binaryExp(long long x, long long n, long long mod){
	long long resp = 1;
	while(n > 0){
		if(n % 2 == 1)
			resp = (resp * x) % mod;
		x = (x * x) % mod;
		n = n / 2;
	}
	return resp;
}

long long toDecimal(long long bin){
	long long dec = 0;
	long long mod = 0;
	int i = 1;
	while(bin != 0){
		mod = bin % 10;
		dec = dec + mod * i;
		i *= 2;
		bin /= 10;
	}
	return dec;
}

int main(int argc, char const *argv[])
{
	long long N, mod, M;
	cin >> N >> mod;
	cin >> M;
	cout << binaryExp(N, toDecimal(M), mod) << endl;
	return 0;
}