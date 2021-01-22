#include <iostream>
#include <algorithm>
using namespace std;

int main () {
    int width, height;
    cin >> height >> width;

    if (height == 1) {
        cout << 1 << endl;
    }
    else if (height == 2) {
        cout << min(4, (width+1)/2);
    }
    else if (height > 2) {
        if (width >= 7) {
            cout << width-2 << endl;
        }
        else if (width < 7) {
            cout << min(4, width) << endl;
        }
    }
    
    return 0;
}
