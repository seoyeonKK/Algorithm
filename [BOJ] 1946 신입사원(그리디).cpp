#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> rank(n);
        for (int i = 0; i < n; i++) {
            cin >> rank[i].first >> rank[i].second;
        }

        sort(rank.begin(), rank.end());

        int result = 1;
        int interviewRank = rank[0].second;

        for (int i = 1; i < n; i++) {
            if (rank[i].second < interviewRank) {
                result++;
                interviewRank = rank[i].second;
            }
        }

        cout << result << endl;

    }
    return 0;
}
