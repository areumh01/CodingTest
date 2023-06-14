#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    string s1 = "", s2 = "";
    vector<string> a;
    vector<string> b;
    double similarity;
    int answer = 0;

    //두글자씩 벡터에 저장
    for (int i = 0; i < str1.size() - 1; i++) {
        string tmp = "";
        if (str1[i] - 'a' >= 0 && str1[i] - 'a' <= 26) {
            tmp += (str1[i] - 'a' + 'A');
        }
        else if (str1[i] - 'A' >= 0 && str1[i] - 'A' <= 26) {
            tmp += (str1[i]);
        }
        else continue;
        if (str1[i + 1] - 'a' >= 0 && str1[i + 1] - 'a' <= 26) {
            tmp += (str1[i + 1] - 'a' + 'A');
        }
        else if (str1[i + 1] - 'A' >= 0 && str1[i + 1] - 'A' <= 26) {
            tmp += (str1[i + 1]);
        }
        else continue;
        a.push_back(tmp);
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        string tmp = "";
        if (str2[i] - 'a' >= 0 && str2[i] - 'a' <= 26) {
            tmp += (str2[i] - 'a' + 'A');
        }
        else if (str2[i] - 'A' >= 0 && str2[i] - 'A' <= 26) {
            tmp += (str2[i]);
        }
        else continue;
        if (str2[i + 1] - 'a' >= 0 && str2[i + 1] - 'a' <= 26) {
            tmp += (str2[i + 1] - 'a' + 'A');
        }
        else if (str2[i + 1] - 'A' >= 0 && str2[i + 1] - 'A' <= 26) {
            tmp += (str2[i + 1]);
        }
        else continue;
        b.push_back(tmp);
    }

    //sorting
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }cout << '\n';
    for (int i = 0; i < b.size(); i++) {
        cout << b[i] << " ";
    }cout << '\n';

    //비교하기
    int same = 0, all = 0;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            same++;
            i++;
            j++;
        }
        else {
            if (a[i][0] < b[j][0]) {
                i++;
            }
            else if (a[i][0] > b[j][0]) {
                j++;
            }
            else {
                if (a[i][1] < b[j][1]) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }
    }
    all = a.size() + b.size() - same;
    similarity = same / (double)all;
    if (a.size() == 0 && b.size() == 0) similarity = 1;
    answer = (int)(similarity * 65536);
    return answer;
}