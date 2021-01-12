#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct jewel {
    int weight; // 무게
    int cost; // 가격
};

bool comp(jewel a, jewel b) {
    return a.cost > b.cost;
}

int main () {
  int N, K;
  cin >> N >> K;
  vector<jewel> a(N);
  for(int i = 0; i < N; i++) {
      cin >> a[i].weight >> a[i].cost;
  }

  sort(a.begin(), a.end(), comp); // 가격이 높은 보석부터

  multiset<int> s;
  for (int i = 0; i < K; i++) {
      int t;
      cin >> t;
      s.insert(t);
  }
  long long ans = 0;
  for(int i = 0; i < N; i++) {
      auto it = s.lower_bound(a[i].weight); // a[i].weight의 이전 원소
      if (it != s.end()) { // 존재하면
          ans += a[i].cost;
          s.erase(it);
      }
  }
  cout << ans << endl;

  return 0;
}
