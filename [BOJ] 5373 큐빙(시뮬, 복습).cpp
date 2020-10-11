#include <iostream>
#include <vector>
using namespace std;

void clockwise(vector<vector<char>> &a) {
    int n = 3;
    // (0, 0) (0, 1) (0, 2)
    // (1, 0) (1, 1) (1, 2)
    // (2, 0) (2, 1) (2, 2)
    // |
    // v
    // (2, 0) (1, 0) (0, 0)
    // (2, 1) (1, 1) (0, 1)
    // (2, 2) (1, 2) (0, 2)
    char temp = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[0][2];
    a[0][2] = temp;
    temp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = temp;
}

void F(vector<vector<vector<char>>> &a) {
    // 1 -> 2 -> 3 -> 4
    vector<vector<char>> temp = a[1];
    a[1] = a[4];
    a[4] = a[3];
    a[3] = a[2];
    a[2] = temp;
    clockwise(a[2]); clockwise(a[2]); clockwise(a[2]);
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
    clockwise(a[4]); clockwise(a[4]); clockwise(a[4]);
    clockwise(a[1]); clockwise(a[1]); clockwise(a[1]);
    clockwise(a[0]); clockwise(a[0]); clockwise(a[0]);
    clockwise(a[5]);
}
void U(vector<vector<vector<char>>> &a) {
    // 0 -> 2 -> 5 ->4
    vector<vector<char>> temp = a[0];
    a[0] = a[4];
    a[4] = a[5];
    a[5] = a[2];
    a[2] = temp;
    clockwise(a[5]); clockwise(a[5]);
    clockwise(a[4]); clockwise(a[4]);
    clockwise(a[1]);
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
}
void L(vector<vector<vector<char>>> &a) {
    // 0 -> 1 -> 5 -> 3
    vector<vector<char>> temp = a[0];
    for (int i=0; i<3; i++) {
        a[0][i][0] = a[3][i][0];
        a[3][i][0] = a[5][i][0];
        a[5][i][0] = a[1][i][0];
        a[1][i][0] = temp[i][0];
    }
    clockwise(a[4]);
}
void R(vector<vector<vector<char>>> &a) {
    // 0 -> 3 -> 5 -> 1
    vector<vector<char>> temp = a[0];
    for (int i=0; i<3; i++) {
        a[0][i][2] = a[1][i][2];
        a[1][i][2] = a[5][i][2];
        a[5][i][2] = a[3][i][2];
        a[3][i][2] = temp[i][2];
    }
    clockwise(a[2]);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M;
        vector<vector<vector<char>>> a;
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'w')));
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'r')));
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'b')));
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'o')));
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'g')));
        a.push_back(vector<vector<char>> (3, vector<char>(3, 'y')));
        for (int j = 0 ; j < M; j++) {
            string S;
            cin >> S;

            int k = 1;
            if (S[1] == '-') k = 3;

            switch(S[0]) {
                case 'L' :
                    for(int i = 0; i < k; i++) L(a);
                    break;
                case 'R' :
                    for(int i = 0; i < k; i++) R(a);
                    break;
                case 'U' :
                    U(a);
                    for(int i = 0; i < k; i++) R(a);
                    for(int i = 0; i < 3; i++) U(a);
                    break;
                case 'D' :
                    U(a);
                    for (int i=0; i<k; i++) L(a);
                    for (int i=0; i<3; i++) U(a);
                    break;
                case 'F' :
                    F(a);
                    for (int i=0; i<k; i++) R(a);
                    for (int i=0; i<3; i++) F(a);
                    break;
                case 'B' :
                    F(a);
                    for (int i=0; i<k; i++) L(a);
                    for (int i=0; i<3; i++) F(a);
                    break;
            }
        }
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                cout << a[0][x][y];
            }
            cout << endl;
        }
    }

    return 0;
}
