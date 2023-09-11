#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, maxx = 0;
	cin >> n;
	int bs[55];
	for (int i = 0; i < n; i++) {
		cin >> bs[i];
	}
	for (int i = 0; i < n; i++) {
		int l = 0, r = 0;
		double ls = 0, rs = 0;
		if (i >= 1) {
			l = 1;
			ls = (bs[i] - bs[i - 1]) / (double)(1);
		}
		if (i < n - 1) {
			r = 1;
			rs = (bs[i + 1] - bs[i]) / (double)(1);
		}
		for (int j = i - 2; j >= 0; j--) {
			double slope = (bs[i] - bs[j]) / (double)(i - j);
			if (ls > slope) {
				ls = slope;
				l++;
			}
		}
		for (int j = i + 2; j < n; j++) {
			double slope = (bs[j] - bs[i]) / (double)(j - i);
			if (slope > rs) {
				rs = slope;
				r++;
			}
		}
		maxx = max(maxx, l + r);
	}
	cout << maxx;
}