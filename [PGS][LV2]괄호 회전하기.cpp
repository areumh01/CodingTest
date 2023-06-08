#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int counting = 0;

bool check(queue<char> q) {
    counting = 0;
    stack<char> ori;
    stack<char> close;
    while (!q.empty()) {
        ori.push(q.front());
        q.pop();
    }
    while (!ori.empty()) {
        if (ori.top() == '}' || ori.top() == ']' || ori.top() == ')') {
            close.push(ori.top());
            ori.pop();
        }
        else if (ori.top() == '{' && !close.empty() && close.top() == '}') {
            close.pop();
            ori.pop();
        }
        else if (ori.top() == '[' && !close.empty() && close.top() == ']') {
            close.pop();
            ori.pop();
        }
        else if (ori.top() == '(' && !close.empty() && close.top() == ')') {
            close.pop();
            ori.pop();
        }
        else {
            return false;
        }
        if (close.empty()) counting++;
    }
    if (close.empty()) return true;
    else return false;
}

int solution(string s) {
    queue<char> q;
    queue<char> comp;

    for (int i = 0; i < s.size(); i++) {
        q.push(s[i]);
    }
    comp = q;

    while (!check(q)) {
        q.push(q.front());
        q.pop();
        if (q == comp) break;
    }
    return counting;
}