#include <iostream>
using namespace std;

int main() {

	int sugar;
	int five_bag, three_bag;
	cin >> sugar;

	five_bag = sugar / 5;

	while (five_bag >= 0) {
		
		if ((sugar - (5 * five_bag)) % 3 != 0) { // ���� 5������ ì��� ���� ������ 3������ �ִµ� ������ ���
			five_bag--;
		}
		else if((sugar - (5 * five_bag)) % 3 == 0) { // ���� 5������ ì��� ���� ������ 3������ �ִµ� ������ ���
			three_bag = (sugar - (5 * five_bag)) / 3;
			cout << five_bag + three_bag;
			break;
		}
		
		if ((sugar == 4) || (sugar == 7)) { // �����ؼ� ���� � ���ε� ���� �� �� ���� ���
			cout << -1;
			break;
		}
	}

}