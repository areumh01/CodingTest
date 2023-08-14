#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>

using namespace std;

int n, m;
int memo[32002];
vector<vector<int>> comp;

int find(int n) {
	if (memo[n] != -1) return memo[n];
	if (comp[n].size() == 0) return memo[0] = 0;
	int maxx = 0;

	for (int i = 0; i < comp[n].size(); i++) {
		maxx = max(maxx, find(comp[n][i]) + 1);
	}

	return memo[n] = maxx;
}

int main() {
	cin >> n >> m;
	vector<pair<int, int>> answer;
	comp.resize(n + 2);

	for (int i = 0; i < m; i++) {
		int winner, loser;
		cin >> winner >> loser;
		comp[winner].push_back(loser);
	}
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= n; i++) {
		answer.push_back({ find(i),i });
	}

	sort(answer.begin(), answer.end(), greater<>());
	for (auto e : answer) cout << e.second << " ";
}