#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    long long t;
    cin >> n >> m >> t;
    vector<long long> a(n);
    vector<long long> bonus(n, 0);

    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int x;
        long long y;
        cin >> x >> y;
        bonus[x] = y;
    }

    for (int i = 1; i < n; i++) {
        if (t <= a[i]) {
            cout << "No" << endl;
            return 0;
        }
        t -= a[i];
        t += bonus[i+1];
    }
    cout << "Yes" << endl;
    return 0;
}