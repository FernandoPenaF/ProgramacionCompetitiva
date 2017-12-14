/*
* Oro - https://omegaup.com/arena/problem/oro#problems
* GUID : d36a0f92
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> s;
int getMinimunExcedent(int minReq){
    int n = s.size();
    int total = 1 << n;
    int results[total];
    vector<int> ans;
    
    for(int i = 0; i < total; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            if(( i & ( 1 << j )))
                sum += s [j];
        }
        results[i] = sum;
        if(results[i] >= minReq)
            ans.push_back(results[i]);
    }
    
    int min = ans[0];
    for(unsigned i = 1; i < ans.size(); i++) {
        if(ans[i] < min){
            min = ans[i];
        }
    }
    return min - minReq;
}

int main(int argc, char const *argv[]){
    int N, B, io;
    cin >> N >> B;
    for(unsigned i = 0; i < N; i++){
        cin >> io;
        s.push_back(io);
    }
    cout << getMinimunExcedent(B) << endl;
    return 0;
}