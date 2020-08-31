#include <iostream>
using namespace std;

int N;
int Time[21];
int Pay[21];
int ans = 0;

void go(int day, int sum) {
    if (day == N+1) {
        if (sum > ans) ans = sum;
        return;
    }

    if (day > N+1) return;

    go(day+1, sum);
    go(day+Time[day], sum+Pay[day]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> Time[i] >> Pay[i];
    }

    go(1, 0);

    cout << ans << endl;

    return 0;
}
