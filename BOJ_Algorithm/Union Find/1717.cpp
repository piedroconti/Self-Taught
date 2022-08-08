#include <iostream>
using namespace std;

int p[100000];

int getParent(int n) {
	if (p[n] == n) return n;
	return p[n] = getParent(p[n]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b) p[a] = b;
	else p[b] = a;
}

bool checkParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) // 1부터 시작해라;;;;
		p[i] = i;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		if (u == 0) unionParent(v, w);
		
		if (u == 1)
			if (checkParent(v, w))
				cout << "YES" << "\n";
			else
				cout << "NO" << '\n';
	}

}