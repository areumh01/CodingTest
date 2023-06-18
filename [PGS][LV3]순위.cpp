#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    bool check[102][102];
    int comp[102];

    memset(check, false, sizeof(check));
    for (int i = 0; i < results.size(); i++) {
        check[results[i][0]][results[i][1]] = true;
    }
    for (int i = 1; i <= n; i++) {
        check[i][i] = true;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (!check[i][k]) continue;
            for (int j = 1; j <= n; j++) {
                if (check[k][j])
                    check[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (check[i][j] || check[j][i]) comp[i]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (comp[i] == n) answer++;
    }

    return answer;
}