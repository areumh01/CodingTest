#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int remain;
    while (true) {
        remain = b % a;
        b = a;
        a = remain;
        if (a == 0) return b;
    }
}

int lcm(int a, int b) {
    return a * b / gcd(min(a, b), max(a, b));
}

int solution(vector<int> arr) {
    int answer = 1;
    for (auto e : arr) {
        answer = lcm(answer, e);
    }
    return answer;
}