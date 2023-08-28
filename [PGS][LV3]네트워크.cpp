#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<vector<int>> graph(n);
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (computers[i][j] == 1)
                graph[i].push_back(j);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                for (int j = 0; j < graph[current].size(); j++) {
                    if (!visited[graph[current][j]]) {
                        visited[graph[current][j]] = true;
                        q.push(graph[current][j]);
                    }
                }
            }
        }
    }
    return answer;
}