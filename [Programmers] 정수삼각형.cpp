#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> temp(triangle.size(),vector<int>(triangle.size())); // 벡터 크기 동적 할당
    temp[0][0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); i++) {
      for (int j = 0; j <= i; j++) {

        // 왼쪽 가장자리일 때 윗 노드 영향만 받음
        if (j == 0)
          temp[i][j] = temp[i - 1][j] + triangle[i][j];

        // 오른쪽 가장자리일 때 윗 노드 영향만 받음
        else if (j == i)
          temp[i][j] = temp[i - 1][j - 1] + triangle[i][j];

        // 가장자리가 아닌 노드
        else {
          temp[i][j] = max(temp[i - 1][j - 1] + triangle[i][j], temp[i - 1][j] + triangle[i][j]);
        }

        // 마지막 줄에서 가장 큰 값 추출
        if (i == triangle.size() - 1)
          answer = max(answer, temp[i][j]);
      }
    }    
    return answer;
}
