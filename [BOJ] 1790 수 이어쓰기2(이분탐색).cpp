#include <iostream>
#include <vector>
using namespace std;

// 길이 구하는 함수
int calc(int n) {
    int ans = 0;
    for (int start = 1, len = 1; start <= n; start*=10, len++) {
        int end = start*10 - 1;
        if (end > n) {
            end = n;
        }
        ans += (end - start + 1) * len;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    // n의 위치가 k 보다 클 때 -1 리턴
    if (calc(n) < k) {
        cout << -1 << endl;
        return 0;
    }

    int left = 1; // 가장 왼쪽 자리 = 1
    int right = n; // 가장 오른쪽 자리 = n
    int ans = 0;
    while(left <= right) {
        int mid = (left+right)/2;
        int len = calc(mid); // mid의 위치
        if (len < k) {
            left = mid + 1;
        }
        else {
            ans = mid;
            right = mid - 1;
        }
    }
    string s = to_string(ans);
    int l = calc(ans);
    cout << s[s.length()-(l-k)-1] << endl; // s의 끝에서 몇번째 자리인지

    return 0;
}
