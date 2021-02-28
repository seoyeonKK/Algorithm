#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// 가중치에 대한 오름차순 정렬
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
 
// 부모노드 찾기
int getParent(vector<int>& parent, int x) {
    // 자신일 경우
    if (parent[x] == x) 
        return x;
    // 자신이 아니라면 최상위 부모노드 찾기
    return parent[x] = getParent(parent, parent[x]);
}
 
// 부모노드 병합
void unionParent(vector<int>& parent, int a, int b) {
    // 두개의 부모를 가져와서
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    // 작은 노드쪽의 부모로 병합시키기
    if (a < b) {
        parent[b] = a;
    }
    else {
        parent[a] = b;
    }
}
 
// 부모노드가 같은지 비교
bool find(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    return a == b;
}
 
int solution(int n, vector<vector<int>> costs) {
    int answer = 0, max = 0;
    
    sort(costs.begin(), costs.end(), cmp); // 가중치 정렬
    
    for (auto a : costs) {
        if (max < a[1]) {
            max = a[1];
        }
    }
    
    vector<int> parent;
    for (int i = 0; i <= max; i++) {
        parent.push_back(i); // 부모노드 초기화
    }
    
    for (auto a : costs) {
        // 두개의 부모노드가 같지않다면
        if (!find(parent, a[0], a[1])) {
            // 가중치 추가
            answer += a[2];
            // 부모노드 병합하기
            unionParent(parent, a[0], a[1]);
        }
    }
    return answer;
}
