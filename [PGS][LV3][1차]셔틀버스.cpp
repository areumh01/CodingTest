#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

vector<string> buses;

//시간 -> 문자열
string convertHM(int time) {
    string hour = "", minutes = "", bus = "";
    if (time / 60 < 10) {
        hour += '0';
        hour += to_string(time / 60);
    }
    else hour += to_string(time / 60);
    if (time % 60 < 10) {
        if (time % 60 == 0) {
            minutes += "00";
        }
        else {
            minutes += '0';
            minutes += to_string(time % 60);
        }
    }
    else minutes += to_string(time % 60);
    bus = hour + ":" + minutes;

    return bus;
}

//운행하는 버스 스케줄 저장
void bus_schedule(int n, int t) {
    string hour = "", minutes = "", bus = "";
    int time = 9 * 60;
    for (int i = 0; i < n; i++) {
        buses.push_back(convertHM(time));
        time += t;
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<string, vector<string>, greater<string>> pq;//최소힙
    stack<string> last_bus;

    //크루들 정보 최소힙에 저장
    for (int i = 0; i < timetable.size(); i++) {
        pq.push(timetable[i]);
    }
    //버스 스케줄 저장
    bus_schedule(n, t);

    //버스마다 크루들을 태움
    for (int i = 1; i <= n; i++) {
        stack<string> s;
        //i번째 버스 시간 가져와서
        string this_bus = buses[i - 1];
        //버스 태우기
        for (int j = 0; j < m; j++) {
            //기다리는 사람이 없으면 무시
            if (pq.empty()) continue;
            //버스시간보다 일찍이거나 똑같게 온 사람들 태우기
            if (pq.top() <= this_bus) {
                s.push(pq.top());
                pq.pop();
            }
        }
        //마지막 버스면 탑승객정보 넘기기
        if (i == n) last_bus = s;
    }
    //마지막 버스 정원보다 적게 탔으면 버스시간에 맞게 도착해서 태우기
    if (last_bus.size() < m) answer = buses.back();
    //마지막 버스에 못탔으면 마지막 탑승객보다 1분 일찍 도착하기
    else {
        string lastcrewh = last_bus.top().substr(0, 2);
        string lastcrewm = last_bus.top().substr(3, 2);
        int calc = stoi(lastcrewh) * 60 + stoi(lastcrewm);
        calc -= 1;
        answer = convertHM(calc);
    }
    return answer;
}