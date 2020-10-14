#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N = 3;

bool is_magic(vector<int> &b) {
    int magic = b[0*N+0] + b[0*N+1] + b[0*N+2];
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += b[i*N+j]; // 행의 합
        }
        if (sum != magic) return false;
    }

    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += b[i*N+j]; // 열의 합 
        }
        if (sum != magic) return false;
    }

    // 대각선의 합 
    if (magic != (b[0*N+0] + b[1*N+1] + b[2*N+2])) return false; 
    if (magic != (b[0*N+2] + b[1*N+1] + b[2*N+0])) return false;

    return true;
}

int diff(vector<int> &a, vector<int> &b) {
    int ans = 0;
    for (int i = 0; i < N*N; i++) {
        int temp = a[i] - b[i];
        if (temp < 0) temp = -temp;
        ans += temp;
    }
    return ans;
}

int main() {
    vector<int> a(N*N);
    for (int i = 0; i < N*N; i++) {
        cin >> a[i];
    }
    vector<int> b(N*N);
    for (int i = 0; i < N*N; i++) {
        b[i] = i+1;
    }
    int ans = -1;
    do {
        if (is_magic(b)) {
            int cost = diff(a,b);
            if (ans == -1 || ans > cost) {
                ans = cost;
            }
        }
    } while(next_permutation(b.begin(), b.end()));

    cout << ans << endl;

    return 0;
}
