#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;

bool check(vector<int>& belt, int k) {
    int count = 0;
    for (int i = 0; i < belt.size(); i++) {
        if (belt[i] <= 0) {
            count++;
        }
    }
    return count >= k;
}

void rotateBelt(vector<int>& belt) {
    int temp = belt[belt.size()-1];
    for (int i = belt.size()-1; i > 0; i--) {
        belt[i] = belt[i-1];
    }
    belt[0] = temp;
}

void rotateRobot(vector<bool>& robot) {
    for (int i = robot.size()-2; i >= 0; i--) {
        if (robot[i]) {
            robot[i+1] = true;
            robot[i] = false;
        }
    }
    robot[robot.size()-1] = false; // 내리는 곳에 로봇이 있다면 내리기
}

void moveRobot(vector<bool>& robot, vector<int>& belt) {
    for (int i = n-2; i >= 0; i--) {
        // i칸에 로봇이 있다면
        if (robot[i]) {
            // 이동하려는 칸에 로봇이 없고, 내구도가 1이상이어야 한다.
            if (!robot[i + 1] && belt[i + 1] >= 1) {
                robot[i + 1] = true; // 한 칸 이동
                robot[i] = false; // 기존 칸 비우기
                belt[i + 1] -= 1; // 내구도 1 감소
            }
        }
    }
    // 내력가는 칸이라면
    robot[n-1] = false; // 로봇을 내린다.
}

int main() {
    cin >> n >> k;

    vector<int> belt(n*2);
    vector<bool> robot(n, false);
    for (int i = 0; i < n*2; i++) {
        cin >> belt[i];
    }

    int time = 0;
    while(1) {
        time++;

        // 1. 벨트가 한 칸 회전한다.
        rotateBelt(belt);
        rotateRobot(robot);

        // 2. 가장 먼저 올라간 로봇부터 한 칸 이동한다.
        moveRobot(robot, belt);

        // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.(내구도가 0인 칸에는 로봇이 올라갈 수 없다)
        if (!robot[0] && belt[0] > 0) {
            robot[0] = true;
            belt[0] -= 1;
        }

        // 4. 내구도가 0인 칸의 개수가 K개 이상인지 체크 -> 맞다면 프로그램 종료
        if (check(belt, k)) break;
    }

    cout << time << endl;

    return 0;
}

