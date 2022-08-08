#include <iostream>>
using namespace std;

int K, N;
int LAN_cable[10001];
int cut_cable = 0;
long long mid;
long long lo = 0, hi = 10000000000;

int main() {

	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> LAN_cable[i];
	}

	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;

		for (int i = 0; i < K; i++) {
			cut_cable += LAN_cable[i] / mid;
		}
		if (cut_cable < N) { hi = mid; }
		if (cut_cable >= N) { lo = mid; }

		cut_cable = 0;
	}

	cout << lo;
}