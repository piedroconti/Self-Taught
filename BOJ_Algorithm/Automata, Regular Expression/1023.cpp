#include <iostream>
#include <string>
#define TRAP 9; // DFA의 오토마타 경로를 벗어나면 state q9로 보낸다
using namespace std;

int DFA[10][2];
int qi = 0;
bool fin[10] = { false };
string tape;

int main() {
	
	int attempt;
	cin >> attempt;

	DFA[0][1] = 1;	 
	DFA[0][0] = 5;	DFA[1][1] = TRAP;
	DFA[1][0] = 2;	DFA[2][1] = TRAP;
	DFA[2][0] = 3;	DFA[5][0] = TRAP;
	DFA[3][0] = 3;	DFA[9][0] = TRAP; // 오토마타를 배워본적이 없어 맞는 표현인지는 모르겠지만 일단 q9은 nonfinal trap state 이다.
	DFA[3][1] = 4;  DFA[9][1] = TRAP;
	DFA[4][0] = 5;
	DFA[4][1] = 7;
	DFA[5][1] = 6;
	DFA[6][0] = 5;
	DFA[6][1] = 1;
	DFA[7][0] = 8;
	DFA[7][1] = 7;
	DFA[8][0] = 3;
	DFA[8][1] = 6;

	fin[7] = fin[4] = fin[6] = true;


	while (attempt--) {
		cin >> tape;

		for (auto p = tape.begin(); p != tape.end(); p++) {
			qi = DFA[qi][(int)*p - 48];
		}


		if (fin[qi])
			cout << "YES";
		else
			cout << "NO";
		
		qi = 0;
	}
}