#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int div = 1;
    
    sort(arr.begin(), arr.end());
    
    for (int i = 0; i < arr.size(); i++) {
        answer *= arr[i];
    }
    
    for (int i = 0; i < arr.size()-1; i++) {
        for (int j = i+1; j < arr.size(); j++) { 
            if (arr[j]%arr[i] == 0) {
                div *= arr[i];
            }
        }
    }
    
    answer /= div;
    
    return answer;
}
