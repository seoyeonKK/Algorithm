#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> v;

int solve() {

    int partialSize = 1 << N; // 2^N
    vector<int> partialSum(partialSize);

    for (int i = 0; i < partialSize; i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) partialSum[i] += v[j]; // 덧셈 조합 만드는 비트 마스크 '표' 참고
        }
    }
    
    sort(partialSum.begin(), partialSum.end());

    if (partialSum[1] > 1) return 1; // 최솟값이 1보다 큰 경우, 1 리턴
    for (int i = 1; i < partialSize; i++) {
        if (partialSum[i] > partialSum[i-1] + 1) {
            return partialSum[i-1] + 1; // partialSum[i]와 partialSum[i-1]의 차가 1보다 클 경우, 그 사이에 자연수가 1개 이상 존재한다고 판단하여 'partialSum[i-1] + 1'을 리턴 
        }
    }
    
    return partialSum.back() + 1; // 덧셈 조합 최댓값보다 큰 경우, 가장 마지막 덧셈 조합 값에 1을 더한 값을 리턴
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    v = vector<int>(N);
    
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << solve() << endl;

    return 0;
}
