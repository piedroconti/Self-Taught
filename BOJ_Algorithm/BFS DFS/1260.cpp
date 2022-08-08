#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1000] = { false }; bool visited2[1000] = { false };
vector<int> adj[10000];

void DFS(int curr) {
	
	visited[curr] = true; // curr: 현재 정점번호 adj[curr]: 이어져 있는 정점들
	
	cout << curr << " ";

	for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) { //int next로 선언한 라이와의 차이점은?
		int next = *p;
		if (!visited[next]) DFS(next); // 스택 혹은 재귀함수를 이용해 구현한다는 사실을 알 수 있다.
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
			if (!visited2[next]) { visited2[next] = true; Q.push(next); } // 큐를 이용해 구현한다는 사실을 알 수 있다.
		}
	}
}

int main() {
	int N, M, S; //정점, 간선, 시작정점
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
