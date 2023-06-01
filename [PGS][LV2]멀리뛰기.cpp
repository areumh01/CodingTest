#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long run[2002];

long long find_answer(int n) {
    if (n == 1) return run[1] = 1;
    if (n == 2) return run[2] = 2;
    if (run[n] != 0) return run[n];
    else {
        return run[n] = find_answer(n - 1) % 1234567 + find_answer(n - 2) % 1234567;
    }
}

long long solution(int n) {
    long long answer = find_answer(n) % 1234567;
    return answer;
}