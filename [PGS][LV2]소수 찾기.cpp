#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

string s;
set<int> all;
bool visited[10];

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int index, int length, string tmp) {
    tmp += s[index];
    if (tmp.size() == length) {
        all.insert(stoi(tmp));
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (visited[i] == false) {
            visited[i] = true;
            dfs(i, length, tmp);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    s = numbers;
    int answer = 0;
    for (int i = 1; i <= numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            visited[j] = true;
            dfs(j, i, "");
            visited[j] = false;
        }
    }

    for (int a : all) {
        if (isPrime(a)) answer++;
    }
    return answer;
}