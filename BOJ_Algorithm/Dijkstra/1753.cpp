#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
const int INF = 100000000;
const int MAX_V = 20000; // �ƹ��� �׷��� �̰� ũ�� ������ outofbounds�� �����ϴ°� �� �ʹ��ϳ�;;;
using namespace std;


typedef pair <int, int> P;

int main() {

	int V, E, K;
	vector <P> adj[MAX_V];
	cin >> V >> E >> K; K--;
	
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w; // cin , cout�� printf, scanf�� ���� ������?
		adj[u - 1].push_back(P(v - 1, w));
	}


	int dist[MAX_V];
	fill(dist, dist + MAX_V, INF);
	
	bool visited[MAX_V] = { 0 };
	
	priority_queue<P, vector<P>, greater<P>> PQ;
	//���ͽ�Ʈ��
	
	dist[K] = 0;
	PQ.push(P(0, K));
	while (!PQ.empty()) { // ���⵵ �켱���� ť �κ��� ��� �۵��ϴ��� ������ ���߰ڴ�
		int curr;
		do {
			curr = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && visited[curr]); // �� �κ� ������ ������ ���߰ڴ�//

		if (visited[curr])
			break;
		
		visited[curr] = true;
		for (auto p = adj[curr].begin(); p != adj[curr].end(); ++p) {//
			int next = p->first, distance = p->second; // �̰� ȭ��ǥ�� ������ ������
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