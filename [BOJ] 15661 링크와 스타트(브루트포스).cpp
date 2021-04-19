#include <iostream>
#include <vector>
using namespace std;

int n;
int s[20][20];

// idx번째 사람을 어떤 팀에 넣을지 결정하는 함수
int go(int idx, vector<int> &first, vector<int> &second) {
    // 마지막 사람인 경우 탈출
    if (idx == n) {
        // 모두 한 팀에 들어간 경우 제외
        if (first.size() == 0) return -1;
        if (second.size() == 0) return -1;

        // t1, t2 팅믜 에너지 계산
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < first.size(); i++) {
            for (int j = 0; j < first.size(); j++) {
                if (i == j) continue;
                t1 += s[first[i]][first[j]];
            }
        }
        for (int i = 0; i < second.size(); i++) {
            for (int j = 0; j < second.size(); j++) {
                if (i == j) continue;
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = t1-t2;
        if (diff < 0) diff = -diff;
        return diff;
    }

    int ans = -1;

    first.push_back(idx);
    int t1 = go(idx+1, first, second);
    if (ans == -1 || (t1 != -1 && ans > t1)) {
        ans = t1;
    }
    first.pop_back();

    second.push_back(idx);
    int t2 = go(idx+1, first, second);
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    second.pop_back();
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    vector<int> first, second;
    cout << go (0, first, second) << endl;

    return 0;
}
