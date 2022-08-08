#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int tree[10001];
int v, e;
int result = 0;
vector <tuple< int, int, int> > edges;

// 유니온 파인드 
int findroot(int n) {
	if (n == tree[n]) return n;
	return tree[n] = findroot(tree[n]); //findroot(n) 아님 이러면 부모를 계속 반환하면서 추적하는것이 아니라 자기자신 정점번호를 무한히 반환하므로 
}                                        // 무한반복하다가 사이트 이름 당한다.

void unionroot(int a, int b) {
	a = findroot(a);
	b = findroot(b);
	
	if (a > b) tree[a] = b;
	else tree[b] = a;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) //tree는 1 부터 시작한다. 0부터 하면 3개의 정점을 tree[0] ~ tree[2]
		tree[i] = i;            // 까지만 채워져서 tree[3] 값 초기 부모가 0이 되어버린다.

	for (int i = 0; i < e; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;

		edges.push_back( tuple<int, int, int>(cost, a, b) );
	}
	// 크루스칼 
	sort(edges.begin(), edges.end());

	for (int i = 0; i < edges.size(); i++) {
		int cost = get<0>(edges[i]);
		int a = get<1>(edges[i]);
		int b = get<2>(edges[i]);

		if (findroot(a) != findroot(b)) {
			unionroot(a, b);
			result += cost;
		}
	}

	cout << result;

	return 0;
}