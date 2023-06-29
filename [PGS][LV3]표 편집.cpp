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
            if (pyoVec[k]->right < n)//�� �� �ε����� ������ ��찡 �ƴϸ�
                pyoVec[pyoVec[k]->right]->left = pyoVec[k]->left;
            if (pyoVec[k]->left >= 0)//�� �� �ε����� ������ ��찡 �ƴϸ�
                pyoVec[pyoVec[k]->left]->right = pyoVec[k]->right;
            //�� �� �ε����� �����ߴٸ�
            if (pyoVec[k]->right >= n) k = pyoVec[k]->left;
            else k = pyoVec[k]->right;
        }
        
        //���� ������ �߸��������� ������ ���� �ֱ� ������ �����ϴ� �ε����� ����ü�� ���� ������ �ʿ䵵 ���� �ش� left,right�� ����ֱ� ������
        //�����ϰ� �� left,right�� ����ü�� right,left���� �ٲٸ� �ȴ�.
        else if (cmd[i][0] == 'Z') {
            int current = deleted.top();
            deleted.pop();
            int l = pyoVec[current]->left;
            int r = pyoVec[current]->right;
            pyoVec[current]->del = 0;
            //�� �� �� �� Ȯ�� �ʼ� �̰Ŷ����� Ʋ�ȴ���~
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