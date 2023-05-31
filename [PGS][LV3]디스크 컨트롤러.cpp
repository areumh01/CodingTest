#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> job) {
    vector<pair<int, int>> jobs;
    for (int i = 0; i < job.size(); i++) {
        jobs.push_back({ job[i][0],job[i][1] });
    }
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //시간의 흐름 저장
    int time = 0;
    //누적 시간 저장
    int answer = 0;
    int index = 0;

    while (index != jobs.size() || !pq.empty()) {
        if (pq.empty()) {
            time = jobs[index].first;
            time += jobs[index].second;
            answer += (time - jobs[index].first);
            index++;
        }
        else {
            time += pq.top().first;
            answer += (time - pq.top().second);
            pq.pop();
        }

        int tmp = index;
        for (int i = tmp; i < jobs.size(); i++) {
            if (jobs[i].first < time) {
                pq.push({ jobs[i].second,jobs[i].first });
                index++;
            }
        }
    }
    return answer / jobs.size();
}