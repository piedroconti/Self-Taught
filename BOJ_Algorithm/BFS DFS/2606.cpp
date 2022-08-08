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
		adj[u-1].push_back(v-1); //!! �迭 �ε����� �׻� ��������!!
		adj[v- 1].push_back(u - 1);
	}

	DFS(0); //1���ĺ��� ���� 

	for (int i = 1; i < 100; i++) // �������� ���� ���ϹǷ� 1���� ����
		if (infected[i]) 
			cnt++;

	cout << cnt;
}