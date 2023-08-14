#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int sq[102][102];
bool visited[102][102];
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };

bool isValid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m) return true;
	else return false;
}

int main() {
	cin >> n >> m;
	queue<pair<int, int>> air;
	queue<pair<int, int>> cheese;
	int answer = 0;
	int lastnum = 0;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) air.push({ i,j });
			cin >> sq[i][j];
		}
	}
	while (true) {
		while (!air.empty()) {
			int currentx = air.front().first;
			int currenty = air.front().second;
			air.pop();
			for (int i = 0; i < 4; i++) {
				int nextx = currentx + x[i];
				int nexty = currenty + y[i];
				if (isValid(nextx, nexty) && !visited[nextx][nexty]) {
					visited[nextx][nexty] = true;
					if (sq[nextx][nexty] == 1) cheese.push({ nextx,nexty });
					else air.push({ nextx,nexty });
				}
			}
		}
		if (cheese.empty()) break;

		answer++;
		lastnum = 0;
		while (!cheese.empty()) {
			int cx = cheese.front().first;
			int cy = cheese.front().second;
			cheese.pop();
			sq[cx][cy] = 0;
			air.push({ cx,cy });
			lastnum++;
		}
	}
	cout << answer << '\n' << lastnum;
}