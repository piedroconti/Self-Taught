#include <iostream>
//#include <algorithm>
using namespace std;

int main() {
	int N, M; //카드 수, 맞쳐야 하는 숫자
	cin >> N >> M;
	
	// int total[1000];
	int total, max = 0;
	int arr[100];
	// int cnt = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) { // i = 0; i < N-2
		for (int j = i + 1; j < N; j++) { // j = 1; j < N - 1  
			for (int d = j + 1; d < N; d++) { // j = 2; j < N -2 가 아닌 이유 복습
				total = arr[i] + arr[j] + arr[d];                                    // 배열 하나씩 변수를 0으로 바꾸어 어디 배열에 문제가 생겼는지 파악

				if (total > max && total <= M)
					max = total;
			}
		}
	}
	
	cout << max;
	
	
	/*int count = 0;
	for (int i = 0; i < cnt; i++) {
		if (total[i] <= M) {
			total[count] -= M;                          발적화 그자체, 위와 비교 후 복습
			count++;
		}
	}
	sort(total, total + count);

	cout << total[0]; */
}