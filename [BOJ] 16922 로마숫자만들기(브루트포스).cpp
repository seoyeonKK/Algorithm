#include <iostream>
using namespace std;

bool check[50*20+1]; // 그 수를 만들 수 있는지, 없는지 기록

int main() {
    int N;
    cin >> N;

    for (int i = 0; i <= N; i++) { // I 갯수
        for (int j = 0; j <= N-i; j++) { // V 갯수
            for (int k = 0; k <= N-i-j; k++) { // X 갯수
                int l = N-i-j-k; // L 갯수
                int sum = i+5*j+10*k+50*l;
                check[sum] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 50*20; i++) {
        if (check[i]) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
