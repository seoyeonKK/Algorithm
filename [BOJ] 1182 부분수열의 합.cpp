#include <iostream>
#include <vector>
using namespace std;

int N, S;
int ans = 0;
vector<int> num;

void solve(int idx, int sum) {
    if (idx == N) {
        if (sum == S) {
            ans++;
        }
        return;
    }


    solve(idx+1, sum+num[idx]);
    solve(idx+1, sum);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    solve(0, 0);

    if (S == 0) ans -= 1;

    cout << ans << endl;

    return 0;
}
