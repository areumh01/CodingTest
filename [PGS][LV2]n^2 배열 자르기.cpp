#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for (long long i = left; i < right + 1; i++) {
        int x = i / n;
        int y = i % n;
        answer.push_back(max(x + 1, y + 1));
    }
    return answer;
}