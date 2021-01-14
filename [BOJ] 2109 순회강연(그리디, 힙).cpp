#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct lecture {
    int pay;
    int day;
};

bool comp(lecture a, lecture b) {
    return a.day > b.day;
}

int main () {
  int N;
  cin >> N;
  vector<lecture> a(N);
  for(int i = 0; i < N; i++) {
      cin >> a[i].pay >> a[i].day;
  }

  sort(a.begin(), a.end(), comp); // day가 큰 곳부터 sorting

  priority_queue<int> q;
  int k = 0;
  int ans = 0;
  for (int i = 10000; i >= 1; i--) {
      while(k<N && a[k].day == i) { // 같은 날에 있는 강연들 넣기, range out 될까봐 k<N 설정
          q.push(a[k].pay);
          k++;
      }
      if (!q.empty()) {
          ans += q.top(); // 있는 강연 중에 가장 페이가 쏀 것을 먼저 함.  
          q.pop(); // 페이를 받은 강연은 빼기
      }
  }
  cout << ans << endl;

  return 0;
}
