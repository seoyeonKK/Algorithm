#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = {x, i};
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second - i > ans) {
            ans = v[i].second - i;  // 왼쪽으로 자리 몇 번 이동했는지
        }
    }

    cout << ans+1 << endl; // 문제에서 아무 수도 이동이 없을 때 종료를 하니까, ans+1을 한다. 
    
    return 0;
}
