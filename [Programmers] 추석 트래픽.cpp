#include <string>
#include <vector>

using namespace std;

struct Timetable{
    int endtime;
    int process_time;
};

int solution(vector<string> lines) {
    string hour, min, sec, milisec;
    string proc_sec, proc_milisec;
    int answer = 0, temp_answer = 0;
    Timetable timetable[2000];
    for(int i = 0 ; i < lines.size() ; i++){
        hour = lines[i].substr(11,2);
        min = lines[i].substr(14,2);
        sec = lines[i].substr(17,2);
        milisec = lines[i].substr(20,3);
        timetable[i].endtime = (stoi(hour) * 1000 * 3600) + (stoi(min) * 60 * 1000) + (stoi(sec) * 1000) + stoi(milisec);

        proc_sec = lines[i].substr(24, 1);
        proc_milisec = "0";
        if(lines[i].length() > 26){
            proc_milisec = lines[i].substr(26, lines[0].length()-27);
        }
        timetable[i].process_time = (stoi(proc_sec) * 1000) + stoi(proc_milisec);
    }


    int fur_time, next_start_time;
    for(int i = 0 ; i < lines.size() ; i++){
        temp_answer = 0;
        fur_time = timetable[i].endtime + 1000;
        for(int j = i+1 ; j < lines.size() ; j++){
            next_start_time = timetable[j].endtime - timetable[j].process_time + 1;
            if(next_start_time < fur_time){
                temp_answer++;
                continue;
            }
            // break;
        }
        if(temp_answer > answer){
            answer = temp_answer;
        }
    }
    return answer+1;
}
