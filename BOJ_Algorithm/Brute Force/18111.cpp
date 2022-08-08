#include <iostream>
using namespace std;

int main() {

	int N, M, B;
	int land[501][501];
	int time[257] = { 0 }; // 0 ~ 256
	int block[257] = { 0 };
	int heigh = 257; // 0 ~ 256
	int min_t = 1000000000; int max_h;
	cin >> N >> M >> B;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> land[i][j];
		}
	}

	

	for (int h = 0; h <= 256; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				if (h > land[i][j]) {
					time[h] += h - land[i][j];
					block[h] += h - land[i][j];
				}
				else if (h < land[i][j]) {
					time[h] += 2 * (land[i][j] - h);
					block[h] += h - land[i][j];
				}
				else {
					;
				}
							
			}
		}
	}

	while (heigh--) {
		if (min_t > time[heigh] && B >= block[heigh]) {
			min_t = min(min_t, time[heigh]);
			max_h = heigh;
		}
	}

	cout << min_t << " " << max_h;
}