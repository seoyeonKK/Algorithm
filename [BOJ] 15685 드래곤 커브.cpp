#include<iostream>
#include<vector>
#define MAX 101
using namespace std;

// 동 북 서 남
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int map[MAX][MAX];
int N, y, x, d, g;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> v;

        cin >> x >> y >> d >> g;

        map[y][x] = 1;

        // 0세대
        y += dx[d];
        x += dy[d];
        map[y][x] = 1;

        // 1세대
        if (g > 0) {
            y += dx[(d + 1) % 4];
            x += dy[(d + 1) % 4];
            map[y][x] = 1;
            v.push_back((d + 1) % 4);
        }

        if (g > 1) {

            for (int j = 2; j <= g; j++) {
                int size = (int) v.size();
                for (int k = 0; k < size; k++) {

                    int p = k * 2;
                    int idx = (v[p] + 1) % 4;

                    v.insert(v.begin(), idx);

                } // end of for k

                for (int k = 0; k < size * 2; k++) {
                    y += dx[v[k]];
                    x += dy[v[k]];
                    map[y][x] = 1;
                } // end of for k

            } // end of for j

        } // end of if
    }

    int ans = 0;
    for(int i=1; i<101; i++){
        for(int j=1; j<101; j++){
            
            if( map[i][j] == 1 && map[i-1][j] == 1 &&
                map[i][j-1] == 1 && map[i-1][j-1] == 1
                    ){
                ans ++;
            }
        } // end of for j
    } // end of for i

    cout << ans << endl;
    return 0;
}
