#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// b를 a로 바꾸는 방법 
int main() {
    long long a, b;
    cin >> a >> b;

    int cnt = 0;
    while(b >= a) {
        // 같다면 정답 출력 
        if (a == b) {
            cout << cnt + 1 << endl;
            return 0;
        }
        
        // 끝자리가 1이라면, 1제거 
        if (b % 10 == 1) {
            b = (b - 1) / 10;
        }
        
        // 2의 배수라면, 2나누기 
        else if (b % 2 == 0) {
            b = b / 2;
        }
        
        // 모두 아니라면 불가능한 수 
        else
            break;
        
        cnt++;
    }
    cout << -1 << endl;
    return 0;
}
