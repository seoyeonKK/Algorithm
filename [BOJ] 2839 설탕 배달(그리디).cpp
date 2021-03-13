#include <iostream>
using namespace std;

int main() {
    int n;
    int a, b;
    cin >> n;
    a = n/5; // 5kg 봉투로 최대한 묶었을 때 5kg 봉투 갯수

    while(1) {
        // 나누어 떨어지지 않는다면 -1 리턴
        if (a < 0) {
            cout << -1 << endl;
            return 0;
        }

        // 남은 무게가 3kg 봉투로 묶이면 b에 3kg 봉투 갯수 저장하고 break
        if((n-(5*a))%3 == 0) {
            b = (n-(5*a))/3;
            break;
        }
        // 3kg 봉투로 묶여지지 않는다면 5kg 봉투 갯수 줄이기
        a--;
    }

    cout  << a+b << endl;
    return 0;
}
