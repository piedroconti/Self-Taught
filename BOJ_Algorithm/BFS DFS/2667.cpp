#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[25][25] = { 0 };
bool visited[25][25] = { false };
vector <int> complex;
int result = 0;


void DFS(int x, int  y) {
	if (x <= -1 || x >= 25 || y <= -1 || y >= 25)
		return;
		
		
		if (!visited[x][y] && arr[x][y] == 1) {
			
			visited[x][y] = true;
			result++;

			DFS(x, y + 1); //상
			DFS(x, y - 1); //하
			DFS(x - 1, y); //좌
			DFS(x + 1, y); //우
						
			
		}
	
}


int main() {
	int complex_num;
	
	cin >> complex_num;
	
	for (int i = 0; i < complex_num; i++) {
		for (int j = 0; j < complex_num; j++) {
		
			scanf("%1d", &arr[i][j]);  // scanf()는 기본적으로 공백(space)이나 개행(enter)을 기준으로 입력을 받기에 공백이나 개행 없이 
			                          //한 줄로 쭉 입력을 한다면 입력이 정상적으로 이루어지지 않습니다. 
			                         //하지만 scanf("%1d",&temp)와 같이 %1d를 사용하면 붙어있어도 한 번에 한 개씩 입력받을 수 있습니다.
			
		}
	}

	for (int i = 0; i < complex_num; i++) {
		for (int j = 0; j < complex_num; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) { //!! 핵심 포인트 !! 나중에 복습할 것
				
				
				DFS(i, j);
				complex.push_back(result);
				result = 0;
			}
		}
	}
	
	cout << complex.size() << endl;
	sort(complex.begin(), complex.end());
	for (auto i = complex.begin(); i != complex.end(); i++)
		cout << *i << endl;

}
