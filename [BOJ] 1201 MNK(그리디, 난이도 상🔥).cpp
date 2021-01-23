#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {

    // M : 증가, K : 감소
    // [1단게] (1 2 3 4) (5 6 7 8) (9) M개의 그룹으로 나눔.
    // [2단계] (4 3 2 1) (8 7 6 5) (9) 각 그룹을 뒤집음.
    // [3단계] ('4' 3 2 1) ('8' 7 6 5) ('9') 긱 그룹에서 하나씩 뽑으면 증가 순열이 된다.
    // [4단계] 그룹의 길이가 K가 되는 그룹이 감소 수열이 된다.
    // 그룹의 개수 = 증가 수열의 길이(M)
    // 그룹의 최대 크기 = 감소 수열의 길이(K)

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> a(N);

    // 최소 범위 : M+K-1(최소 1개를 공유할 수 있기 때문)
    // 최대 범위 : MK+1(M+1인 수열이나 K+1인 수열을 반드시 만들기 때문 - 비둘기집 원리 증명)
    if ((M+K-1 <= N) && (N <= M*K)) {
        for (int i = 0; i < N; i++) {
            a[i] = i+1; // 전체 증가 순열
        }
        vector<int> g;
        g.push_back(0);
        g.push_back(K); // 첫번째 그룹의 경계 0 ~ K 만들기 
        N -= K; // 남은 수열 갯수
        M -= 1; // 그룹 만들면 그룹 갯수 빼기
        int gs = M == 0 ? 1 : N/M;
        int r = M == 0 ? 0 : N%M; // N/M의 나머지

        // 나머지 그룹의 경계 만들기
        for (int i = 0; i < M; i++) {
            g.push_back(g.back()+gs + (r > 0 ? 1 : 0)); // 나머지 r이 있으면 1을 더함
            if (r > 0) {
                r -= 1;
            }
        }
        
        // 각 그룹 뒤집기 
        for (int i = 0; i < g.size()-1; i++) {
            reverse(a.begin()+g[i], a.begin()+g[i+1]);
        }
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
