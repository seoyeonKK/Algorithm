#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool desc(int a, int b) { return a > b; }

int solution(vector<int> citations) {
    int idx = 0;
    
    sort(citations.begin(), citations.end(), desc);
    
    while(idx < citations.size()) {
        if (citations[idx] <= idx) break;
        idx++;
    }
        
    return idx;
}
