#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
const int INF = 100000000;
const int MAX_V = 20000; // 아무리 그래도 이거 크기 가지고 outofbounds로 지랄하는건 좀 너무하네;;;
using namespace std;


typedef pair <int, int> P;

int main() {

	int V, E, K;
	vector <P> adj[MAX_V];
	cin >> V >> E >> K; K--;
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w; // cin , cout는 printf, scanf에 비해 느린가?
		adj[u - 1].push_back(P(v - 1, w));
	}


	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	
	bool visited[MAX_V] = { 0 };
	
	priority_queue<P, vector<P>, greater<P>> PQ;
	//다익스트라
	
	dist[K] = 0;
	PQ.push(P(0, K));
	while (!PQ.empty()) { // 여기도 우선순위 큐 부분이 어떻게 작동하는지 생각해 봐야겠다
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]); // 이 부분 이유좀 생각해 봐야겠다//

		if (visited[curr])
			break;
		
		visited[curr] = true;
		for (auto p = adj[curr].begin(); p != adj[curr].end(); ++p) {//
			int next = p->first, distance = p->second; // 이거 화살표인 이유가 뭐더라
			if (dist[next] > dist[curr] + distance) {
				dist[next] = dist[curr] + distance;
				PQ.push(P(dist[next], next));
			}
		}
	}


	for (int i = 0; i < V; i++) {
		if (dist[i] == INF)
			puts("INF");//
		else
			printf("%d\n", dist[i]);
	}

}