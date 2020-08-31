#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;
bool c[20*1000000+10]; // 20*100000인데 넓게 쓰려고

void solve(int idx, int sum) {
    if (idx == N) {
        c[sum] = true;
        return;
    }

    solve(idx+1, sum+num[idx]);
    solve(idx+1, sum);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    solve(0, 0);

    int i = 1;
    while(1) {
        if (!c[i]) {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;
}
