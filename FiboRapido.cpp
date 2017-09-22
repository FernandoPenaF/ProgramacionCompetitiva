/*
* Fibonacci Rápido - https://omegaup.com/arena/problem/Fibonacci-Rapido
* GUID : a4797ee9
*/

#include <iostream>
using namespace std;

void multiply(long long A[2][2], long long B[2][2], long long mod){
    long long x =  (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % mod;
    long long y =  (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % mod;
    long long z =  (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % mod;
    long long w =  (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % mod;
    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

long long binaryExp(long long n, long mod){
	long long fiboMatrix[2][2] = {{1, 1}, {1, 0}};
	long long resp[2][2] = {{1, 0}, {0, 1}};

	while(n > 0){
		if(n % 2 == 0){
			multiply(fiboMatrix, fiboMatrix, mod);
			n = n / 2;
		}
		else{
			multiply(resp, fiboMatrix, mod);
			n = n - 1;
		}
	}
	return resp[0][1];
}

int main(int argc, char const *argv[]){	
	long long n;
	cin >> n;
	cout << binaryExp(n, 98765431) << endl;
	return 0;
}