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
        
        //삭제 복구를 잘못생각했음 어차피 가장 최근 삭제라 복구하는 인덱스의 구조체는 값을 변경할 필요도 없이 해당 left,right가 살아있기 때문에
        //유지하고 그 left,right의 구조체의 right,left값만 바꾸면 된다.
        else if (cmd[i][0] == 'Z') {
            int current = deleted.top();
            deleted.pop();
            int l = pyoVec[current]->left;
            int r = pyoVec[current]->right;
            pyoVec[current]->del = 0;
            //맨 앞 맨 뒤 확인 필수 이거때문에 틀렸던거~
            if (l >= 0)
                pyoVec[l]->right = current;
            if (r < n)
                pyoVec[r]->left = current;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pyoVec[i]->del == 0) answer += 'O';
        else answer += 'X';
    }
    return answer;
}