#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

vector<string> buses;

//�ð� -> ���ڿ�
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

//�����ϴ� ���� ������ ����
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
    priority_queue<string, vector<string>, greater<string>> pq;//�ּ���
    stack<string> last_bus;

    //ũ��� ���� �ּ����� ����
    for (int i = 0; i < timetable.size(); i++) {
        pq.push(timetable[i]);
    }
    //���� ������ ����
    bus_schedule(n, t);

    //�������� ũ����� �¿�
    for (int i = 1; i <= n; i++) {
        stack<string> s;
        //i��° ���� �ð� �����ͼ�
        string this_bus = buses[i - 1];
        //���� �¿��
        for (int j = 0; j < m; j++) {
            //��ٸ��� ����� ������ ����
            if (pq.empty()) continue;
            //�����ð����� �����̰ų� �Ȱ��� �� ����� �¿��
            if (pq.top() <= this_bus) {
                s.push(pq.top());
                pq.pop();
            }
        }
        //������ ������ ž�°����� �ѱ��
        if (i == n) last_bus = s;
    }
    //������ ���� �������� ���� ������ �����ð��� �°� �����ؼ� �¿��
    if (last_bus.size() < m) answer = buses.back();
    //������ ������ �������� ������ ž�°����� 1�� ���� �����ϱ�
    else {
        string lastcrewh = last_bus.top().substr(0, 2);
        string lastcrewm = last_bus.top().substr(3, 2);
        int calc = stoi(lastcrewh) * 60 + stoi(lastcrewm);
        calc -= 1;
        answer = convertHM(calc);
    }
    return answer;
}