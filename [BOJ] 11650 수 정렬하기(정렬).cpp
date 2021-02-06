#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> point(n);

    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point.begin(), point.end());

    for (int i = 0; i < n; i++) {
        cout << point[i].first << " " << point[i].second << '\n';
    }

    return 0;
}
