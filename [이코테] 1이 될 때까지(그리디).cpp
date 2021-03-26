#include <iostream>
using namespace std;

int main () {
    int n, k;
    int result = 0;
    cin >> n >> k;

    while(true) {
        int num = (n/k) * k; // n보다 작지만 가장 가까운 k의 배수
        result += (n - num); // 1로 뺄 횟수 더하기
        n = num;

        if (n < k) break;
        result++; // 나누는 횟수 더하기
        n /= k;
    }

    // 마지막으로 남은 수 1씩 빼기
    result += (n-1);
    cout << result << endl;

    return 0;
}
