#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int block = 0;
    
    block = brown + yellow;
    
    for (int h = 3; h <= sqrt(block); h++) {
       if (block % h == 0) {
            int w = block / h;
            if ((w - 2) * (h - 2) == yellow) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}
