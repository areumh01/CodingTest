#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n <= s) {
        int q = s / n;
        int r = s % n;
        for (int i = 0; i < n; i++) {
            if (i < n - r) {
                answer.push_back(q);
            }
            else {
                answer.push_back(q + 1);
            }
        }
    }
    else {
        answer.push_back(-1);
    }
    return answer;
}