#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m; //누가 말했는지 저장
    int game = 1;
    int i = 1;
    for (int j = 0; j < words.size(); j++) {
        if (i == n + 1) {
            game++;
            i = 1;
        }
        if (j != 0 && words[j - 1].back() != words[j][0]) {
            answer.push_back(i);
            answer.push_back(game);
            break;
        }
        if (m[words[j]] != 0) {
            answer.push_back(i);
            answer.push_back(game);
            break;
        }
        m[words[j]] = i++;
    }
    if (answer.size() == 0) answer = { 0,0 };
    return answer;
}