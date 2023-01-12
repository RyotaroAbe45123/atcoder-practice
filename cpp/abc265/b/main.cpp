#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long t;
    cin >> n >> m >> t;
    vector<long long> a(n-1);
    vector<int> x(m);
    vector<long long> y(m);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
    }
    int idx = 0;
    string ans = "No";
    while (t > 0) {
        t -= a[idx];
        if (t > 0) idx++;
        else break;

        for (int j = 0; j < m; j++) {
            if (idx == x[j]-1) t += y[j];
        }
        if (idx == n - 1) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}