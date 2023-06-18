#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>
#include <iostream>

using namespace std;

vector<unordered_set<int>> v(9);

void make(int N, int index) {
    string s = "";
    for (int i = 0; i < index; i++) {
        s += to_string(N);
    }
    v[index].insert(stoi(s));
}

int solution(int N, int number) {
    for (int index = 1; index < 9; index++) {
        make(N, index);
        for (auto a : v[index]) if (a == number) return index;
        for (int i = 1; i <= index / 2; i++) {
            for (auto a : v[i]) {
                for (auto b : v[index - i]) {
                    v[index].insert(a + b);
                    v[index].insert(a * b);
                    if (a != 0)
                        v[index].insert(b / a);
                    v[index].insert(abs(b - a));
                    if (a + b == number) return index;
                    if (a * b == number) return index;
                    if (a != 0)
                        if (b / a == number) return index;
                    if (abs(b - a) == number) return index;
                }
            }
        }
    }
    return -1;
}