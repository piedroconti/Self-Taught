#include <iostream>
using namespace std;

int cnt;

void printLine(int num) {
	while(num--)           // ���� --�� �ؼ� �ݺ�Ƚ�� ��ŭ �ݺ��ϴ� ���� �������� ���ߴ�.
		cout << "____";
}

void proffessor(int n) {
	printLine(n); cout << "\"����Լ��� ������?\"\n";
	
	if (n != cnt) {
		printLine(n); cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n"; 
		printLine(n); cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		printLine(n); cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		proffessor(n+1); // ����Լ����� return proffessor �������� �׳� proffessor�ϸ� �������� ���Ƽ� ���� �κе� ���డ��
	                     // n++�� �Լ� �߰��� �����ʰ� ����Ҷ� ���ڿ��ٰ� �ϸ� �� ��͸����� Ƚ���� ���� �� �ִٴ� ���� �˰� �Ǿ���.
	} 
	else { 
		printLine(n); cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";

	}
	
	printLine(n); cout << "��� �亯�Ͽ���.\n";
	return;
}



int main() {
	
	cin >> cnt;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";

	proffessor(0);

	
}