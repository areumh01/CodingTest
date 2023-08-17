#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

bool result[502][502];
int comp[502];
int answer = 0;

int main() {
	int n, m;
	cin >> n >> m;
	memset(result, false, sizeof(result));
	memset(comp, 0, sizeof(comp));

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		result[b - 1][a - 1] = true;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) {
					result[i][j] = true;
					continue;
				}
				result[i][j] = (result[i][j] || (result[i][k] && result[k][j]));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (result[i][j] || result[j][i]) comp[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		if (comp[i] == n) answer++;

	cout << answer << '\n';
}