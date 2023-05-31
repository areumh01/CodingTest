#include <iostream>
#include <math.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    if (min(a, b) % 2 == 1 && abs(b - a) == 1) return 1; //1,2 2,1�� ó���� ����ϴ� �ֵ��� �ݺ����ȿ� ���� ����
    while (true) {
        answer++;
        a = (a % 2) ? a / 2 + 1 : a / 2;
        b = (b % 2) ? b / 2 + 1 : b / 2;
        if (min(a, b) % 2 == 1 && abs(b - a) == 1) break;
    }
    return answer + 1;
}