#include <iostream>
#include <vector>
using namespace std;

long long a[10000];
int k, n;

// 길이 X로 자르면 몇 개의 랜선이 나오는 지
bool check(long long x) {
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += a[i]/x;
    }
    return cnt >= n;
}

int main() {
    // [ 이분탐색 방법 ]
    // 1. 길이 X로 잘랐을 떄 N개 이상을 만들 수 있다면, X를 크게 만들어야 한다.
    // 2. N개 이상을 만들 수 없다면, X를 작게 만들어야 한다.
    // left = 1, right = 렌선 길이의 최댓값

    cin >> k >> n;
    long long max = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        if (max < a[i]) {
            max = a[i];
        }
    }
    long long ans = 0;
    long long left = 1;
    long long right = max;
    while(left <= right) {
        long long mid = (left+right)/2;
        if (check(mid)) {
            if (ans < mid) {
                ans = mid;
            }
            left = mid + 1;
        }
        else {
            right = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}
