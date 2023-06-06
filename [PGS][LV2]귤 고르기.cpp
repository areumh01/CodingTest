#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int m = *max_element(tangerine.begin(), tangerine.end());
    vector<int> tan(m,0);

    for (int i = 0; i < tangerine.size(); i++) {
        tan[tangerine[i]-1]++;
    }
    sort(tan.begin(), tan.end(), greater<>());

    for (int i = 0; i < tan.size(); i++) {
        answer++;
        k -= tan[i];
        if (k <= 0) break;
    }

    return answer;
}