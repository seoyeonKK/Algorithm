#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lotto;
void solve(vector<int> &arr, int idx, int cnt) {
    if (cnt == 6) {
        for (int i; i < lotto.size(); i++) {
            cout << lotto[i] << " ";
        }
        cout << endl;
        return;
    }

    int size = arr.size();
    if (size == idx) return;
    lotto.push_back(arr[idx]);
    solve(arr, idx+1, cnt+1);
    lotto.pop_back();
    solve(arr, idx+1, cnt);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(1) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        solve(arr, 0, 0);
        cout << endl;
    }

    return 0;
}
