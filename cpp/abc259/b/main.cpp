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
    double theta = atan2(b, a);
    theta += d * acos(-1.0) / 180.0;

    double aa = r * cos(theta);
    double bb = r * sin(theta);
    cout << fixed << setprecision(20) << aa << " " << bb << endl;
    return 0;
}