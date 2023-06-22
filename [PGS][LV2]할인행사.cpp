#include <string>
#include <vector>
#include <map>

using namespace std;

int answer = 0;
int start = 0;
int last = 9;
map<string, int> wantlist;
map<string, int> m;

void check() {
    map<string, int>::iterator it;
    for (it = wantlist.begin(); it != wantlist.end(); it++) {
        if (m[it->first] >= it->second) continue;
        else return;
    }
    answer++;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    //����ϴ� ��� ����
    for (int i = 0; i < want.size(); i++) {
        wantlist[want[i]] = number[i];
    }
    //�ʱ� 10�� ����
    for (int i = 0; i < 10; i++) {
        m[discount[i]]++;
    }

    while (start <= last) {
        check();
        m[discount[start]]--;
        start++;
        if (last < discount.size() - 1) {
            last++;
            m[discount[last]]++;
        }
    }

    return answer;
}