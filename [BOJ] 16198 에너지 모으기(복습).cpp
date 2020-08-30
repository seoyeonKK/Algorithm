#include <iostream>
#include <vector>
using namespace std;

int N;

int getEnergy(vector<int> &m) {
    if (m.size() == 2) return 0;
    int ans = 0;

    for (int i = 1; i < m.size()-1; i++) {
        int energy = m[i-1] * m[i+1];
        vector<int> temp(m);
        temp.erase(temp.begin() + i);
        energy += getEnergy(temp);
        if (ans < energy) ans = energy;
    }

    return ans;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    vector<int> marble(N);
    for (int i = 0; i < N; i++) {
        cin >> marble[i];
    }

    cout << getEnergy(marble);

    return 0;
}
