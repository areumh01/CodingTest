#include <string>
#include <vector>

using namespace std;

//N�� ������ �������� ���� �� �ִ� ���ڵ��� �����ϴ� vector
vector<vector<int>> v(9);

int solution(int N, int number) {
    int answer = 0;
    for (int i = 1; i < 9; i++) {
        int n = 0;
        for (int j = 0; j < i; j++) {
            n *= 10;
            n += N;
        }
        if (n == number) return i;
        v[i].push_back(n);
        for (int j = 1; j <= i / 2; j++) {
            for (auto e : v[j]) {
                for (auto el : v[i - j]) {
                    if (e + el == number || e * el == number || ((e != 0) && (el / e == number)) || abs(el - e) == number) return i;
                    v[i].push_back(e + el);
                    v[i].push_back(e * el);
                    v[i].push_back(abs(el - e));
                    if (e != 0)
                        v[i].push_back(el / e);
                }
            }
        }
    }
    return -1;
}