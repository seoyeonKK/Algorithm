#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    double x, y, c;
    cin >> x >> y >> c;

    double left = 0;
    double right = min(x, y);

    for (int k = 0; k < 10000; k++) {
        double mid = (left + right) / 2.0;
        double d = mid;
        double h1 = sqrt(x * x - d * d);
        double h2 = sqrt(y * y - d * d);
        double h = (h1 * h2) / (h1 + h2);

        if (h > c) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    printf("%.3lf\n", left);

return 0;
}
