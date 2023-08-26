/*
* �ʿ��� ���� : ��Ϲ������� �Ӹ��� �����ϴ� �迭, �������� ���ο� ������ �����ϴ� ����(-1,1,0)
* �迭�� �� ��Ϲ����� 12�� ���� ��ġ�� �����Ѵ�.
* �Է��� �ް� �������� �� ��ü������ ������ ������ �����Ѵ�
* �������ϴ� ��Ϲ����� �������� ���ʿ����� �˻��ϰ� ���� �ٲ��� �ʴ´ٸ� ���̻� �˻����� �ʰ� �ٲ�� ��쿡�� ��� �˻� ����
* �������κ��� 1���� true�� ������ ��� ���� �����ʵ� �����ϰ� ���� while������ true&&left>0
* �������ϴ� ������ �����ϴ� �迭�� ����
* �������ϴ� ������ ������ �Ÿ� �������� 12�� ���� ������Ʈ
*/

#include<iostream>
#include<vector>
#include<string.h>
#include<math.h>

using namespace std;

string s[4];
int head[4] = { 0,0,0,0 };
int rotatedir[4] = { 0,0,0,0 };

bool check(int left, int right, int who) {
	int lefts = s[left][(head[left] + 2) % 8];
	int rights = s[right][(head[right] + 6) % 8];
	//cout << left << " " << right << " " << lefts << " " << (head[left] + 2) % 8 << " " << rights << " " << (head[left] + 6) % 8 << '\n';
	if (lefts != rights) {
		if (who == 0) //left�� ���� Ÿ��
			rotatedir[left] = (rotatedir[right] == 1) ? -1 : 1;
		else
			rotatedir[right] = (rotatedir[left] == 1) ? -1 : 1;
		return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, dir;
		cin >> num >> dir;
		//num�� �������� �� ��Ϲ������� �� �˻�
		rotatedir[num - 1] = dir;

		int left = num - 1;
		int right = num;
		bool flag = true;
		while (left > 0 && flag) {
			flag = check(left - 1, right - 1, 0);
			left--;
			right--;
		}

		left = num;
		right = num + 1;
		flag = true;
		while (right < 5 && flag) {
			flag = check(left - 1, right - 1, 1);
			left++;
			right++;
		}

		//������ ������
		for (int i = 0; i < 4; i++) {
			if (rotatedir[i] == 1)
				head[i] = (head[i] + 7) % 8;
			else if (rotatedir[i] == -1)
				head[i] = (head[i] + 1) % 8;
		}
		memset(rotatedir, 0, sizeof(rotatedir));
	}
	int answer = 0;
	for (int i = 0; i < 4; i++) {
		if (s[i][head[i]] == '1') answer += pow(2, i);
	}
	cout << answer;
}