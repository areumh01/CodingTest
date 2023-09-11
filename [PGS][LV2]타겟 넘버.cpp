#include <string>
#include <vector>

using namespace std;

int answer = 0;

void checkAll(int index, int sum, vector<int>& numbers, int target) {
    if (index == numbers.size()) {
        if (sum == target)
            answer++;
        return;
    }
    checkAll(index + 1, sum - numbers[index], numbers, target);
    checkAll(index + 1, sum + numbers[index], numbers, target);
}

int solution(vector<int> numbers, int target) {
    checkAll(0, 0, numbers, target);
    return answer;
}