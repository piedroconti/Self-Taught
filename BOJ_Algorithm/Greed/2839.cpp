#include <iostream>
using namespace std;

int main() {

	int sugar;
	int five_bag, three_bag;
	cin >> sugar;

	five_bag = sugar / 5;

	while (five_bag >= 0) {
		
		if ((sugar - (5 * five_bag)) % 3 != 0) { // 설탕 5봉지씩 챙기고 남은 설탕을 3봉지씩 넣는데 실패한 경우
			five_bag--;
		}
		else if((sugar - (5 * five_bag)) % 3 == 0) { // 설탕 5봉지씩 챙기고 남은 설탕을 3봉지씩 넣는데 성공한 경우
			three_bag = (sugar - (5 * five_bag)) / 3;
			cout << five_bag + three_bag;
			break;
		}
		
		if ((sugar == 4) || (sugar == 7)) { // 급조해서 만든 어떤 경우로도 답을 낼 수 없는 경우
			cout << -1;
			break;
		}
	}

}