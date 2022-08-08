#include <iostream>
using namespace std;

int main() {
	int num;
	int selfnum[10030]; //기초지만 치명적인 허점을 보이는 배열 index를 조심하자

	for (int i = 0; i < 10030; i++)
		selfnum[i] = i;

	
	for (int i = 0; i < 10000; i++) {
		int temp = i;
		num = temp;
		
		while (temp) {
			num += temp % 10;
			temp = temp / 10;
		}
		
		selfnum[num] = NULL; //아니 num 값이 10000을 막판에 넘게 되는데 배열을 10000까지만 만들면 당연히 안되지;;; 이거 가지고 3시간은 날렸네
		
	}

	
	for (int i = 0; i < 10000; i++) {
		if (selfnum[i] != NULL)
			cout << selfnum[i] << endl;
	}

	
}