#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int check[1000002];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    memset(check, 0, sizeof(check));
    stack<int> deleted;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            int X = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            int counting = 0;
            while (counting != X) {
                if (check[--k] == 0) counting++;
            }
        }
        else if (cmd[i][0] == 'D') {
            int X = stoi(cmd[i].substr(2, cmd[i].size() - 2));
            int counting = 0;
            while (counting != X) {
                if (check[++k] == 0) counting++;
            }
        }
        else if (cmd[i][0] == 'C') {
            check[k] = -1;
            deleted.push(k);
            bool flag = false;
            int tmp = k;
            while (tmp + 1 < n) {
                tmp++;
                if (check[tmp] == 0) {
                    k = tmp;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                tmp = k;
                while (tmp > 0) {
                    tmp--;
                    if (check[tmp] == 0) {
                        k = tmp;
                        break;
                    }
                }
            }
        }
        else if (cmd[i][0] == 'Z') {
            check[deleted.top()] = 0;
            deleted.pop();
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) answer += 'O';
        else answer += 'X';
    }
    return answer;
}