#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int start = 0;
    int end = citations.back();
    int mid, index;

    while (start <= end) {
        mid = (start + end) / 2;
        //cout << "mid : " << mid << '\n';
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= mid) {
                index = i;
                break;
            }
        }
        if (citations.size() - index >= mid) {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return end;
}