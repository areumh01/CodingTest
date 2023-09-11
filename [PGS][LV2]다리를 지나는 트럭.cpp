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
        //마지막 차가 올라가고 그 차빠질때까지 기다리는거면
        if (index == truck_weights.size()) {
            //q.pop();
            //continue;
            //마지막 차가 올라간 직후니까
            answer += bridge_length;
            break;
        }
        //큐 사이즈가 length와 동일하면 pop하기
        if (q.size() == bridge_length) {
            if (q.front() != -1) bridge_weight -= q.front();
            q.pop();
        }
        //그러면 일단 항상 자리가 존재
        //올릴 수 있다면 다리에 올리기
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