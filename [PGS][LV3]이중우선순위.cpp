#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    deque<int> dq;

    for (int i = 0; i < operations.size(); i++) {
        string num = "";
        for (int j = 2; j < operations[i].size(); j++) {
            num += operations[i][j];
        }
        int numbers = stoi(num);

        if (operations[i][0] == 'I') {
            dq.push_back(numbers);
            sort(dq.begin(), dq.end());
        }
        if (operations[i][0] == 'D') {
            if (dq.size() == 0) continue;
            if (numbers == 1) {
                dq.pop_back();
            }
            if (numbers == -1) {
                dq.pop_front();
            }
        }
    }

    vector<int> answer;
    if (dq.size() == 0) answer = { 0,0 };
    else if (dq.size() == 1) answer.push_back(dq.front());
    else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}