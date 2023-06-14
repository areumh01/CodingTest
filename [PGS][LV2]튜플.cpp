#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    stringstream ss;
    ss.str(s);
    string tmp;
    vector<int> answer;
    map<int, int> m;

    while (getline(ss, tmp, '}')) {
        string sub = "";
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] == ',') {
                if (sub != "") m[stoi(sub)]++;
                sub = "";
                continue;
            }
            if (tmp[i] - '0' <= 9 && tmp[i] - '0' >= 0) {
                sub += tmp[i];
            }
        }
        if (sub != "") m[stoi(sub)]++;
    }
    answer.resize(m.size());

    map<int, int>::iterator  it;
    for (it = m.begin(); it != m.end(); it++) {
        answer[m.size() - it->second] = it->first;
    }

    return answer;
}