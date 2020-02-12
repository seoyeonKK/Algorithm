#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int depth;
    int rx, ry, bx, by;
    Node(int e, int a,int b, int c, int d): depth(e), rx(a), ry(b), bx(c), by(d){};
};
int r_x, r_y, b_x, b_y, h_x, h_y;

int n, m;
int ans;

int map[10][10];
bool visit[10][10][10][10];

// 동 북 서 
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


void move(int &x, int &y, int d) {
    while (1) {
        x += dx[d];
        y += dy[d];
        if (map[x][y] == 1) {
            x -= dx[d];
            y -= dy[d];
            break;
        }
        else if (map[x][y] == 2) {
            break;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ans = -1;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++){
            switch (s[j]) {
                case '#' :
                    map[i][j] = 1;
                    break;

                case '.' :
                    map[i][j] = 0;
                    break;

                case 'O' :
                    map[i][j] = 2;
                    h_x = i;
                    h_y = j;
                    break;

                case 'R' :
                    r_x = i;
                    r_y = j;
                    break;

                case 'B' :
                    b_x = i;
                    b_y = j;
                    break;
            }
        }
    }


    queue<Node> q;
    q.push( Node(0, r_x, r_y, b_x, b_y) );
    visit[r_x][r_y][b_x][b_y] = true;

    while(!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.depth > 10)
            break;
        if (node.rx == h_x && node.ry == h_y) {
            ans = node.depth;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int rx = node.rx, ry = node.ry;
            int bx = node.bx, by = node.by;
            move(rx, ry, i);
            move(bx, by, i);

            /*
             Blue 공이 Hall에 빠지면 안된다.
             */
            if (bx == h_x && by == h_y)
                continue;
            /*
             row or column
             같은 선상에 있었다면 예외처리를 해줘야한다.
             0 : 서
             1 : 북
             2 : 동
             3 : 남
             */
            if (rx == bx && ry == by) {
                switch (i) {
                   case 0: // 남
                        node.rx < node.bx ? rx-- : bx--; break;
                    case 2: // 북
                        node.rx < node.bx ? bx++ : rx++; break;
                    case 1: // 동
                        node.ry < node.by ? ry-- : by--; break;
                    case 3: // 서
                        node.ry < node.by ? by++ : ry++; break;
                }
            }

            /*
             visit처리 안해줘도 AC
             하지만 안해주면
             엄청 난 시간이 더 소요된다.
             */
            if (!visit[rx][ry][bx][by]) {
                q.push( Node(node.depth + 1,rx,ry,bx,by ) );
                visit[rx][ry][bx][by] = true;
            }
        }
    }

    cout << ans;
    return 0;
}
