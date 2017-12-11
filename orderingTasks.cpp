/*
* Ordering Tasks - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
* ID : 20471991
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> list;
vector<int> topoSort;
bool visited[101];
int util[101];

void init(){
	list.clear();
	topoSort.clear();
	for (unsigned i = 0; i < 101; i++){
		visited[i] = false;
		util[i] = 0;
		list.push_back(vector<int>(101));
	}
}

void dfs(int vertex){
	visited[vertex] = true;
	topoSort.push_back(vertex);

	for (int i : list.at(vertex)){
		--util[i];
		if(util[i] == 0)
			dfs(i);
	}
}

int main(int argc, char const *argv[]){
    
	int n, m, vertex, conect, respSize;
	while(scanf("%d %d", &n, &m) != EOF){
		init();
        if(n == 0 && m == 0)
            break;
		for (unsigned i = 0; i < m; i++){
			scanf("%d %d", &vertex, &conect);
			vertex = vertex - 1;
			conect = conect - 1;
			++util[conect];
			list.at(vertex).push_back(conect);
		}

		for (unsigned i = 0; i < n; i++){
			if(!visited[i] && util[i] == 0)
				dfs(i);
		}
		respSize = topoSort.size() - 1;
		for (unsigned i = 0; i < respSize; i++){
		    printf("%d ", topoSort.at(i) + 1);
		}
    	printf("%d\n", topoSort.at(respSize) + 1);
	}
	return 0;
}