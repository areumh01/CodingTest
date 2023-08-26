#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> numbers;
vector<int> calc;
int maxanswer = -1e10;
int minanswer = 1e10;

void dfs(int n, int result) {
	if (n == numbers.size()) {
		maxanswer = max(maxanswer, result);
		minanswer = min(minanswer, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (calc[i] != 0) {
			calc[i]--;
			if (i == 0) dfs(n + 1, result + numbers[n]);
			else if (i == 1) dfs(n + 1, result - numbers[n]);
			else if (i == 2) dfs(n + 1, result * numbers[n]);
			else if (i == 3) dfs(n + 1, result / numbers[n]);
			calc[i]++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}
	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		calc.push_back(a);
	}
	dfs(1, numbers[0]);
	cout << maxanswer << "\n" << minanswer << '\n';
}