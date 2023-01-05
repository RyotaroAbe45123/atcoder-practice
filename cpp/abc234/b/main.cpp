#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int X = x[i] - x[j], Y = y[i] - y[j];
            ans = max(ans, sqrt(X * X + Y * Y));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
}