#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    
    int min = routes[0][1];
    
    for (int i = 0; i < routes.size() - 1; i++) {
        if (min > routes[i][1]) min = routes[i][1];
        if (min < routes[i + 1][0]) { 
            answer += 1;
            min = routes[i + 1][1];
        }
    }

    return answer;
}
