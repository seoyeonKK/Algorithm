#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int x, int y) {
    return x > y;
}

int main () {
    int N;
    cin >> N;
    vector<int> plus;
    vector<int> minus;
    int zero = 0;
    int one = 0;

    // < 수열 묶는 방법 >
    // (1) 음수는 0을 이용해 최대를 만든다.
    // (2) 1은 묶지 않는다.
    // (3) 양수는 양수끼리, 음수는 음수끼리.

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            one += 1; // 1의 갯수 세기
        }
        else if (x > 0) {
            plus.push_back(x);
        }
        else if (x < 0) {
            minus.push_back(x);
        }
        else {
            zero += 1; // 0의 갯수 세기
        }
    }

    sort(plus.begin(), plus.end(), comp); // 큰 수 부터 sort
    sort(minus.begin(), minus.end()); // 작은 수 부터 sort

    if (plus.size()%2 == 1) {
        plus.push_back(1); // plus가 홀수개일 경우 맨 마지막 수에 1을 넣음
    }
    if (minus.size()%2 == 1) {
//        if (zero > 0) {
//            minus.push_back(0);
//        }
//        else {
//            minus.push_back(1);
//        }
//        아래식과 같습니다.
        minus.push_back(zero > 0 ? 0 : 1); // minus가 홀수개일 경우 0이 있다면 맨 마지막 수에 0을 넣음. 없으면 1.
    }

    int ans = one; // 1의 갯수로 초기화
    for (int i = 0; i < plus.size(); i += 2) {
        ans += (plus[i] * plus[i+1]);
    }
    for (int i = 0; i < minus.size(); i += 2) {
        ans += (minus[i] * minus[i+1]);
    }

    cout << ans << endl;

    return 0;
}
