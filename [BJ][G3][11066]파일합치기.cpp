#include<iostream>
#include<queue>

using namespace std;

int n, m;
int dp[502][502];
int costs[502];
int sum[502];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> costs[j];
			sum[j] = sum[j - 1] + costs[j];
		}
		for (int d = 1; d < m; d++) {
			for (int tx = 1; tx + d <= m; tx++) {
				int ty = tx + d;
				dp[tx][ty] = 1e8;
				for (int mid = tx; mid < ty; mid++) {
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}
		cout << dp[1][m] << '\n';
	}
}