#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
int N, M, K;
int add_bun[10][10], bun[10][10];

struct Node{
    int value;
    int alive;
    Node(int a,int b): value(a), alive(b) {};
};

vector<Node> map[10][10];
vector<Node> v;

/*
 내림차순 정렬을 위한 compare 함수
 */
bool compare(Node &p1, Node &p2){
    return p1.value > p2.value;
}

bool inRange(int x, int y){
    if( x < 0 || x >= N || y < 0 || y >= N)
        return false;
    return true;
}

void spring_summer(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int size = (int) map[i][j].size();

            // (i, j)에 나무가 하나도 없으면
            if( size == 0 )
                continue;

            v.clear();
            /*
             봄 작업
             */

            // 나이 내림차순
            sort(map[i][j].begin(), map[i][j].end(), compare);

            for(int k=size-1; k>=0; k--){
                /*
                 내림차순 정렬을 했기 때문에
                 가장 마지막 부분부터 참조한다.
                 */
                Node top = map[i][j][k];
                map[i][j].pop_back();
                if(bun[i][j] >= top.value){
                    bun[i][j] -= top.value;
                    v.push_back( Node(top.value + 1, 1 ) ); // 양식을 먹고 산 나무
                }
                else{
                    v.push_back( Node(top.value , 0 )); // 양식을 못먹고 죽은 나무
                }
            }

            /*
             여름 작업
             alive = 1 이면 다시 map에 더해주고
             alive = 0 이면 양분(=bun)으로 더해준다.
             */
            for(int k=0; k<size; k++){
                if(v[k].alive == 0){
                    bun[i][j] += v[k].value / 2;
                }
                else{
                    map[i][j].push_back( v[k]  );
                }
            }

        } // end of for j
    } // end of for i
}

void fall_winter(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            int nx, ny;
            int size = (int) map[i][j].size();

            for(int k=0; k<size; k++) {
                if(0 == map[i][j][k].value%5) {
                    for (int q = 0; q < 8; q++) {
                        nx = i + dx[q];
                        ny = j + dy[q];
                        if (inRange(nx, ny)) {
                            map[nx][ny].push_back(Node(1, 1));
                        }
                    }
                }
            }

            bun[i][j] += add_bun[i][j];
        } // end of for j
    } // end of for i
}

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            bun[i][j] = 5;
            cin >> add_bun[i][j];
        }

    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x-1][y-1].push_back( Node(z,1) );
    }

    while (K--) {
        spring_summer();
        fall_winter();
    }

    int ans = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int size = (int) map[i][j].size();
            ans += size;
        }
    }

    cout << ans << endl;
    return 0;
}
