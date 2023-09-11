#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 1e8;

int solution(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push({ y,0 });
    while (!q.empty()) {
        int current = q.front().first;
        int counting = q.front().second;
        q.pop();
        if (current == x) {
            answer = counting;
            break;
        }
        if (current % 2 == 0) q.push({ current / 2,counting + 1 });
        if (current % 3 == 0) q.push({ current / 3,counting + 1 });
        if (current >= n) q.push({ current - n,counting + 1 });
    }
    if (answer == 1e8) return -1;
    return answer;
}