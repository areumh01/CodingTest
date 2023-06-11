#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long start = 0;
    long long end = 1e18;
    long long mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        long long counting = 0;
        for (int i = 0; i < times.size(); i++) {
            counting += mid / times[i];
        }
        if (counting >= n) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}