#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1000] = { false }; bool visited2[1000] = { false };
vector<int> adj[10000];

void DFS(int curr) {
	
	visited[curr] = true; // curr: ���� ������ȣ adj[curr]: �̾��� �ִ� ������
	
	cout << curr << " ";

	for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) { //int next�� ������ ���̿��� ��������?
		int next = *p;
		if (!visited[next]) DFS(next); // ���� Ȥ�� ����Լ��� �̿��� �����Ѵٴ� ����� �� �� �ִ�.
	}

}

void BFS(int curr) {
	queue <int> Q;
	Q.push(curr);
	visited2[curr] = true;

	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		cout << curr << " ";

		for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) {
			int next = *p;
			if (!visited2[next]) { visited2[next] = true; Q.push(next); } // ť�� �̿��� �����Ѵٴ� ����� �� �� �ִ�.
		}
	}
}

int main() {
	int N, M, S; //����, ����, ��������
	cin >> N >> M >> S;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= M; i++)
		sort(adj[i].begin(), adj[i].end());

	
	DFS(S);

	cout << endl;

	BFS(S);
}
