#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> customer;
int n, m, taxi_x, taxi_y, s_x, s_y, e_x, e_y;
long long oil;
int start[22][22] = {0, }; // 각 승객들의 출발 위치에 따른 번호
int map[22][22] = {0, };
int done[402] = {0, }; // 이미 태운 승객
bool check = false;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

// {sx, sy} -> {ex, ey} 사이의 거리를 계산하는 함수
int bfs(int sx, int sy, int ex, int ey) {
    int visited[21][21] = {0, };
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(sx, sy)));
    visited[sx][sy] = 1;

    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int num = q.front().first;
        q.pop();

        if(x==ex && y==ey){
            return num;
        }

        for(int i = 0; i < 4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(1 <= nx && nx <= n && 1 <= ny && ny <= n && !visited[nx][ny]){
                if(map[nx][ny]==0){
                    q.push(make_pair(num+1, make_pair(nx, ny)));
                    visited[nx][ny] = 1;
                }
            }
        }
    }

    return -1;
}

bool choose() {
    vector<pair<int, pair<int, int>>> temp;
    for(int i = 0; i < customer.size(); i++){
        if(done[i]) continue;
        // 승객 위치
        int start_x = customer[i].first.first;
        int start_y = customer[i].first.second;

        // 택시 - 승객 거리 계산
        int dist = bfs(taxi_x, taxi_y, start_x, start_y);
        // 못 태우는 경우
        if(dist==-1){
            return false;
        }
        // temp 큐 임시로 삽입
        temp.push_back(make_pair(dist, make_pair(start_x, start_y)));
    }

    // dist 기준으로 sorting
    sort(temp.begin(), temp.end());

    // 가장 가까운 승객 정보
    int pick = temp[0].first;
    int x = temp[0].second.first;
    int y = temp[0].second.second;
    int cus_num = start[x][y];
    int nx = customer[cus_num].second.first;
    int ny = customer[cus_num].second.second;

    // 손님 태우러 가는 거리
//    int pick = bfs(taxi_x, taxi_y, x, y);
    if (pick == -1){
        return false;
    }

    int drop = bfs(x, y, nx, ny);
    if (drop == -1){
        return false;
    }

    int total_dist = pick + drop;

    // 오일이 부족하면 false
    if (oil < total_dist){
        return false;
    }

    // oil 뺴고, 2배 충전하기
    oil -= total_dist;
    oil += (drop*2);
    done[cus_num] = 1;

    // 택시 위치 재설정
    taxi_x = nx;
    taxi_y = ny;
    m--;

    return true;
}

void drive() {
    while(1){
        // 오일 없으면 break
        if(oil <= 0){
            check = true;
            break;
        }
        // 사람 다 태웠으면 break
        if(m==0){
            break;
        }
        // 태울 승객 정하기
        if(!choose()){ // 운행을 못하는 경우 탈출
            check = true;
            break;
        }
    }
}

int main() {
    cin >> n >>m >> oil;
    for(int i = 1; i <= n; i++){
        for(int  j=1; j <= n; j++){
            cin >> map[i][j];
        }
    }

    cin >> taxi_x >> taxi_y;
    for(int i = 0; i < m; i++){
        cin >> s_x >> s_y >> e_x >> e_y;
        customer.push_back({{s_x, s_y}, {e_x, e_y}});
        start[s_x][s_y] = i; // 각 위치에 대한 승객 idx 넣기(customer 큐에 idx로 접근하기 위함)
    }

    drive();

    // 영업 중단
    if(check == true) {
        cout << "-1" << endl;
    }
    else{
        cout << oil << endl;
    }

    return 0;
}
