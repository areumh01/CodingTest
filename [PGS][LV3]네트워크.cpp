#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class disj {
private:
    map<int, pair<int, int>> m;

public:
    disj(int n) {
        for (int i = 0; i < n; i++) {
            m[i + 1].first = i + 1;
            m[i + 1].second = 0;
        }
    }
    int find(int n) {
        if (m[n].first == n)
            return n;
        else {
            return find(m[n].first);
        }
    }
    void Union(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if (roota == rootb) {
            return;
        }
        else {
            if (m[roota].second > m[rootb].second) m[rootb].first = roota;
            else if (m[roota].second < m[rootb].second) m[roota].first = rootb;
            else if (m[roota].second == m[rootb].second) {
                m[rootb].first = roota;
                m[roota].second++;
            }
        }
    }
};

int solution(int n, vector<vector<int>> computers) {
    disj dis(n);
    int visited[202] = { 0, };
    int answer = 0;
    for (int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            if (j != i && computers[i][j] == 1) {
                dis.Union(i + 1, j + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[dis.find(i + 1)] == 0) {
            visited[dis.find(i + 1)] = 1;
            answer++;
        }
    }
    return answer;
}