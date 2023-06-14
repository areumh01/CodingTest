#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = -1;
vector<vector<int>> d;
bool visited[10];

void dfs(int index, int hp, int counting) {
    if (hp < d[index][0]) {
        answer = max(answer, counting);
        return;
    }
    if (hp >= d[index][0]) { //남아있는 체력 > 필요한 체력
        visited[index] = true;
        if (counting == d.size() - 1) {
            answer = max(answer, counting + 1);
            return;
        }
        for (int i = 0; i < d.size(); i++) {
            if (!visited[i]) {
                dfs(i, hp - d[index][1], counting + 1);
            }
        }
        //visited[index] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    d = dungeons;
    for (int i = 0; i < dungeons.size(); i++) {
        dfs(i, k, 0);
    }
    return answer;
}