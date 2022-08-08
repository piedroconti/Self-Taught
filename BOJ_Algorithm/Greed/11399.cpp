#include <iostream>
using namespace std;

int main() {
	int arr[1000];
	int temp;
	int count;
	int total = 0;
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
		scanf("%d", &arr[i]);


	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	
	for (int i = 0; i < count; i++)
		for (int j = 0; j <= i; j++)
			total += arr[j];

	printf("%d", total);

	return 0;
}