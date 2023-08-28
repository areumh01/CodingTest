#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    set<pair<int, int>> s;
    vector<vector<int>> answer(n + 2, vector<int>(m + 2, 0));

    for (auto e : puddles) s.insert({ e[1],e[0] });

    answer[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            if (s.find({ i,j }) == s.end())
                answer[i][j] = answer[i - 1][j] % 1000000007 + answer[i][j - 1] % 1000000007;
        }
    }
    return answer[n][m] % 1000000007;
}