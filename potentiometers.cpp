/*
* Potentiometers - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=&problem=3238&mosmsg=Submission+received+with+ID+20122291
* ID : 20122291
*/
#include <iostream>
using namespace std;

int BIT[200000];
int n;

int prefix(int k){
	int ref = 0;
	for(int i = k; i; i -= (i & -i)) 
		ref += BIT[i];
	return ref;
}

int query(int limInf, int limSup){
	return prefix(limSup) - ( limInf == 1 ? 0 : prefix(limInf - 1));
}

void update(int k, int d){
	for(int i = k; i <= n; i += (i & -i))
		BIT[i] += d;
}

void init(){
	for(int i = 1; i <= n; i++)
		update(i, BIT[i]);
}

int main(int argc, char const *argv[]){
	int caseNum = 1;

	while(scanf("%d", &n) && n != 0){
		int initValue;
		char c;
		int a, b;
		
		if(caseNum > 1)
			cout << endl;

		for(unsigned i = 1; i <= n; i++) {
			scanf("%d", &initValue);
			update(i, initValue - query(i, i));
		}
		cout << "Case " << caseNum << ":" << endl;
		caseNum++;

		while(scanf("%c", &c) && c != 'E'){
			if(c == 'M'){
				scanf("%d %d", &a, &b);
				cout << query(a, b) << endl;
			} else if(c == 'S'){
				scanf("%d %d", &a, &b);
				update(a, b - query(a, a));
			}
		}
		scanf("ND");
	}
	return 0;
}