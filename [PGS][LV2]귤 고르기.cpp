#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int start = 1;
    int end = 10000000;
    vector<int> tan;
    tan.resize(10000002);

    for (int i = 0; i < tangerine.size(); i++) {
        tan[tangerine[i]]++;
    }
    sort(tan.begin(), tan.end(), greater<>());

    while (start <= end) {
        int counting = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < tan.size(); i++) {
            if (mid <= tan[i]) {
                counting += tan[i];
            }
        }
        if (counting < k) end = mid - 1;
        else start = mid + 1;
    }

    int sub = 0;
    for (int i = 0; i < tan.size(); i++) {
        if (tan[i] >= end) {
            sub += tan[i];
            answer++;
        }
        if (sub >= k) break;
    }

    return answer;
}