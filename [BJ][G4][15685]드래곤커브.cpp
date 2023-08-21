/*
* ������ �� ���Ѵ����� ���� ������ ��� �̵��ϸ鼭 �湮ó���ϸ�ȴ�.
* �� �������� ��� �湮ó���� �Ǵ��� Ȯ�� -> �� �簢���� ���ʻ�� ��ǥ�� �ְ� üũ�ϴ� �Լ��� ����
*/

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int n, answer = 0;
int map[101][101];
int x[4] = { 1,0,-1,0 };
int y[4] = { 0,-1,0,1 };

int check() {
	int counting = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) counting++;
		}
	}
	return counting;
}

int main() {
	cin >> n;
	int cx, cy, d, g;
	memset(map, 0, sizeof(map));
	for (int i = 0; i < n; i++) {
		cin >> cx >> cy >> d >> g;
		vector<int> dir = { d };
		map[cx][cy] = 1;
		for (int j = 1; j <= g; j++) {
			vector<int> tmp;
			for (int e = dir.size() - 1; e >= 0; e--) {
				tmp.push_back((dir[e] + 1) % 4);
			}
			for (auto e : tmp) {
				dir.push_back(e);
			}
		}
		//for (auto e : dir) cout << e << " ";
		//cout << '\n';
		for (int i = 0; i < dir.size(); i++) {
			cx += x[dir[i]];
			cy += y[dir[i]];
			if (cx >= 0 && cx <= 100 && cy >= 0 && cy <= 100) map[cx][cy] = 1;
		}
		//for (int i = 0; i < 10; i++) {
		//	for (int j = 0; j < 10; j++) {
		//		cout << map[i][j] << " ";
		//	}cout << '\n';
		//}
	}
	answer = check();
	cout << answer << '\n';
}