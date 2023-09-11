#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int index = 0;
    int bridge_weight = 0;
    queue<int> q;
    //for(int i=0; i<bridge_length; i++) q.push(-1);

    while (true) {
        //������ ���� �ö󰡰� �� ������������ ��ٸ��°Ÿ�
        if (index == truck_weights.size()) {
            //q.pop();
            //continue;
            //������ ���� �ö� ���Ĵϱ�
            answer += bridge_length;
            break;
        }
        //ť ����� length�� �����ϸ� pop�ϱ�
        if (q.size() == bridge_length) {
            if (q.front() != -1) bridge_weight -= q.front();
            q.pop();
        }
        //�׷��� �ϴ� �׻� �ڸ��� ����
        //�ø� �� �ִٸ� �ٸ��� �ø���
        if (bridge_weight + truck_weights[index] <= weight) {
            q.push(truck_weights[index]);
            bridge_weight += truck_weights[index];
            index++;
        }
        else
            q.push(-1);

        answer++;
    }
    return answer;
}