/*
* �߾Ӱ��� pq�� 2�� �Ἥ �ذ�
*/

#include<iostream>
#include<queue>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	priority_queue<int> pq1; //�߾Ӱ� ���� �ִ���
	priority_queue<int, vector<int>, greater<>> pq2; //�߾Ӱ����� ū �ֵ� �ּ���

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		if (pq1.empty() && pq2.empty()) {
			pq1.push(tmp);
		}
		else if (pq1.top() < tmp) {
			pq2.push(tmp);
			if (pq1.size() < pq2.size()) {
				pq1.push(pq2.top());
				pq2.pop();
			}
		}
		else if (pq1.top() >= tmp) {
			pq1.push(tmp);
			if (pq1.size() - pq2.size() > 1) {
				pq2.push(pq1.top());
				pq1.pop();
			}
		}
		cout << pq1.top() << '\n';
	}
}