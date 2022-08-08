#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
const int INF = 987654321;
using namespace std;
typedef pair <int, int> P;

int dist[1000]; 
bool visited[1000];
vector <P> adj[1000];
priority_queue<P, vector<P>, greater<P>> PQ;



void dijkstra(int K) {
	dist[K] = 0;
	PQ.push(P(0, K));
	//visited[K] = true;  방문처리를 여기서 하면, 하든 말든 상관없이 while (PQ가 비어있지 않다) 조건을 만족하지 않아 그냥 통과하므로 아무런 상관이 없다.

	while (!PQ.empty()) {
		int curr;

			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[curr]);
			//if (visited[curr]) break; 하지만 이게 문제가 된다. 따라서 둘중 하나만 넣든가 둘다 빼든가 근데 이거는 빼도 되는건지 몰?루
			
			visited[curr] = true;
			for (auto p = adj[curr].begin(); p != adj[curr].end(); p++) {
				int next = p->first; int d = p->second;
				
				if (dist[next] > dist[curr] + d) {
					dist[next] = dist[curr] + d;
					PQ.push(P(dist[next], next));
				}
			}

	}
}

int main() {
	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back(P(v - 1, w));
		adj[v - 1].push_back(P(u - 1, w));
	}

	int pass1, pass2;
	int  a1, a2, a3, b1, b2, b3 ,res1, res2;
	cin >> pass1 >> pass2; pass1--; pass2--;
	/*--------------------------------------------- case1*/
	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(0);

	a1 = dist[pass1];

	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(pass1);

	a2 = dist[pass2];

	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(pass2);
	a3 = dist[N - 1];
	/*-----------------------------------------------case2*/
	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(0);

	b1 = dist[pass2];

	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(pass2);

	b2 = dist[pass1];

	fill(dist, dist + 1000, INF);
	fill(visited, visited + 1000, false);

	dijkstra(pass1);
	b3 = dist[N - 1];
	/*----------------------------------------------*/

	if (a1 == INF || a2 == INF || a3 == INF) res1 = INF;
	else res1 = a1 + a2 + a3;

	if (b1 == INF || b2 == INF || b3 == INF) res2 = INF;
	else res2 = b1 + b2 + b3;

	if (res1 == INF && res2 == INF) cout << -1;
	else cout << min(res1, res2);



	
}
	
/* 1->a->b->N 인 경우의 최단 거리만 구하는 것이 아니라 1->b->a->N 인 경우도 구하는것이다 
   문제를 똑바로 읽자. 아무래도 철저하게 머릿속에서 설계 다하고 푸는 것도 생각해 봐야 할 듯

   마지막 출력 부분 때문에 애먹은 건 솔직히 뭘 보완해야 한다고 하지를 못하겠다 그냥 다음에는 그럴일이 없길 바랄 수 밖에...
*/
