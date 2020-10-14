#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int go(long long a, long long b) {
    if (a == b) return 1;
    if (a > b) return -1;

    int t1 = go(a*2, b); // t1
    int t2 = go(a*10+1, b); // t2

    if (t1 == -1 && t2 == -1) return -1; // 둘 다 불가능하면
    if (t1 == -1) return t2+1; // t2만 가능하면
    if (t2 == -1) return t1+1; // t1만 가능하면

    // 둘 다 가능하면 최솟값 리턴
    return min(t1, t2) + 1;
}

int main() {
    long long a, b;
    cin >> a >> b;

    cout << go(a, b) << endl;

    return 0;
}
