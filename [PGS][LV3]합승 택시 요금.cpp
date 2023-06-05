#include <string>
#include <vector>

using namespace std;

int road[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e8;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            road[i][j] = 1e8;
            if (i == j) road[i][j] = 0;
        }
    }

    for (int i = 0; i < fares.size(); i++) {
        road[fares[i][0]][fares[i][1]] = fares[i][2];
        road[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    //플로이드-와샬
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                road[i][j] = min(road[i][j], road[i][k] + road[k][j]);
            }
        }
    }

    //s->i->a, i->b
    for (int i = 1; i <= n; i++) {
        answer = min(answer, road[s][i] + road[i][a] + road[i][b]);
    }

    return answer;
}