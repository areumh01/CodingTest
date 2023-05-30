#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[50002];

int solution(vector<int> people, int limit) {
    int boat = 0;
    sort(people.begin(), people.end());
    for (int i = people.size() - 1; i >= 0; i--) {
        bool flag = false;
        if (visited[i] == true) continue;
        if ((limit - people[i]) < 40) {
            boat++;
            visited[i] = true;
            //cout << people[i] << "Å¾½Â" << '\n';
            continue;
        }
        else {
            for (int j = 0; j < people.size(); j++) {
                if (visited[j] == true) continue;
                if (people[j] <= (limit - people[i])) {
                    visited[j] = true;
                    boat++;
                    //cout << people[i] << "¶û °°ÀÌ Å¾½ÂÇÑ" << people[j] << '\n';
                    flag = true;
                    break;
                }
            }
            if (flag == false) boat++;
        }
    }
    return boat;
}