#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int result = 0;
bool visited[102];
vector<vector<pair<int, int>>> graph;

void prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,0 });

    while (!pq.empty()) {
        int here = pq.top().second;
        int hereDist = pq.top().first;
        pq.pop();
        if (visited[here]) continue;
        visited[here] = true;
        result += hereDist;

        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i].second;
            int thereDist = graph[here][i].first;
            if (visited[there]) continue;
            pq.push({ thereDist,there });
        }
    }
}

int solution(int n, vector<vector<int>> costs) {
    graph.resize(n + 2);
    for (int i = 0; i < costs.size(); i++) {
        graph[costs[i][1]].push_back({ costs[i][2],costs[i][0] });
        graph[costs[i][0]].push_back({ costs[i][2],costs[i][1] });
    }
    prim();

    return result;
}