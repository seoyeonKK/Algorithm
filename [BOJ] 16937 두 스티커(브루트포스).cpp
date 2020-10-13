#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int h, w, n;

    cin >> h >> w;
    cin >> n;
    vector<int> r(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> c[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r1 = r[i], c1 = c[i];
        for (int j = i+1; j < n; j++) {
            int r2 = r[j], c2 = c[j];
            for (int rot1 = 0; rot1 < 2; rot1++) {
                for (int rot2 = 0; rot2 < 2; rot2++) {
                    if (r1+r2 <= h && max(c1, c2) <= w) {
                        int temp = r1*c1 + r2*c2;
                        if (ans < temp) ans = temp;
                    }
                    if (max(r1, r2) <= h && c1+c2 <= w) {
                        int temp = r1*c1 + r2*c2;
                        if (ans < temp) ans = temp;
                    }
                    swap(r2, c2); // 회전
                }
                swap(r1, c1);  // 회전
            }
        }
    } 
    cout << ans << endl;
    return 0;
}
