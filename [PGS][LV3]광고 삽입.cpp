#include <string>
#include <vector>
#include <iostream>

using namespace std;

int playerNumber[360001] = { 0, };

int CalcToInt(string s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));

    return h * 3600 + m * 60 + ss;
}

string CalcToString(int n) {
    int h = n / 3600;
    int m = (n % 3600) / 60;
    int s = (n % 60);

    string HH = h < 10 ? "0" + to_string(h) : to_string(h);
    string MM = m < 10 ? "0" + to_string(m) : to_string(m);
    string SS = s < 10 ? "0" + to_string(s) : to_string(s);

    return HH + ":" + MM + ":" + SS;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTime = CalcToInt(play_time);
    int advTime = CalcToInt(adv_time);

    for (string s : logs) {
        int start = CalcToInt(s.substr(0, 8));
        int end = CalcToInt(s.substr(9, 8));
        playerNumber[start]++;
        playerNumber[end]--;
    }

    for (int i = 1; i <= playTime; i++) {
        playerNumber[i] += playerNumber[i - 1];
    }

    int start = 0;
    int end = advTime;
    long long sum = 0;
    int maxStart = 0;
    long long tmp;

    for (int i = start; i < end; i++) {
        sum += playerNumber[i];
    }
    tmp = sum;

    while (end <= playTime) {
        sum -= playerNumber[start++];
        sum += playerNumber[end++];
        if (tmp < sum) {
            maxStart = start;
            tmp = sum;
        }
    }
    return CalcToString(maxStart);
}