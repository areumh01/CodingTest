#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> coins;
	vector<int> results(10002);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		coins.push_back(tmp);
	}

	results[0] = 1;
	for (int j = 0; j < coins.size(); j++) {
		for (int i = 1; i <= m; i++) {
			if (i >= coins[j]) {
				results[i] += results[i - coins[j]];
			}
		}
	}
	cout << results[m];
}