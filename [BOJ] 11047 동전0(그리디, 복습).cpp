#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    int answer = 0;
    cin >> n >> k;

    vector<int> coin(n);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for (int i = n-1; i >= 0; i--) {
        answer += k/coin[i];
        k %= coin[i];
    }

    cout << answer << endl;

    return 0;
}
