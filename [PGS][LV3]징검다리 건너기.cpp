#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int start = 1;
    int end = 200000000;
    int mid = (start + end) / 2;

    //ÀÌºĞÅ½»ö
    while (start <= end) {
        mid = (start + end) / 2;
        int counting = 0;
        int maxi = 0;
        int last = -1;
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] <= mid && last == -1) {
                counting++;
                last = i;
            }
            else if (stones[i] <= mid && last != -1) {
                if (i == last + 1) {
                    counting++;
                    last = i;
                }
                else {
                    maxi = max(maxi, counting);
                    counting = 1;
                    last = i;
                }
            }
        }
        maxi = max(maxi, counting);
        if (maxi < k) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return start;
}