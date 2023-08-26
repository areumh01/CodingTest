#include<iostream>
#include<vector>

using namespace std;

int n, m;
int x[4] = { -1,0,1,0 };
int y[4] = { 0,1,0,-1 };
int home[52][52];
int answer = 0;

bool isValid(int x, int y) {
	if (x > 0 && x < n - 1 && y > 0 && y < m - 1) return true;
	return false;
}

int main() {
	cin >> n >> m;
	int cx, cy, cd;
	cin >> cx >> cy >> cd;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> home[i][j];
		}
	}

	while (true) {
		int c = 0;
		//�� �ڸ� û��, 1��
		if (home[cx][cy] == 0) {
			home[cx][cy] = 2;
			answer++;
		}
		//3��
		while (c != 4) {
			//ȸ��
			if (cd == 0) cd = 3;
			else cd--;
			//���� ���⿡�� ������ ����
			int nextx = cx + x[cd];
			int nexty = cy + y[cd];
			if (home[nextx][nexty] == 0) {
				cx = nextx;
				cy = nexty;
				break;
			}
			c++;
		}
		//2��
		if (c == 4) {
			//����
			int backx = cx - x[cd];
			int backy = cy - y[cd];

			if (home[backx][backy] == 1) break;

			cx = backx;
			cy = backy;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << home[i][j] << " ";
	//	}cout << '\n';
	//}

	cout << answer;
}