#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int boat = 0;

    int left = 0;
    int right = people.size() - 1;
    sort(people.begin(), people.end());
    while (left <= right) {
        if (people[left] + people[right] > limit) {
            right--;
            boat++;
        }
        else {
            left++;
            right--;
            boat++;
        }
        if (right == left) {
            boat++;
            break;
        }
    }

    return boat;
}