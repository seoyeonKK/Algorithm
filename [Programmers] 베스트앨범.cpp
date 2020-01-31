#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool comp1(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

bool comp2(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, string>> p;
    vector<pair<int, int>> play;
    map<string, int> m;
    
    // <장르, 재생 수> map
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
    }
    
    // m을 pair<재생 수, 장르> vector에 삽입 -> 재생 수 기준 sorting하기 위해
    for (auto i : m) {
        p.push_back({ i.second, i.first });
    }
    
    // 장르 재생 수 기준 sorting (desc)
    sort(p.begin(), p.end(), comp1);
    
    // p vector 순서 대로 해당 장르에 맞는 plays와 idx를 pair<재생 수, 인덱스> vector에 삽입  
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == p[i].second) {
                play.push_back({ plays[j], j });
            }
        }
        
        // 음원 재생 수 기준 sorting (desc)
        sort(play.begin(), play.end(), comp2);
        
        // answer에 2개씩 삽입
        for (int k = 0; k < 2; k++) {
            if (k == play.size()) break; // 음원이 1개일 때 예외 처리
            answer.push_back(play[k].second);
        }
        
        play.clear();
    }
    
    return answer;
}
