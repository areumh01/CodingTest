#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> s;
bool visited[10];
int answer = 0;

void dfs(vector<string>& user_id, vector<string>& banned_id, int index) {
    if (index == banned_id.size()) {
        //중복되는 케이스는 세면 안됨
        string st = "";
        //user_id순서대로 방문 처리된 숫자들을 문자열로 만들어서 set에 저장하면 중복 알아서 걸러줌
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