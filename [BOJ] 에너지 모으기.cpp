#include <iostream>
#include <algorithm>
using namespace std;

int N;
int weight[10] = {};
bool check[10] = {};

int getEnergy() {
    int answer = 0;

    for (int i = 1; i < N - 1; i++) {
        if (check[i]) continue;

        int left = i - 1;
        int right = i + 1;

        while(check[left]) left--;
        while(check[right]) right++;
        
        check[i] = true; // 구슬 삭제 체크
        answer = max(answer, getEnergy() + weight[left] * weight[right]);
        check[i] = false;
    }
    
    return answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> weight[i];

    cout << getEnergy() << endl;

    return 0;
}
