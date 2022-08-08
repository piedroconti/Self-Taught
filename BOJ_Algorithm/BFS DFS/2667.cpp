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

			DFS(x, y + 1); //��
			DFS(x, y - 1); //��
			DFS(x - 1, y); //��
			DFS(x + 1, y); //��
						
			
		}
	
}


int main() {
	int complex_num;
	
	cin >> complex_num;
	
	for (int i = 0; i < complex_num; i++) {
		for (int j = 0; j < complex_num; j++) {
		
			scanf("%1d", &arr[i][j]);  // scanf()�� �⺻������ ����(space)�̳� ����(enter)�� �������� �Է��� �ޱ⿡ �����̳� ���� ���� 
			                          //�� �ٷ� �� �Է��� �Ѵٸ� �Է��� ���������� �̷������ �ʽ��ϴ�. 
			                         //������ scanf("%1d",&temp)�� ���� %1d�� ����ϸ� �پ��־ �� ���� �� ���� �Է¹��� �� �ֽ��ϴ�.
			
		}
	}

	for (int i = 0; i < complex_num; i++) {
		for (int j = 0; j < complex_num; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) { //!! �ٽ� ����Ʈ !! ���߿� ������ ��
				
				
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
