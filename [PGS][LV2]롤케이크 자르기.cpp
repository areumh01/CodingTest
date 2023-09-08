#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> ob;
    map<int, int> yb;

    for (auto e : topping) ob[e]++;
    //if(ob.size()%2 != 0) return 0;

    for (auto e : topping) {
        yb[e]++;
        ob[e]--;
        if (ob[e] == 0) ob.erase(e);
        if (ob.size() == yb.size()) answer++;
    }
    return answer;
}