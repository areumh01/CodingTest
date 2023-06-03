#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<int> visited;

void dfs(vector<vector<string>>& tickets, string start, int count) {
    if (count == tickets.size() + 1) {
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (tickets[i][0] == start && visited[i] == 0) {
            cout << tickets[i][0] << " ";
            visited[i] = 1;
            answer.push_back(tickets[i][1]);
            dfs(tickets, tickets[i][1], count + 1);
            if (answer.size() == tickets.size() + 1) return;
            visited[i] = 0;
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    visited.resize(tickets.size() + 2);
    answer.push_back("ICN");
    dfs(tickets, "ICN", 0);
    return answer;
}