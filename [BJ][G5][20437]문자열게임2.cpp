#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int all[10002][27];
int counting[27];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int number, minn = 1e8, maxx = 0;
		cin >> s >> number;
		memset(counting, 0, sizeof(counting));
		memset(all, 0, sizeof(all));
		for (int l = 0; l < s.size(); l++) {
			int index = s[l] - 'a';
			all[counting[index]][index] = l;
			counting[index]++;
		}
		for (int a = 0; a < 26; a++) {
			if (counting[a] >= number) {
				for (int l = counting[a] - 1; l >= number - 1; l--) {
					minn = min(minn, all[l][a] - all[l - number + 1][a] + 1);
					maxx = max(maxx, all[l][a] - all[l - number + 1][a] + 1);
				}
			}
		}
		if (minn == 1e8)
			cout << -1 << '\n';
		else
			cout << minn << " " << maxx << '\n';
	}
}