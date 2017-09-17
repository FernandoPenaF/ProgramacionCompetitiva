/*
* Fibonacci Rápido - https://omegaup.com/arena/problem/Fibonacci-Rapido
* 60% correcto
*/

#include <iostream>
using namespace std;

long long binaryExp(long long n, long mod){
	long long h, i, j, k, aux;
	h = i = 1;
	j = k = 0;
	while(n > 0){
		if(n % 2 == 1){
			aux = (h * j) % mod;
			j = (h * i + j * k + aux) % mod;
			i = (i * k + aux) % mod;
		}
		aux = (h * h) % mod;
		h = (2 * h * k + aux) % mod;
		k = (k * k + aux) % mod;
		n = (n / 2) % mod;
	}
	return j;
}

int main(int argc, char const *argv[]){	
	long long n;
	cin >> n;
	cout << binaryExp(n, 98765431) << endl;
	return 0;
}