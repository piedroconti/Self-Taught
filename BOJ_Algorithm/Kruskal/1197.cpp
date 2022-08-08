#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int tree[10001];
int v, e;
int result = 0;
vector <tuple< int, int, int> > edges;

// ���Ͽ� ���ε� 
int findroot(int n) {
	if (n == tree[n]) return n;
	return tree[n] = findroot(tree[n]); //findroot(n) �ƴ� �̷��� �θ� ��� ��ȯ�ϸ鼭 �����ϴ°��� �ƴ϶� �ڱ��ڽ� ������ȣ�� ������ ��ȯ�ϹǷ� 
}                                        // ���ѹݺ��ϴٰ� ����Ʈ �̸� ���Ѵ�.

void unionroot(int a, int b) {
	a = findroot(a);
	b = findroot(b);
	
	if (a > b) tree[a] = b;
	else tree[b] = a;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) //tree�� 1 ���� �����Ѵ�. 0���� �ϸ� 3���� ������ tree[0] ~ tree[2]
		tree[i] = i;            // ������ ä������ tree[3] �� �ʱ� �θ� 0�� �Ǿ������.

	for (int i = 0; i < e; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;

		edges.push_back( tuple<int, int, int>(cost, a, b) );
	}
	// ũ�罺Į 
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