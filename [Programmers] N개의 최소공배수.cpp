#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b){
    int c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int LCM(int a, int b){
    return a * b / GCD(a, b);
}
int solution(vector<int> arr) {
    int answer = 0;
    int lcm = 1;
    for(int i = 0; i < arr.size(); i++){
        lcm = LCM(lcm, arr[i]);
    }
    answer = lcm;
    return answer;
}
