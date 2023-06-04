#include <iostream>
#include <queue>

using namespace std;

int target;

int find_min(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 0) return find_min(n / 2);
    else return find_min(n - 1) + 1;
}

int solution(int n)
{
    return find_min(n);
}