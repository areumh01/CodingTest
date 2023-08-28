#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int>> s;
    for (int i = 0; i < prices.size(); i++) {
        if (!s.empty() && s.top().first > prices[i]) {
            while (!s.empty() && s.top().first > prices[i]) {
                int index = s.top().second;
                s.pop();
                answer[index] = i - index;
            }
        }
        s.push({ prices[i],i });
    }
    while (!s.empty()) {
        int index = s.top().second;
        s.pop();
        answer[index] = prices.size() - 1 - index;
    }
    return answer;
}