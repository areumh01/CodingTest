#include <iostream>
#include <string>

using namespace std;

int answer = 0;
string scopy;

bool palindrome(int start, int end) {
    while (start <= end) {
        if (scopy[start] == scopy[end]) {
            start++;
            end--;
        }
        else
            return false;
    }
    return true;
}

int solution(string s)
{
    scopy = s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = s.size() - 1; j > i; j--) {
            if (s[i] == s[j]) {
                if (palindrome(i, j)) {
                    answer = max(answer, j - i + 1);
                    break;
                }
            }
        }
    }
    if (answer == 0) answer = 1;
    return answer;
}