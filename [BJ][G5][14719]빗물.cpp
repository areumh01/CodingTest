#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m, answer = 0;
	cin >> n >> m;
	vector<int> v(505);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < m - 1; i++) {
		int l = 0;
		int r = 0;
		for (int j = 0; j < i; j++) l = max(l, v[j]);
		for (int j = i + 1; j < m; j++) r = max(r, v[j]);
		answer += max(0, min(l, r) - v[i]);
	}
	cout << answer;
}