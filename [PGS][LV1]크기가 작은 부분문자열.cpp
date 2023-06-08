#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    bool flag = true;
    int answer = 0;

    for (int i = 0; i <= t.size() - p.size(); i++) {
        flag = true;
        for (int j = 0; j < p.size(); j++) {
            if (t[i + j] < p[j]) break;
            if (t[i + j] == p[j]) {
                continue;
            }
            flag = false;
        }
        if (flag) answer++;
    }
    return answer;
}