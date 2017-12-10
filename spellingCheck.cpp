#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int hsh1[1000001], hsh2[1000001];
vector<int> queue;

void computeHashes(string s1, string s2, int minLen){
	for (unsigned i = 0; i < minLen; i++){
        if (s1.at(i + 1) == s2.at(i)){
        	hsh1[i + 1] = 1;
        }
        if (s1.at(i) == s2.at(i) ){
        	hsh2[i + 1] = 1;
        }
        hsh1[i + 1] += hsh1[i];
        hsh2[i + 1] += hsh2[i];
    }
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    int size;

    if(fabs(len1 - len2) == 1){
		computeHashes(s1, s2, len2);
		hsh1[len2 + 1] = hsh1[len2];
		for (unsigned i=0; i < len1; i++){
		    if ((hsh2[i] + hsh1[len1] - hsh1[i]) == len2) {
		    	queue.push_back(i + 1);
		    }
		}
		size = queue.size();

		cout << size << endl;
		for (unsigned i = 0; i < size; i++){
		    cout << queue.at(i) << " ";
		}
	} else {
		cout << 0 << endl;
	}
	return 0;
}