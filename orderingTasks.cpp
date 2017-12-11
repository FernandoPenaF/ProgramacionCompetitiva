#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> list;
vector<int> topoSort;
bool visited[101];
int util[101];

void dfs(int vertex){
	visited[vertex] = true;
	topoSort.push_back(vertex);

	for (int i : list.at(vertex)){
		--util[i];
		if(util[i] == 0)
			dfs(i);
	}
}

void init(){
	list.clear();
	for (unsigned i = 0; i < 101; i++){
		visited[i] = false;
		util[i] = 0;
		list.push_back(vector<int>(101));
	}
	topoSort.clear();
}

int main(int argc, char const *argv[]){
	int n, m, v, c;
	while(true){
		init();
		
		cin >> n >> m;
		if(n == 0 && m == 0) break;

		for (unsigned i = 0; i < m; i++){
			cin >> v >> c;
			v = v - 1;
			c = c - 1;
			++util[c];
			list.at(v).push_back(c);
		}

		for (unsigned i = 0; i < n; i++){
			if(!visited[i] && util[i] == 0)
				dfs(i);
		}
		int rep = topoSort.size();
		for (unsigned i = 0; i < rep; i++){
			if(i != rep - 1)
				cout << topoSort.at(i) + 1 << " ";
			else
				cout << topoSort.at(i) + 1 << endl;
		}
	}
	return 0;
}