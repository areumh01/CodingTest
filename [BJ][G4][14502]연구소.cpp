#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<vector<int>> map(10, vector<int>(10, 0));
vector<pair<int, int>> zeros;
vector<pair<int, int>> virus;
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };
int answer = 0;

int bfs(vector<pair<int, int>>& picked) {
	vector<vector<int>> map_copy = map;
	int contaminated = 0;

	for (auto e : picked) {
		map_copy[e.first][e.second] = 1;
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++) {
		q.push(virus[i]);
	}
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = cx + x[i];
			int nexty = cy + y[i];
			if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && map_copy[nextx][nexty] == 0) {
				map_copy[nextx][nexty] = 2;
				contaminated++;
				q.push({ nextx,nexty });
			}
		}
	}
	return zeros.size() - contaminated;
}

void pick_three_wall(vector<pair<int, int>>picked, int index) {
	if (picked.size() == 3) {
		answer = max(answer, bfs(picked));
		return;
	}
	for (int i = index; i < zeros.size(); i++) {
		picked.push_back(zeros[i]);
		pick_three_wall(picked, i + 1);
		picked.pop_back();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) zeros.push_back({ i,j });
			if (map[i][j] == 2) virus.push_back({ i,j });
		}
	}
	pick_three_wall({}, 0);
	cout << answer - 3;
}