#include <iostream>
using namespace std;

int N;
int a[20];
bool c[20*100000+10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < (1<<N); i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            if (i&(1<<j)) {
                sum += a[j];
            }
        }
        c[sum] = true;
    }

    for (int i = 1; ; i++) {
        if (!c[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
