/*
* 필요한 변수 : 톱니바퀴들의 머리를 저장하는 배열, 돌리는지 여부와 방향을 저장하는 벡터(-1,1,0)
* 배열에 각 톱니바퀴의 12시 방향 위치를 저장한다.
* 입력을 받고 돌려야할 때 전체적으로 누구를 돌릴지 결정한다
* 돌려야하는 톱니바퀴를 기준으로 왼쪽오른쪽 검사하고 만약 바뀌지 않는다면 더이상 검사하지 않고 바뀌는 경우에는 계속 검사 진행
* 기준으로부터 1까지 true가 나오면 계속 진행 오른쪽도 동일하게 진행 while문으로 true&&left>0
* 돌려야하는 방향을 저장하는 배열도 생성
* 돌려야하는 방향을 결정한 거를 바탕으로 12시 방향 업데이트
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
		if (who == 0) //left가 변경 타겟
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
		//num을 기준으로 각 톱니바퀴들의 극 검사
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

		//실제로 돌리기
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