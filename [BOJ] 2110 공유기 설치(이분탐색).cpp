#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 공유기 설치가 가능한지 체크하는 함수
bool possible(vector<int> &h, int c, int x) { // possible(집의 위치, 공유기 개수, 가장 인접한 두 공유기 사이 거리)
    int cnt = 1;
    int last = h[0];
    for (int house : h) {
        if (house - last >= x) {
            cnt += 1;
            last = house;
        }
    }
    return cnt >= c;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<int> house(n);
    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int l = 1; // 가장 인접한 두 공유기 사이 거리 범위 : 1 < mid < house[n-1] - house[0]
    int r = house[n-1] - house[0];
    int ans = l;
    while(l <= r) {
        int mid = (l+r)/2;
        if (possible(house, c, mid)) {
            if (ans < mid) {
                ans = mid;
            }
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
