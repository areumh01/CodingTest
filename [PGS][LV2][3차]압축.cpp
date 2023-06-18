#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> m;
int last = 0;
vector<int> answer;

//������ ���� �ܾ� ����
void new_word(string s) {
    m[s] = last + 1;
    last++;
}

//������ ���� ��ȣ�� ���
void save_answer(string s) {
    s.pop_back();
    answer.push_back(m[s]);
}

vector<int> solution(string msg) {
    int index = 0;

    //���̰� 1�� ��� �ܾ �����ϵ��� ������ �ʱ�ȭ�Ѵ�.
    while (last < 26) {
        string alpha = "";
        alpha += 'A' + last;
        m[alpha] = last + 1;
        last++;
    }

    while (index != msg.size()) {
        string sub = "";
        sub += msg[index];
        //������ ���� ���ڿ��� ��Ÿ�� ������ ���� ���δ�
        while (m[sub] != 0) {
            sub += msg[++index];
        }
        //������ ���� ���ڿ� �߰�
        new_word(sub);
        //���� ��ȣ ���
        save_answer(sub);
    }
    return answer;
}