#include <iostream>
using namespace std;

int d[1500000+50];
int t[1500000];
int p[1500000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t[i] >> p[i];
    }

    for (int i = 0; i < n; i++) {
        d[i+t[i]] = max(d[i+t[i]], d[i]+p[i]);
        d[i+1] = max(d[i+1], d[i]);
    }

    cout << d[n] << endl;

    return 0;
}
