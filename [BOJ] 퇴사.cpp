#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, period, cost;
int total = 0;
pair<int, int> p;
int dp[16] = {0, };
vector<pair<int, int>> schedule;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> period >> cost;

        schedule.push_back({ period, cost });
        dp[i] = cost;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {

            if (i - j >= schedule[i].first) {
                dp[i] = max(schedule[i].second + dp[j], dp[i]);
            }

        }
    }

    int max = 0;

    for (int i = 0; i < N; i++) {
        if (i + schedule[i].first < N) {
            if (max < dp[i]) {
                max = dp[i];
            }
        }
    }

    cout << max;

    return 0;
}
