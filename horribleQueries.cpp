#include <iostream>
using namespace std;
long long arr[100000];

void init(){
	for(unsigned i = 0; i < 100000; ++i) {
		arr[i] = 0;
	}
}

void update(int i, int j, long long value){
	for(int count = i; count <= j; count++) {
		arr[count] += value;
	}
}

long long query(int i, int j){
	long long suma = 0;
	for(int count = i; count <= j; count++) {
		suma += arr[count];
	}
	return suma;
}

int main(int argc, char const *argv[]){
	int t, op, a, b, value, n, c;
	cin >> t;

	for(unsigned i = 0; i < t; ++i) {
		init();
		cin >> n >> c;
		for(unsigned i = 0; i < c; ++i) {
			scanf("%d %d %d", &op, &a, &b);

			if(op == 0){
				scanf(" %d", &value);
				update(a, b, value);
			} else {
				cout << query(a, b) << endl;
			}
		}
	}
	return 0;
}