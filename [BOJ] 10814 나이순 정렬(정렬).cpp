#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    stable_sort(a.begin(), a.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i].first << " " << a[i].second << "\n";
    }

    return 0;
}
