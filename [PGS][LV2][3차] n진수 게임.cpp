#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string str = "0";

int convert(int n, int target) {
    stack<string> s;
    while (n != 0) {
        if (n % target >= 10) {
            string tmp1 = "";
            char tmp2 = 'A' + (n % target - 10);
            tmp1 += tmp2;
            s.push(tmp1);
        }
        else s.push(to_string(n % target));
        n /= target;
    }
    while (!s.empty()) {
        str += s.top();
        s.pop();
    }
    return str.size();
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int number = 1;
    while (convert(number, n) <= t * m) {
        number++;
    }
    cout << str << '\n';
    for (int i = 0; i < t; i++) {
        answer.push_back(str[i * m + (p - 1)]);
    }
    return answer;
}