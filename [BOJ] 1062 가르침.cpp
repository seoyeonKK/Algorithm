#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int ans = 0;
bool alphaVisited[26];
string word[51];

int getCount() {
    int res = 0;

    for (int i=0; i<N; i++){
        int cnt = 0;
        for (int j=0; j<word[i].size(); j++){
            if (alphaVisited[word[i][j]-97]) {
                cnt++;
            }
            else break;
        }
        if(cnt == word[i].size())
            res++;
    }

    return res;
}

void dfs(int start, int count) {
    if (K-5 < 0) return;

    if (count == K-5) {
        ans = max(ans, getCount());
        return;
    }

    for (int i=start; i<26; i++){
        if (!alphaVisited[i]){
            alphaVisited[i] = true;
            dfs(i, count+1);
            alphaVisited[i] = false;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    for (int i=0; i<N; i++) {
        cin >> word[i];
    }

    alphaVisited['a'-97] = true;
    alphaVisited['n'-97] = true;
    alphaVisited['t'-97] = true;
    alphaVisited['i'-97] = true;
    alphaVisited['c'-97] = true;

    dfs(0, 0);

    cout << ans << endl;

    return 0;
}
