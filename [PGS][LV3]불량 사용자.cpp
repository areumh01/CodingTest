#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> s;
bool visited[10];
int answer = 0;

void dfs(vector<string>& user_id, vector<string>& banned_id, int index) {
    if (index == banned_id.size()) {
        //�ߺ��Ǵ� ���̽��� ���� �ȵ�
        string st = "";
        //user_id������� �湮 ó���� ���ڵ��� ���ڿ��� ���� set�� �����ϸ� �ߺ� �˾Ƽ� �ɷ���
        for (int i = 0; i < user_id.size(); i++) {
            if (visited[i] == true) st += to_string(i);
        }
        s.insert(st);
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        if (visited[i]) continue;
        bool flag = true;
        if (banned_id[index].size() != user_id[i].size()) continue;
        for (int j = 0; j < user_id[i].size(); j++) {
            if (banned_id[index][j] == '*') continue;
            if (banned_id[index][j] != user_id[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            visited[i] = true;
            dfs(user_id, banned_id, index + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    dfs(user_id, banned_id, 0);
    return s.size();
}