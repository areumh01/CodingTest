#include<iostream>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> schedule(20);
vector<int> endDate(20);
int answer = 0;

void dfs(int start, int money) {
	if (start > n) {
		answer = max(answer, money);
		return;
	}
	//상담을 받고 넘어가기
	if (endDate[start] <= n)
		dfs(endDate[start] + 1, money + schedule[start].second);
	//안받고 넘어가기
	dfs(start + 1, money);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		schedule[i] = { a,b }; //며칠 걸리는지 , 비용
		endDate[i] = i + a - 1;
	}
	dfs(1, 0);
	cout << answer << '\n';
}