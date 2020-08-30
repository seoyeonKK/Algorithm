#include <iostream>
#include <vector>
using namespace std;

int N = 9;
int arr[10][10];
int check_row[10][10];
int check_col[10][10];
int check_box[10][10];

int box (int i, int j) {
    return (i/3)*3 + (j/3);
}

bool sudoku (int idx) {
    if (idx == 81) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        return true;
    }

    int x = idx/N;
    int y = idx%N;

    if (arr[x][y] != 0) {
        return sudoku(idx+1);
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (check_row[x][i] == 0 && check_col[y][i] == 0 && check_box[box(x,y)][i]==0) {
                check_row[x][i] = check_col[y][i] = check_box[box(x,y)][i] = true;
                arr[x][y] = i;
                if (sudoku(idx+1)) {
                    return true;
                }
                arr[x][y] = 0;
                check_row[x][i] = check_col[y][i] = check_box[box(x,y)][i] = false;
            }
        }
    }
    return false;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] != 0) {
                check_row[i][arr[i][j]] = true;
                check_col[j][arr[i][j]] = true;
                check_box[box(i, j)][arr[i][j]] = true;
            }
        }
    }

    sudoku(0);

    return 0;
}
