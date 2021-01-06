#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;

    vector<long long> blue(N);
    long long right = 1000000;
    long long left = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> blue[i];
        left = max(left, blue[i]);
    }

    while (left <= right) {
        //필요 블루레이의 갯수
        int cnt = 1;
        long long mid = (left + right) / 2;
        long long sum = blue[0]; // sum을 첫번째 블루레이로 초기화

        //최소 필요 블루레이의 갯수를 구하는 과정
        for (int i = 1; i < N; i++) {
            if (sum + blue[i] > mid) { // 다음 음반 길이 합이 mid를 넘기면 블루레이 추가
                cnt++;
                sum = 0; // sum 초기화
            }
            sum += blue[i];
        }

        if (cnt <= M)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << left << endl;

    return 0;
}
