#include <iostream>
using namespace std;

int N, M;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int coins[101];
    int d[10001] = {0};

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> coins[i];
    }

    d[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (j >= coins[i]) {
                d[j] += d[j-coins[i]];
            }
        }
    }

    cout << d[M] << endl;

    return 0;
}
