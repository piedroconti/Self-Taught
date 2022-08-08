#include <iostream>
#include <string>
#define TRAP 9; // DFA�� ���丶Ÿ ��θ� ����� state q9�� ������
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
	DFA[3][0] = 3;	DFA[9][0] = TRAP; // ���丶Ÿ�� ��������� ���� �´� ǥ�������� �𸣰����� �ϴ� q9�� nonfinal trap state �̴�.
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