#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, vector<string>> m;
map<string, bool> visited;

//bfs�� target���� ���� �ּ� �Ÿ� ã��
int bfs(string begin, string target) {
    queue<pair<string, int>> q;
    q.push({ begin,0 });
    while (!q.empty()) {

        string current = q.front().first;
        int counting = q.front().second;
        q.pop();
        //target�� ó�� ���� ���� ���� �ִܰŸ�
        if (current == target) return counting;

        vector<string> v = m[current];
        for (int i = 0; i < v.size(); i++) {
            if (!visited[v[i]]) {
                visited[v[i]] = true;
                q.push({ v[i],counting + 1 });
            }
        }
    }
    //��ã���� 0 ��ȯ
    return 0;
}

//a�� �������� b�� ���ĺ� 1���� �ٸ� �� �ʿ� �־���
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
    //begin �������� ���ĺ� �ϳ��� �ٸ� �ֵ� ������
    for (int j = 0; j < words.size(); j++) {
        check_twoString(begin, words[j]);
    }
    //words�� �ִ� �ֵ鵵 ���� ���ΰ� ���ĺ� �ϳ��� �ٸ� �ֵ� ������
    for (int i = 0; i < words.size(); i++) {
        for (int j = 0; j < words.size(); j++) {
            if (i == j) continue;
            check_twoString(words[i], words[j]);
        }
    }

    return bfs(begin, target);
}