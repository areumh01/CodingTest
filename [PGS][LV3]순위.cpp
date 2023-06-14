#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[100002];

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int last = 0;

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());

    for (int i = 0; i < B.size(); i++) {
        for (int j = last; j < A.size(); j++) {
            if (B[i] > A[j]) {
                last = j + 1;
                answer++;
                break;
            }
        }
    }
    return answer;
}