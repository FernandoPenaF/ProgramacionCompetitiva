/*
* La venganza de Silvio - https://omegaup.com/arena/problem/VenganzaDeSilvio
* GUID : 22ebf0b5
*/

#include <iostream>
#include <string>
using namespace std;
typedef unsigned long long int ulli;
int binaryRep[1000001];

ulli binaryExp(ulli n, ulli mod, int len){
	ulli resp = 1;
	int i = 0;
	while(i < len){
		resp = (resp * resp) % mod;
		if(binaryRep[i] == 1)
			resp = (resp * n) % mod;
		i++;
	}
	return resp;
}

int main(int argc, char const *argv[]){
	ulli N, mod;
	string M;
	cin >> N >> mod;
	cin >> M;
	unsigned int i = 0;
	for(i = 0; i < M.length(); ++i) {
		binaryRep[i] = M.at(i) - '0';
	}

	cout << binaryExp(N, mod, i) << endl;
	return 0;
}