#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, vector<string>> m;
map<string, bool> visited;

//bfs로 target으로 가는 최소 거리 찾기
int bfs(string begin, string target) {
    queue<pair<string, int>> q;
    q.push({ begin,0 });
    while (!q.empty()) {

        string current = q.front().first;
        int counting = q.front().second;
        q.pop();
        //target을 처음 봤을 때가 가장 최단거리
        if (current == target) return counting;

        vector<string> v = m[current];
        for (int i = 0; i < v.size(); i++) {
            if (!visited[v[i]]) {
                visited[v[i]] = true;
                q.push({ v[i],counting + 1 });
            }
        }
    }
    //못찾으면 0 반환
    return 0;
}

//a를 기준으로 b가 알파벳 1개만 다를 때 맵에 넣어줌
void check_twoString(string a, string b) {
    int check = 0;
    for (int s = 0; s < a.size(); s++) {
        if (a[s] == b[s]) continue;
        check++;
        if (check > 1) break;
    }
    if (check <= 1) m[a].push_back(b);
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    //begin 기준으로 알파벳 하나만 다른 애들 모으고
    for (int j = 0; j < words.size(); j++) {
        check_twoString(begin, words[j]);
    }
    //words에 있는 애들도 각자 본인과 알파벳 하나만 다른 애들 모으기
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            check_twoString(words[i], words[j]);
        }
    }

    return bfs(begin, target);
}