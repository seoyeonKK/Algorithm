#include <string>
#include <vector>
#include <iostream>

#define MAX 101

using namespace std;

int arr[MAX][MAX] = {0, }; // 경로 수를 저장하는 배열
int puds[MAX][MAX] = {0, }; // 웅덩이 위치 저장하는 배열

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer;

    // "웅덩이" 위치면 1 로 초기화
    for (int i = 0; i < puddles.size(); i++) {
        puds[puddles[i][1]-1][puddles[i][0]-1] = 1;
    }

    // 집에서 경로 1로 출발
    arr[0][0] = 1;

    // 배열 순회
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // 첫 출발지면 continue
            if (i == 0 && j == 0)
                continue;

            // "웅덩이"면 경로 0개
            if (puds[i][j] == 1) {
                arr[i][j] = 0;
            }
            else {

                // 윗쪽 가장자리일 경우 바로 왼쪽 경로 받아오기
                if(i == 0) {
                    arr[i][j] = arr[i][j-1];
                }

                // 왼쪽 가장자리일 경우 바로 윗 경로 받아오기
                else if(j == 0) {
                    arr[i][j] = arr[i-1][j];
                }

                // 가운데 부분일 경우 윗, 왼쪽 경로 합해서 나머지 구하기
                else {
                    arr[i][j] = (arr[i-1][j] + arr[i][j-1]) % 1000000007;
                }
            }
        } // end of j
    } // end of i

    answer = arr[n-1][m-1];

    return answer;
}
