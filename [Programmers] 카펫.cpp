#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int block = 0;
    
    block = brown + red;
    
    for (int i = 2; i <= sqrt(block); i++) {
        int w = 0;
        int h = 0;
        
        if(0 == (block % i) && brown == ((i + (block/i)) * 2 - 4)) {
            if(i >= (block/i)){
                answer.push_back(i);
                answer.push_back(block/i);
            }
            else if(i < (block/i)){
                answer.push_back(block/i);
                answer.push_back(i);
            }
        }        
    }
    return answer;
}
