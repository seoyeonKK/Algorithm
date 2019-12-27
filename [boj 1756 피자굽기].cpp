#include <iostream>
#include <algorithm>
#define MAX 300000

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int depth = 0;
    int n = 0;
    int num = 0;
    int minList[MAX + 1];
    int pizza[MAX + 1];
    int idx = 1;

    minList[0] = 1000000001;

    cin >> depth >> n;

    for (int i = 1; i <= depth; i++) {
        cin >> num;
        minList[i] = min(num, minList[i-1]);
    }

    for (int i = 1; i <= n; i++) {
        cin >> pizza[i];
    }

    for (int i = depth; i > 0; i--) {

        if (minList[i] < pizza[idx])
            continue;

        idx = idx + 1;

        if (idx > n) {
            cout << i  << endl;
            return 0;
        }
    }

    cout << "0";

    return 0;
}
