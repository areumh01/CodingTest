#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(int a, int b) {
    string atmp = to_string(a), btmp = to_string(b);
    string concab = "", concba = "";

    concab += atmp + btmp;
    concba += btmp + atmp;

    if (concab <= concba) return false;
    else return true;
}

string solution(vector<int> numbers) {
    string answer = "";
    int check = 0;
    sort(numbers.begin(), numbers.end(), comp);
    for (int i = 0; i < numbers.size(); i++) {
        answer += to_string(numbers[i]);
    }
    if (answer[0] == '0') return "0";
    else return answer;
}