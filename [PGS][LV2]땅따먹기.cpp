#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> land_copy;
int answer = 0;
int memo[100000][4];

int find_answer(int row, int index) {
    int maxx = 0;
    if (row == 0) {
        return memo[row][index] = land_copy[row][index];
    }
    if (memo[row][index] != 0) return memo[row][index];
    for (int i = 0; i < 4; i++) {
        if (i != index)
            maxx = max(maxx, find_answer(row - 1, i));
    }
    return memo[row][index] = maxx + land_copy[row][index];
}

int solution(vector<vector<int>> land)
{
    land_copy = land;
    for (int i = 0; i < 4; i++) {
        answer = max(answer, find_answer(land.size() - 1, i));
    }
    return answer;
}