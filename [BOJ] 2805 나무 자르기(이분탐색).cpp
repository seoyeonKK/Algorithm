#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// mid길이의 절단기로 나무를 잘랐을 떄 m을 만족하는지 확인하는 함
bool check(vector<long long> &tree, long long mid, long long m) { // check(나무벡터, 절단기 높이, 최소 m)
    int n = tree.size();
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i]-mid > 0) {
            cnt += (tree[i]-mid);
        }
    }
    return cnt >= m;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    
    vector<long long> tree(n);
    long long l = 0; // 절단기 길이의 범위(이분탐색) : 0 < X < 가장 높은 나무의 높이
    long long r = 0;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        if (r < tree[i]) { // 가장 높은 나무의 길이를 최댓값으로 설정
            r = tree[i];
        }
    }

    long long ans = 0;
    while(l <= r) {
        long long mid = (l+r)/2;
        if (check(tree, mid, m)) {
             ans = max(ans, mid);
             l = mid+1;
        }
        else {
            r = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}
