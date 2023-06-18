#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
int last = 0;
vector<int> answer;

//사전에 없는 단어 저장
void new_word(string s) {
    m[s] = last + 1;
    last++;
}

//사전의 색인 번호를 출력
void save_answer(string s) {
    s.pop_back();
    answer.push_back(m[s]);
}

vector<int> solution(string msg) {
    int index = 0;

    //길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    while (last < 26) {
        string alpha = "";
        alpha += 'A' + last;
        m[alpha] = last + 1;
        last++;
    }

    while (index != msg.size()) {
        string sub = "";
        sub += msg[index];
        //사전에 없는 문자열이 나타날 때까지 문자 붙인다
        while (m[sub] != 0) {
            sub += msg[++index];
        }
        //사전에 없는 문자열 추가
        new_word(sub);
        //색인 번호 출력
        save_answer(sub);
    }
    return answer;
}