#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(const pair <int, int> &a, const pair <int, int> &b){
  if(a.second == b.second)
    return a.first < b.first;
  else return a.second < b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int start = 0; 
    int time = 0;
    vector <pair <int, int>> disks;
    
    for (int i = 0; i < jobs.size(); i++) 
        disks.push_back(make_pair(jobs[i][0], jobs[i][1]));
    
    sort(disks.begin(), disks.end(), desc);
    
    while (!disks.empty()) {
        for (int i = 0; i < disks.size(); i++) {
            if (disks[i].first <= start) {
                start += disks[i].second;
                time += start - disks[i].first;
                disks.erase(disks.begin() + i);
                break;
            } 
            if (i == disks.size()-1) start++;
        }
    }
 
    answer = time / jobs.size();
 
    return answer;
}
