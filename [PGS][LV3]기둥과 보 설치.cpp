#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<vector<int>> sanswer;

bool has(vector<int> a) {
    if (sanswer.find(a) == sanswer.end()) return false;
    else return true;
}

bool isValid(set<vector<int>> s) {
    for (auto ele : s) {
        int x = ele[0];
        int y = ele[1];
        int a = ele[2];
        if (a == 0) {//기둥이라면
            vector<int> pos[3] = { {x,y - 1,0},{x - 1,y,1},{x,y,1} };
            if (y == 0 || has(pos[0]) || has(pos[1]) || has(pos[2])) continue;
            return false;
        }
        if (a == 1) {//보라면
            vector<int> pos[4] = { {x,y - 1,0},{x + 1,y - 1,0},{x - 1,y,1},{x + 1,y,1} };
            if (has(pos[0]) || has(pos[1]) || (has(pos[2]) && has(pos[3]))) continue;
            return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (auto ele : build_frame) {
        int x = ele[0];
        int y = ele[1];
        int a = ele[2];
        int b = ele[3];
        if (b == 1) {
            sanswer.insert({ x,y,a });
            if (!isValid(sanswer)) sanswer.erase({ x,y,a });
        }
        else {
            sanswer.erase({ x,y,a });
            if (!isValid(sanswer)) sanswer.insert({ {x,y,a} });
        }
    }
    for (auto a : sanswer) {
        answer.push_back(a);
    }
    return answer;
}