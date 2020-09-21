#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, int> &v1, const pair<int, int> &v2) {
    if (v1.second == v2.second) {
        return v1.first < v2.first;
    }
    else {
        return v1.second < v2.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> meeting(n);
    for (int i = 0; i < n; i++) {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), cmp);

    int now = 0, answer = 0;

    for (int i = 0; i < n; i++) {
        if (now <= meeting[i].first) {
            now = meeting[i].second;
            answer += 1;
        }
    }
    cout << answer << endl;

    return 0;
}
