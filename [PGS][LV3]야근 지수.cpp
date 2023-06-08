#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    long long answer = 0;
    for (int i = 0; i < works.size(); i++) {
        pq.push(works[i]);
    }
    while (n > 0) {
        if (pq.empty()) break;
        int tmp = pq.top();
        pq.pop();
        if (tmp >= 1)
            pq.push(tmp - 1);
        n--;
    }
    while (!pq.empty()) {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    return answer;
}