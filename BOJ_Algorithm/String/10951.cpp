#include <iostream>
using namespace std;

int main() {
	int first, second;

	while (!(cin >> first >> second).eof()) {
		cout << first + second << endl;
	}

	return 0;
}