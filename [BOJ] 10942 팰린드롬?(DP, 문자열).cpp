#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dp[2001][2001] = {0,};
vector<int> num;

void palin() {
    // 문자열 길이 1인 팰린드롬 체크
    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }
    // 문자열 길이 2인 팰린드롬 체크
    for (int i = 1; i < N; i++) {
        if (num[i] == num[i+1]) {
            dp[i][i+1] = 1;
        }
    }
    // 문자열 길이 3이상인 팰린드롬 체크
    for (int i = 2; i < N; i++) { // 팰린드롬 S와 E의 idx 차, "abcba"이고 S=1, E=4일 때 i=3이 된다.
        for (int j = 1; j <= N-i; j++) { // j는 S를 의미 
            if (num[j] == num[j+i] && dp[j+1][j+i-1]) // S(j)와 E(j+i)가 같다면, 그 사이에 있는 문자가 팰린드롬인지 체크(dp를 사용했기 때문에 가장 바깥쪽만 확인하면 됨)
                dp[j][j+i] = 1;
        }
    }
}

int main () {
    int S, E;
    cin >> N;
    num.resize(N);

    for (int i = 1; i <= N; i++) {
        cin >> num[i];
    }
    palin();
    cin >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }
    return 0;
}
