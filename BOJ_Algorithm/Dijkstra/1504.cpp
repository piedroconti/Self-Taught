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
	//visited[K] = true;  �湮ó���� ���⼭ �ϸ�, �ϵ� ���� ������� while (PQ�� ������� �ʴ�) ������ �������� �ʾ� �׳� ����ϹǷ� �ƹ��� ����� ����.

	while (!PQ.empty()) {
		int curr;

			do {
				curr = PQ.top().second;
				PQ.pop();
			} while (!PQ.empty() && visited[curr]);
			//if (visited[curr]) break; ������ �̰� ������ �ȴ�. ���� ���� �ϳ��� �ֵ簡 �Ѵ� ���簡 �ٵ� �̰Ŵ� ���� �Ǵ°��� ��?��
			
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
	
/* 1->a->b->N �� ����� �ִ� �Ÿ��� ���ϴ� ���� �ƴ϶� 1->b->a->N �� ��쵵 ���ϴ°��̴� 
   ������ �ȹٷ� ����. �ƹ����� ö���ϰ� �Ӹ��ӿ��� ���� ���ϰ� Ǫ�� �͵� ������ ���� �� ��

   ������ ��� �κ� ������ �ָ��� �� ������ �� �����ؾ� �Ѵٰ� ������ ���ϰڴ� �׳� �������� �׷����� ���� �ٶ� �� �ۿ�...
*/
