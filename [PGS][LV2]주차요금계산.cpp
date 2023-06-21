#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

map<string, int> time_sum;
vector<int> fees_copy;

//주차 요금 계산
int calc(int totalTime) {
    int sum = 0;
    if (totalTime <= fees_copy[0]) sum = fees_copy[1];
    else {
        totalTime -= fees_copy[0];
        sum = (fees_copy[1] + ceil(totalTime / (double)fees_copy[2]) * fees_copy[3]);
    }
    return sum;
}

//주차 시간 계산
int getMinutes(string outTime, string inTime) {
    return (stoi(outTime.substr(0, 2)) * 60 - stoi(inTime.substr(0, 2)) * 60 + stoi(outTime.substr(3, 2)) - stoi(inTime.substr(3, 2)));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<pair<string, int>> answer_beforeSort;
    vector<int> answer;
    fees_copy = fees;
    //차량번호 - 들어온 시간
    map<string, string> intime;
    //주차되어있는 차량번호
    set<string> cars;
    //레코드의 문자열을 나눠서 저장
    vector<vector<string>> records_split;
    records_split.resize(records.size());

    for (int i = 0; i < records.size(); i++) {
        stringstream ss;
        string tmp;
        ss.str(records[i]);
        while (getline(ss, tmp, ' ')) {
            records_split[i].push_back(tmp);
        }
    }

    for (int i = 0; i < records_split.size(); i++) {
        string currentTime = records_split[i][0];
        string carNumber = records_split[i][1];

        if (cars.find(carNumber) == cars.end()) {
            //입차
            intime[carNumber] = currentTime;
            cars.insert(carNumber);
        }
        else {
            //출차
            time_sum[carNumber] += getMinutes(currentTime, intime[carNumber]);
            cars.erase(carNumber);
        }
    }
    if (cars.size() > 0) {
        //아직 남아있는 차가 있음
        for (auto carNumber : cars) {
            time_sum[carNumber] += getMinutes("23:59", intime[carNumber]);
            cars.erase(carNumber);
        }
    }

    for (auto e : time_sum) {
        int money = calc(e.second);
        answer_beforeSort.push_back({ e.first, money });
    }
    sort(answer_beforeSort.begin(), answer_beforeSort.end());

    for (int i = 0; i < answer_beforeSort.size(); i++) {
        answer.push_back(answer_beforeSort[i].second);
    }
    return answer;
}