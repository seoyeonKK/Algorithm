#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h;

int getMaxLeft(vector<int> blocks, int idx) {
    int getMax = -1;
    for (int i = 0; i < idx; i++) {
        getMax = max(getMax, blocks[i]);
    }
    return getMax;
}

int getMaxRight(vector<int> blocks, int idx) {
    int getMax = -1;
    for (int i = idx + 1; i < w; i++) {
        getMax = max(getMax, blocks[i]);
    }
    return getMax;
}


int main() {
    cin >> h >> w;
    vector<int> blocks(w);

    for (int i = 0; i < w; i++) {
        cin >> blocks[i];
    }
    int ans = 0;
    
    // 중간 블록 탐색
    for (int i = 1; i < w - 1; i++) {
        int maxLeft = getMaxLeft(blocks, i); // 왼쪽 가장 높은 벽 찾기
        int maxRight = getMaxRight(blocks, i); // 오른쪽 가장 높은 벽 찾기 
        if (min(maxLeft, maxRight) < blocks[i]) {
            continue; // 높은 벽이 한쪽이라도 없으면 continue. (i번째가 벽이므로) 
        }
        ans += min(maxLeft, maxRight) - blocks[i]; // 물이 채워진 높이 = (min(좌, 우)높이 - block높이)
    }

    cout << ans << endl;
    return 0;
}

