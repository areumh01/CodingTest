#include <string>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int numbers[3] = { 4,1,2 };
    int r = n % 3;
    int q = r == 0 ? n / 3 - 1 : n / 3;
    answer += to_string(numbers[r]);
    while (q != 0) {
        answer += to_string(numbers[q % 3]);
        q = (q % 3 == 0) ? q / 3 - 1 : q / 3;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}