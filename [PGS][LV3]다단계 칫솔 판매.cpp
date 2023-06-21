#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    map<string, int> profit;
    map<string, string> relation;

    for (int i = 0; i < enroll.size(); i++) {
        string child = enroll[i];
        string parent = referral[i];
        relation[child] = parent;
    }

    for (int i = 0; i < seller.size(); i++) {
        int over = amount[i] * 100;
        string child = seller[i];
        string parent = "";
        while (child != "-") {
            parent = relation[child];
            if (over / 10 > 0) {
                profit[child] += (over - over / 10);
                over /= 10;
            }
            else {
                profit[child] += over;
                break;
            }
            child = parent;
        }
    }

    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(profit[enroll[i]]);
    }
    return answer;
}