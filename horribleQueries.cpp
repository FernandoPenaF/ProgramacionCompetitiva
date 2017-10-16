/*
* Horrible Queries - http://www.spoj.com/problems/HORRIBLE/
* ID : 20380610
*/

#include <iostream>
using namespace std;
typedef long long ll;

ll tree[400001];
ll lazy[400001];

void init(){
	for(unsigned i = 0; i < 400001; i++) {
		tree[i] = 0;
		lazy[i] = 0;
	}
}

void updateRange(int node, int start, int end, int l, int r, ll val){
    if(lazy[node] != 0){ 
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r){
        tree[node] += (end - start + 1) * val;
        if(start != end){
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    updateRange(node * 2, start, (start + end) / 2, l, r, val);
    updateRange(node * 2 + 1, (start + end) / 2 + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll queryRange(int node, int start, int end, int l, int r){
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    ll p1 = queryRange(node * 2, start, (start + end) / 2, l, r);
    ll p2 = queryRange(node * 2 + 1, (start + end) / 2 + 1, end, l, r);
    return p1 + p2;
}

int main(int argc, char const *argv[]){
	int t, op, a, b, n, c;
	ll value;
	cin >> t;

	for(unsigned i = 0; i < t; ++i) {
		cin >> n >> c;
		init();
		for(unsigned i = 0; i < c; ++i) {
			scanf("%d %d %d", &op, &a, &b);

			if(op == 0){
				scanf("%lld", &value);
				updateRange(1, 0, n - 1, a - 1, b - 1, value);
			} else {
				cout << queryRange(1, 0, n - 1, a - 1, b - 1) << endl;
			}
		}
	}
	return 0;
}