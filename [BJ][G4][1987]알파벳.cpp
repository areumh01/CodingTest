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
int counting = 0;
vector<string> map(22);
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };
bool visited[22][22];
bool alpha[28];

void dfs(pair<int, int> a) {
	alpha[map[a.first][a.second] - 'A'] = true;
	counting++;

	for (int i = 0; i < 4; i++) {
		int nextx = a.first + x[i];
		int nexty = a.second + y[i];
		if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && !alpha[map[nextx][nexty] - 'A']) {
			dfs({ nextx,nexty });
		}
	}
	//빠져나오면 더이상 갈 방법이 없다는 의미
	answer = max(counting, answer);
	counting--;
	alpha[map[a.first][a.second] - 'A'] = false;
}

int main() {
	cin >> n >> m;
	memset(alpha, false, sizeof(alpha));

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	dfs({ 0,0 });
	cout << answer << '\n';
}