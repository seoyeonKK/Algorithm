#include <iostream>
#define MAX 10000
using namespace std;

int N, M;
int arr[MAX];

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int low = 0, high = 0;
    int sum = arr[0];
    int result = 0;

    //투 포인터 알고리즘 적용
    while(low <= high && high < N) {

        if (sum < M) {
            sum += arr[++high];
        }
        else if (sum == M) {
            result++;
            sum += arr[++high];
        }
        else if (sum > M) {
            sum -= arr[low++];
            //low가 high를 역전하면 low에서부터 다시 시작
            if (low > high && low < N) {
                high = low;
                sum = arr[low];
            }
        }

    }

    cout << result;

    return 0;
}
