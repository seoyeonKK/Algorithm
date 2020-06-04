#include <iostream>
#include <string>
#define MAX 1000001
using namespace std;


string s, bomb;
char result[MAX];

int main(void) {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> bomb;

    int idx = 0;

    for (int i = 0; i < s.length(); i++) {

        // 일단 추가
        result[idx++] = s[i];

        // 폭탄으로 추정되는 부분 문자열 발견
        if (result[idx - 1] == bomb[bomb.length() - 1]) {

            // 기저 사례
            if (idx - bomb.length() < 0)
                continue;

            // 폭탄 여부 파악
            bool detected = true;

            for(int j=0; j < bomb.length(); j++)
                if (result[idx - j - 1] != bomb[bomb.length() - j - 1]) {
                    detected = false;
                    break;
                }

            // 폭탄 제거
            if (detected)
                idx -= bomb.length();
        }
    }

    if (!idx)
        cout << "FRULA" << endl;

    else {
        for (int i = 0; i < idx; i++)
            cout << result[i];
        cout << endl;
    }

    return 0;

}
