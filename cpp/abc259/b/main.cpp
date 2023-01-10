#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, d;
    cin >> a >> b >> d;
    if (a == 0 && b == 0) {
        cout << fixed << setprecision(20) << 0.0 << " " << 0.0 << endl;
        return 0;
    }
    double r = sqrt(a*a + b*b);
    double theta = acos(a / r) * 180;
    cout << theta << endl;

    double aa = r * cos(d + theta);
    double bb = r * sin(d + theta);
    cout << fixed << setprecision(20) << aa << " " << bb << endl;
    return 0;
}