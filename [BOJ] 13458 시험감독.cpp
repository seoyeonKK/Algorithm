#include <iostream>
#include <queue>
using namespace std;

int N;
int master, sub;
long long answer = 0;
queue<int> room;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        room.push(n);
    }

    cin >> master >> sub;

    while(!room.empty()) {
        int student;
        student = room.front() - master;

        answer++; // 정 감독관 한 명은 무조건

        // 부 감독관 필요 시에
        if (student > 0) {
            answer += (student / sub); // 부 감독관 발생 수
            if (student % sub) answer++; // 나머지가 발생 시 부 감독관 한 명 추가
        }

        room.pop();
    }

    cout << answer;
    
    return 0;
}
