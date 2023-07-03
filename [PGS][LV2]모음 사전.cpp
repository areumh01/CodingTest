#include <string>
#include <vector>

using namespace std;
int answer = 0;
int subcounting = 0;
char vowel[5] = { 'A','E','I','O','U' };
string target;

void dfs(int index, int count, string s) {
    if (answer != 0) return;
    s += vowel[index];
    subcounting++;
    if (s == target) { answer = subcounting; return; }
    if (count == 4) return;
    for (int i = 0; i < 5; i++) {
        dfs(i, count + 1, s);
    }
}

int solution(string word) {
    target = word;
    for (int i = 0; i < 5; i++) {
        if (answer == 0) dfs(i, 0, "");
    }
    return answer;
}