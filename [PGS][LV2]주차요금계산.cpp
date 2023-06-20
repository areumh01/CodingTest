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

//���� ��� ���
int calc(int totalTime) {
    int sum = 0;
    if (totalTime <= fees_copy[0]) sum = fees_copy[1];
    else {
        totalTime -= fees_copy[0];
        sum = (fees_copy[1] + ceil(totalTime / (double)fees_copy[2]) * fees_copy[3]);
    }
    return sum;
}

//���� �ð� ���
int getMinutes(string outTime, string inTime) {
    return (stoi(outTime.substr(0, 2)) * 60 - stoi(inTime.substr(0, 2)) * 60 + stoi(outTime.substr(3, 2)) - stoi(inTime.substr(3, 2)));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<pair<string, int>> answer_beforeSort;
    vector<int> answer;
    fees_copy = fees;
    //������ȣ - ���� �ð�
    map<string, string> intime;
    //�����Ǿ��ִ� ������ȣ
    set<string> cars;
    //���ڵ��� ���ڿ��� ������ ����
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
            //����
            intime[carNumber] = currentTime;
            cars.insert(carNumber);
        }
        else {
            //����
            time_sum[carNumber] += getMinutes(currentTime, intime[carNumber]);
            cars.erase(carNumber);
        }
    }
    if (cars.size() > 0) {
        //���� �����ִ� ���� ����
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