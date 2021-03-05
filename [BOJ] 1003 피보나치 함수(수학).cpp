#include <iostream>
#define MAX 40
using namespace std;

int dp[MAX+1];

int fibo(int n) {
    if (n <= 0) {
        dp[0] = 0;
        return 0;
    }
    else if (n == 1) {
        dp[1] = 1;
        return 1;
    }

    if (dp[n] != 0) {
        return dp[n];
    }
    else {
        return dp[n] = fibo(n-1) + fibo(n-2);
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if (n == 0) {
            cout << "1 0" << endl;
        }
        else {
            cout << fibo(n-1) << ' ' << fibo(n) << '\n';
        }
    }

    return 0;
}
