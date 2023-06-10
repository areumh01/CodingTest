#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), -1);
    stack<pair<int, int>> s;
    s.push({ prices[0],0 });
    int index = 1;

    while (!s.empty() && index != prices.size()) {
        if (prices[index] >= s.top().first) {
            s.push({ prices[index],index });
        }
        else {
            while (!s.empty() && s.top().first > prices[index]) {
                answer[s.top().second] = index - s.top().second;
                s.pop();
            }
            s.push({ prices[index],index });
        }
        index++;
    }

    for (int i = 0; i < prices.size(); i++) {
        if (answer[i] == -1) {
            if (s.empty()) answer[i] = prices.size() - i;
            else answer[i] = s.top().second - i;
        }
    }

    return answer;
}