#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string msg = "";
    char cmd(16);
    char word(16);
    int count = 0;
    stack<char> left, right;

    cin >> msg;
    cin >> count;

    for (int i = 0; i < msg.length(); i++) {
        left.push(msg[i]);
    }

    for (int i = 0; i < count; i++) {

        cin >> cmd;
        switch(cmd) {
            case 'L' :
                if(!left.empty()) {
                    right.push(left.top());
                    left.pop();
                }
                break;

            case 'P' :
                cin >> word;
                left.push(word);
                break;

            case 'B' :
                if(!left.empty()) {
                    left.pop();
                }
                break;

            case 'D' :
                if(!right.empty()) {
                    left.push(right.top());
                    right.pop();
                }
                break;

            default:
                break;

        }
    }

    while(!left.empty()) {
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()) {
        cout << right.top();
        right.pop();
    }

    cout << endl;
    return 0;
}
