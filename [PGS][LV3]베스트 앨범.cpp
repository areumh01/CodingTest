#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<pair<int, string>> gen;
    map<string, int> tmp;
    map<string, vector<pair<int, int>>> m;
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++) {
        tmp[genres[i]] += plays[i];
        m[genres[i]].push_back({ plays[i],i });
    }
    map<string, int>::iterator it;
    for (it = tmp.begin(); it != tmp.end(); it++) {
        gen.push_back({ it->second,it->first });
    }
    sort(gen.begin(), gen.end(), comp);

    for (auto e : gen) {
        string genre = e.second;
        vector<pair<int, int>> v = m[genre];
        sort(v.begin(), v.end(), compare);
        if (v.size() >= 2) {
            answer.push_back(v[0].second);
            answer.push_back(v[1].second);
        }
        else answer.push_back(v[0].second);
    }

    return answer;
}
}