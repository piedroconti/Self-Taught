#include <iostream>
//#include <algorithm>
using namespace std;

int main() {
	int N, M; //ī�� ��, ���ľ� �ϴ� ����
	cin >> N >> M;
	
	// int total[1000];
	int total, max = 0;
	int arr[100];
	// int cnt = 0;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) { // i = 0; i < N-2
		for (int j = i + 1; j < N; j++) { // j = 1; j < N - 1  
			for (int d = j + 1; d < N; d++) { // j = 2; j < N -2 �� �ƴ� ���� ����
				total = arr[i] + arr[j] + arr[d];                                    // �迭 �ϳ��� ������ 0���� �ٲپ� ��� �迭�� ������ ������� �ľ�

				if (total > max && total <= M)
					max = total;
			}
		}
	}
	
	cout << max;
	
	
	/*int count = 0;
	for (int i = 0; i < cnt; i++) {
		if (total[i] <= M) {
			total[count] -= M;                          ����ȭ ����ü, ���� �� �� ����
			count++;
		}
	}
	sort(total, total + count);

	cout << total[0]; */
}