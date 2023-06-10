#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    set<int> s;
    for (int i = 0; i < elements.size(); i++) {
        for (int j = 1; j <= elements.size(); j++) {
            int sum = 0;
            for (int k = 0; k < j; k++) {
                if (i + k < elements.size())
                    sum += elements[i + k];
                else
                    sum += elements[(i + k) - elements.size()];
            }
            s.insert(sum);
        }
    }
    return s.size();
}