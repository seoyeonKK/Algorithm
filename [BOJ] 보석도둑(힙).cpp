#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;

struct jewel {
    int weight; // 무게
    int price; // 가격
    int check; // 0==보석, 1==가방
};

bool comp(jewel a, jewel b) {
    return a.weight < b.weight || (a.weight == b.weight && a.check < b.check);
}

int main () {
  int N, K;
  cin >> N >> K;
  vector<jewel> a(N+K);
  for(int i = 0; i < N; i++) {
      cin >> a[i].weight >> a[i].price;
  }
  for (int i = 0; i < K; i++) {
      cin >> a[i+N].weight;
      a[i+N].check = 1;
  }

  sort(a.begin(), a.end(), comp); // 가격이 낮은 보석부터

  priority_queue<int> q; // 가방 무게보다 작은 것만 들어감.
  long long ans = 0;
  for (auto &p : a) {
      if (p.check == 0) { // 보석이면 무게를 넣는다.
          q.push(p.price);
      }
      else {
          if (!q.empty()) {
              ans += (long long)q.top();
              q.pop();
          }
      }
  }

  cout << ans << endl;

  return 0;
}
