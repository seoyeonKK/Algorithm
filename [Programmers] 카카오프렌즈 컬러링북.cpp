#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int Max_Size;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool visited[100][100];

int BFS(int a, int b, int m, int n, vector<vector<int>> map) {
    int color = map[a][b];
    int size = 1;
    queue<pair<int,int>> q;
    q.push({ a, b });
    visited[a][b] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0 ; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if(map[nx][ny] == color && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                    size++;
                }
            }
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) 
{
    for(int i = 0 ; i < m; i++) {
        for(int j = 0 ; j < n; j++) {
            visited[i][j] = false;
        }
    }
    
    int number_of_area = 0;
    int max_size_of_one_area = 0;  
    
    for(int i = 0; i < m; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(picture[i][j] != 0 && visited[i][j] == false) {
                int size = BFS(i, j, m, n, picture);
                if(size > max_size_of_one_area) max_size_of_one_area = size;
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
