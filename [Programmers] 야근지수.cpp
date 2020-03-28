#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b){ return a > b; }

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    while(n) {
        sort(works.begin(), works.end(), desc);
        if (works.front() == 0) break;
        works.front()--;
        n--;
    }
    
    for (int i = 0; i < works.size(); i++) {
        answer += (works[i] * works[i]);
    }
    
    return answer;
}
