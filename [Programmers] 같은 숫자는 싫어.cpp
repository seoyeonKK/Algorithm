#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    // 중복 제거 함수
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i = 0; i < arr.size(); i++) 
        answer.push_back(arr[i]);
    
    return answer;
}
