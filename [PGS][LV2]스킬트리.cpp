#include <string>
#include <vector>
#include <string.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    char check[27];
    memset(check, -1, sizeof(check));

    for (int i = 0; i < skill.size(); i++) {
        check[skill[i] - 'A'] = i;
    }

    for (string s : skill_trees) {
        bool flag = true;
        int last = 0;
        for (char c : s) {
            if (check[c - 'A'] == -1) continue;
            if (check[c - 'A'] != last) flag = false;
            else last++;
        }
        if (flag) answer++;
    }
    return answer;
}