#include <iostream>
#include <vector>
#define MAX 1001
using namespace std;

int main() {
    int n;
    int house[MAX][3];
    int cost[3];

    // dp 계산하기 위해 0번쨰 인덱스 초기화 
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        // 루트 둘 중 최소 비용 dp에 저장 
        house[i][0] = min(house[i-1][1], house[i-1][2]) + cost[0]; 
        house[i][1] = min(house[i-1][0], house[i-1][2]) + cost[1];
        house[i][2] = min(house[i-1][0], house[i-1][1]) + cost[2];
    }

    cout << min(house[n][0], min(house[n][1], house[n][2])) << endl;

    return 0;
}

