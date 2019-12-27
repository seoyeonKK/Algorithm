/*
 * 2019 SDS 입과테스트 2번 스도쿠
 */
#include <iostream>
#include <algorithm>
using namespace std;


void reverse(int arr[], int start, int end) {
    int temp;
    end = end - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// 왼쪽 한 칸 이동
void shiftLeft(int arr[]) {
    reverse(arr, 0, 3);
    reverse(arr, 3, 12);
    reverse(arr, 0, 12);
}

// 오른쪽 한 칸 이동
void shiftRight(int arr[]) {
    reverse(arr, 0, 12 - 3);
    reverse(arr, 12 - 3, 12);
    reverse(arr, 0, 12);
}

int main() {
    int n,m;
    int cmd;
    int face;

    cin >> n;

    for (int i=0; i<n; i++) {
        int row[3][12] = {{37,38,39,10,11,12,46,47,48,36,35,34},
                          {40,41,42,13,14,15,49,50,51,33,32,31},
                          {43,44,45,16,17,18,52,53,54,30,29,28}};

        int column[3][12] = {{1,4,7,10,13,16,19,22,25,28,31,34},
                             {2,5,8,11,14,17,20,23,26,29,32,35},
                             {3,6,9,12,15,18,21,24,27,30,33,36}};
        cin >> m;
        for (int j=0; j<m; j++) {
            cin >> cmd;

            int temp[3][3];
            if (cmd<=3) {
                shiftLeft(column[cmd-1]);
                for (int k=0; k<3; k++) {
                    row[k][cmd+2] = column[k][cmd+2];
                    row[k][12-cmd] = column[2-k][cmd-1];
                }

                // 옆면 90도 회전 발생하는 경우
                if (cmd==1) {
                    for(int i=0; i<3; i++) {
                        for (int j=0; j<3; j++) {
                            temp[2-j][i] = row[i][j];
                        }
                    }
                    for(int i=0; i<3; i++) {
                        for (int j=0; j<3; j++) {
                            row[i][j] = temp[i][j];
                        }
                    }
                }
                else if (cmd==3) {
                    for(int i=6; i<9; i++) {
                        for (int j=6; j<9; j++) {
                            temp[i-6][8-j] = row[j][i];
                        }
                    }
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            row[i][j] = temp[i-6][j-6];
                        }
                    }
                }
            }
            else if (cmd<=6) {
                shiftRight(column[cmd-4]);
                for (int k=0; k<3; k++) {
                    row[k][cmd+2] = column[k][cmd+2];
                    row[k][12-cmd] = column[2-k][cmd-1];
                }

                // 옆면 90도 회전 발생하는 경우
                if (cmd==4) {
                    for(int i=0; i<3; i++) {
                        for (int j=0; j<3; j++) {
                            temp[i][2-j] = row[j][i];
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            row[i][j] = temp[i][j];
                        }
                    }
                }
                else if (cmd==6) {
                    for(int i=6; i<9; i++) {
                        for (int j=6; j<9; j++) {
                            temp[8-j][i-6] = row[i][j];
                        }
                    }
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            row[i][j] = temp[i-6][j-6];
                        }
                    }
                }
            }
            else if (cmd<=9) {
                shiftLeft(row[cmd-7]);
                for (int k=0; k<3; k++) {
                    column[k][cmd-4] = row[cmd-7][k+3];
                    column[k][18-cmd] = row[cmd-7][11-k];
                }

                // 옆면 90도 회전 발생하는 경우
                if (cmd==7) {
                    for(int i=0; i<3; i++) {
                        for (int j=0; j<3; j++) {
                            temp[2-j][i] = column[i][j];
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            column[i][j] = temp[i][j];
                        }
                    }
                }
                else if (cmd==9) {
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            temp[i-6][8-j] = column[j][i];
                        }
                    }
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            column[i][j] = temp[i-6][j-6];
                        }
                    }
                }
            }
            else if (cmd<=12) {
                shiftRight(row[cmd-10]);
                for (int k=0; k<3; k++) {
                    column[k][cmd-7] = row[cmd-10][k+3];
                    column[k][21-cmd] = row[cmd-10][11-k];
                }
                
                // 옆면 90도 회전 발생하는 경우 
                if (cmd==10) {
                    int temp[3][3];
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            temp[i][2-j] = column[j][i];
                        }
                    }
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            column[i][j] = temp[i][j];
                        }
                    }
                }
                if (cmd==12) {
                    int temp[3][3];
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            temp[8-j][i-6] = column[i][j];
                        }
                    }
                    for (int i = 6; i < 9; i++) {
                        for (int j = 6; j < 9; j++) {
                            column[i][j] = temp[i-6][j-6];
                        }
                    }
                }
            }

        }

        cin >> face;
        cout << "#" << i+1 << " ";
        
        // 최종 선택 면
        if (face<5) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    cout << column[k][face*3+j-3] << " ";
                }
            }
        }
        else if (face==5) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    cout << row[j][k] << " ";
                }
            }
        }
        else if (face==6) {
            for (int j=0; j<3; j++) {
                for (int k=7; k<10; k++) {
                    cout << row[j][k] << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}
