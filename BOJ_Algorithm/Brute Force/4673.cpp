#include <iostream>
using namespace std;

int main() {
	int num;
	int selfnum[10030]; //�������� ġ������ ������ ���̴� �迭 index�� ��������

	for (int i = 0; i < 10030; i++)
		selfnum[i] = i;

	
	for (int i = 0; i < 10000; i++) {
		int temp = i;
		num = temp;
		
		while (temp) {
			num += temp % 10;
			temp = temp / 10;
		}
		
		selfnum[num] = NULL; //�ƴ� num ���� 10000�� ���ǿ� �Ѱ� �Ǵµ� �迭�� 10000������ ����� �翬�� �ȵ���;;; �̰� ������ 3�ð��� ���ȳ�
		
	}

	
	for (int i = 0; i < 10000; i++) {
		if (selfnum[i] != NULL)
			cout << selfnum[i] << endl;
	}

	
}