#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct pyo {
    bool del;
    int left;
    int right;
    pyo(int n) {
        left = n - 1;
        right = n + 1;
        del = 0;
    };
};

vector<pyo*> pyoVec;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<int> deleted;
    for (int i = 0; i < n; i++) {
        pyo* tmp = new pyo(i);
        pyoVec.push_back(tmp);
    }
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            int X = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            for (int i = 0; i < X; i++) {
                k = pyoVec[k]->left;
            }
        }
        else if (cmd[i][0] == 'D') {
            int X = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            for (int i = 0; i < X; i++) {
                k = pyoVec[k]->right;
            }
        }
        else if (cmd[i][0] == 'C') {
            pyoVec[k]->del = 1;
            deleted.push(k);
            if (pyoVec[k]->right < n)//맨 끝 인덱스를 삭제한 경우가 아니면
                pyoVec[pyoVec[k]->right]->left = pyoVec[k]->left;
            if (pyoVec[k]->left >= 0)//맨 앞 인덱스를 삭제한 경우가 아니면
                pyoVec[pyoVec[k]->left]->right = pyoVec[k]->right;
            //맨 끝 인덱스를 삭제했다면
            if (pyoVec[k]->right >= n) k = pyoVec[k]->left;
            else k = pyoVec[k]->right;
        }
        else if (cmd[i][0] == 'Z') {
            int current = deleted.top();
            deleted.pop();
            int l = current;
            int r = current;
            while (l > 0) if (pyoVec[--l]->del == 0) break;
            while (r < n - 1) if (pyoVec[++r]->del == 0) break;
            pyoVec[current]->del = 0;
            pyoVec[current]->left = l;
            pyoVec[current]->right = r;
            pyoVec[l]->right = current;
            pyoVec[r]->left = current;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pyoVec[i]->del == 0) answer += 'O';
        else answer += 'X';
    }
    return answer;
}