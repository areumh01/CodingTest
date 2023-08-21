/*
* 방문 처리 -> 들어갔다가 -> 나와서 방문처리 취소
* dfs
*/

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int n, m;
int answer = 0;
vector<string> map(22);
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };
bool visited[22][22];
bool alpha[28];

void dfs(int cx, int cy, int counting) {
	bool check = false;
	for (int i = 0; i < 4; i++) {
		int nextx = cx + x[i];
		int nexty = cy + y[i];

		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && !visited[nextx][nexty] && !alpha[map[nextx][nexty] - 'A']) {
			alpha[map[nextx][nexty] - 'A'] = true;
			visited[nextx][nexty] = true;
			dfs(nextx, nexty, counting + 1);
			alpha[map[nextx][nexty] - 'A'] = false;
			visited[nextx][nexty] = false;
			check = true;
		}
	}
	if (!check) {
		answer = max(answer, counting);
		return;
	}
}

int main() {
	cin >> n >> m;
	memset(visited, false, sizeof(visited));
	memset(alpha, false, sizeof(alpha));

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	visited[0][0] = true;
	alpha[map[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << answer << '\n';
}