#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int xy[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> xy[i][j];
        }
    }
    double res[n];
    for (int i = 0; i < n; i++) {
        double m = 0;
        for (int j = i+1; j < n; j++) {
            double d = pow(xy[i][0] - xy[j][0], 2) + pow(xy[i][1] - xy[j][1], 2);
            d = sqrt(d);
            m = max(m, d);
        }
        res[i] = m;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, res[i]);
    }
    cout << fixed << setprecision(10) << ans << endl;
}