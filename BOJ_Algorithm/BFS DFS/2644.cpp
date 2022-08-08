#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector <int> adj[100];
int dist[100] = { 0, };
bool visited[100] = { false };
queue <int> Q;


void BFS(int n) {
	dist[n] = 0;
	Q.push(n);
	visited[n] = true;
	
	
	while (!Q.empty()) { // Q �������� �ݺ� Q�� ����ٴ� ���� ���� Ž���ϰ� Ž���� ����ȴٴ� ��
		int curr = Q.front();
		Q.pop();
		
		for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) { // �ֺ� ���� ���� Q�� �־���
			int next = *p;
			
			if (!visited[next]) {
				visited[next] = true; // �湮
				Q.push(next);
				dist[next] = dist[curr] + 1; // ���������� ���� 1�� ��� ������
			}
		}
	}
}

int main() {
	int V, E;
	int start, end;

	cin >> V;
	cin >> start >> end; start--; end--;
	cin >> E;

	for (int i = 0; i < E; i++) {
		int u, v;
		cin >> u >> v;
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}

	BFS(start);

	if (!dist[end])
		cout << -1;
	else
		cout << dist[end];
}