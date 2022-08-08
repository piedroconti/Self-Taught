#include <iostream>
#include <vector>
using namespace std;

vector <int> adj[100];
bool infected[100] = { false };
int cnt = 0;

void DFS(int n) {
	if (infected[n])
		return;

	infected[n] = true;

	for (auto p = adj[n].begin(); p != adj[n].end(); ++p) {
		DFS(*p);
	}
}

int main() {
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u-1].push_back(v-1); //!! 배열 인덱스를 항상 조심하자!!
		adj[v- 1].push_back(u - 1);
	}

	DFS(0); //1번컴부터 시작 

	for (int i = 1; i < 100; i++) // 시작컴은 포함 안하므로 1부터 시작
		if (infected[i]) 
			cnt++;

	cout << cnt;
}