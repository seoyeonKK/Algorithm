#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;

    return GCD(b, a%b);
}

int main () {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }
        long long  sum = 0;
        for (int i = 0; i < N-1; i++) {
            for (int j = i+1; j < N; j++) {
                sum += GCD(v[i], v[j]);
            }
        }
        cout << sum << endl;
    }
}
