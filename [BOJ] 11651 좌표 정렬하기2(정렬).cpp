#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> point(n);

    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point.begin(), point.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << point[i].first << " " << point[i].second << '\n';
    }

    return 0;
}
