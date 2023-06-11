#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string tmp;
    vector<vector<string>> splited;
    for (int i = 0; i < record.size(); i++) {
        stringstream ss;
        ss.str(record[i]);
        vector<string> sub;
        while (getline(ss, tmp, ' ')) {
            sub.push_back(tmp);
        }
        if (sub[0] == "Enter" || sub[0] == "Change") m[sub[1]] = sub[2];
        splited.push_back(sub);
    }
    for (int i = 0; i < splited.size(); i++) {
        string s = "";
        if (splited[i][0] == "Enter") {
            s += m[splited[i][1]];
            s += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        }
        else if (splited[i][0] == "Leave") {
            s += m[splited[i][1]];
            s += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        }
        else continue;
        answer.push_back(s);
    }
    return answer;
}