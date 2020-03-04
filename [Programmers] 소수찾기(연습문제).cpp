#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> tmp(n+1, true);
    
    for (int i = 2; i < n+1; i++) {
        if (tmp[i] == true) {
            for (int j = 2; i*j < n+1; j++) tmp[i*j] = false;
            answer++;
        }
    }

    return answer;
}

