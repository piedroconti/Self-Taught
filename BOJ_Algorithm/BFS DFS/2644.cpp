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
	
	
	while (!Q.empty()) { // Q 빌때까지 반복 Q가 비었다는 것은 전부 탐색하고 탐색이 종료된다는 것
		int curr = Q.front();
		Q.pop();
		
		for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) { // 주변 정점 전부 Q에 넣어줌
			int next = *p;
			
			if (!visited[next]) {
				visited[next] = true; // 방문
				Q.push(next);
				dist[next] = dist[curr] + 1; // 시작점으로 부터 1씩 계속 더해줌
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