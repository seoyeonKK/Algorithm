#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define p pair<int,int>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int map[20][20];
int n;
int idx = 1;
int ans;

struct Fish {
    int size;
    int alive;
    int x;
    int y;
    Fish(){};
    Fish(int a, int b, int c, int d) : size(a), alive(b), x(c), y(d) {};
};

struct Shark {
    int size;
    int eat;
    int x;
    int y;
    Shark(){};
    Shark(int a, int b, int c, int d) : size(a), eat(b), x(c), y(d) {};
};

Fish fish_map[400];
Shark shark;

bool inRange(int x, int y){
    if( x<0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

p distance(int idx){
    if(fish_map[idx].size >= shark.size){
        return p(-1,-1);
    }

    int visit[20][20] = {0,};
    int time[20][20] = {0,};
    int x = shark.x;
    int y = shark.y;
    int nx = x;
    int ny = y;

    queue<p> q;
    q.push(p(x,y));
    visit[x][y] = 1;
    time[x][y] = 1;

    while (! q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            nx = x + dx[i];
            ny = y + dy[i];

            if(! inRange(nx, ny)) continue;
            if(visit[nx][ny]) continue;
            if( fish_map[ map[nx][ny] ].size > shark.size) continue;
            if( map[nx][ny] == idx){
                return p(time[x][y],idx);
            }

            visit[nx][ny] = 1;
            time[nx][ny] = time[x][y] + 1;
            q.push(p(nx,ny));
        }
    }
    return p(-1,-1);
}

void solve() {

    /*
    * 먹을 수 있는 물고기 : shark보다 크기가 작음
    * 1순위 : 거리 순
    * 2순위 : x
    * 3순위 : y
    */
    while(1) {
        vector<pair<int, pair<int,int> > > v;
        for(int i=1; i<idx; i++){
            /*
             이미 먹은 물고기에 대해서는 Pass
             */
            if(fish_map[i].alive == 0) {
                continue;
            }

            p res = distance(i);

            if(res.first != -1 && res.second != -1){
                v.push_back({res.first, {fish_map[res.second].x,fish_map[res.second].y}   });
            }
        }

        if(v.size() == 0) break;

        sort(v.begin(), v.end());

        int x = v.front().second.first;
        int y = v.front().second.second;
        int t = v.front().first;

        ans += t;

        fish_map[map[x][y]].alive = 0;
        map[x][y] = 0;
        shark.x = x;
        shark.y = y;
        shark.eat++;

        if(shark.eat == shark.size) {
            shark.size++;
            shark.eat = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];

            if (9 == map[i][j]) {
                map[i][j] = 0;
                shark.size = 2;
                shark.x = i;
                shark.y = j;
                shark.eat = 0;
            }
            else if(map[i][j] >= 1 && map[i][j] <= 6){
                fish_map[idx] = Fish(map[i][j],1,i,j);
                map[i][j] = idx;
                idx++;
            }
        }

    solve();

    return 0;
}
