#include <string>
#include <vector>

using namespace std;
int count;
void dfs(vector<int> &numbers, int &target, int sum, int depth) {
    if (depth >= numbers.size()) {
        if (sum == target) 
            count++;
        
        return;
    }
    
    dfs(numbers, target, sum + numbers[depth], depth + 1);
    dfs(numbers, target, sum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, numbers[0], 1);
    dfs(numbers, target, -numbers[0], 1);
    
    answer = count;
    
    return answer;
}
