#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int m = a[0];
    vector<pair<int, int>> mins;
    mins.resize(a.size());

    //왼쪽 최솟값 정의
    for (int i = 1; i < a.size() - 1; i++) {
        if (m > a[i]) m = a[i];
        mins[i].first = m;
    }
    m = a.back();
    //오른쪽 최솟값 정의
    for (int i = a.size() - 2; i > 0; i--) {
        if (m > a[i]) m = a[i];
        mins[i].second = m;
    }

    for (int i = 1; i < a.size() - 1; i++) {
        if (mins[i].first < a[i] && mins[i].second < a[i]) continue;
        answer++;
    }
    return answer + 2;
}