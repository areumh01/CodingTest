#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> sum(triangle.size(), vector<int>(triangle.back().size(), 0));
    sum[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j > 0 && j < i)
                sum[i][j] = max(sum[i - 1][j] + triangle[i][j], sum[i - 1][j - 1] + triangle[i][j]);
            else if (j == 0)
                sum[i][j] = sum[i - 1][j] + triangle[i][j];
            else if (j == i)
                sum[i][j] = sum[i - 1][j - 1] + triangle[i][j];
        }
    }
    for (int i = 0; i < triangle.back().size(); i++) {
        answer = max(answer, sum[triangle.size() - 1][i]);
    }
    return answer;
}