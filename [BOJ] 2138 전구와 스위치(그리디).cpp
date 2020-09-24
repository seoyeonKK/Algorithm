#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
void change(vector<int> &v, int index) {
    for (int i = index-1; i <= index+1; i++) {
        if (0 <= i && i < v.size()) {
            v[i] = 1 - v[i];
        }
    }
}

pair<bool, int> go(vector<int> s, vector<int> &g) {
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] != g[i]) {
            change(s, i+1);
            ans += 1;
        }
    }
    if (s == g) {
        return {true, ans};
    }
    else {
        return {false, ans};
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n);
    vector<int> goal(n);
    for (int i = 0; i < n; i++) {
        scanf("%1d", &start[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%1d", &goal[i]);
    }
    
    // '0번 눌렀을 때'와 '0번을 누르지 않았을 때' 2가지의 경우를 따져서 분석 
    auto p1 = go(start, goal); // 0번 누르지 않음
    change(start, 0); // 0번 눌렀다는 가정
    auto p2 = go(start, goal); // 0번 누름

    if (p2.first) {
        p2.second += 1; // 0번째 눌렀을 때, 0번쨰 누른 횟수 더하기
    }
    if (p1.first && p2.first) {
        cout << min(p1.second, p2.second) << endl;
    }
    else if (p1.first){
        cout << p1.second << endl;
    }
    else if (p2.first) {
        cout << p2.second << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
