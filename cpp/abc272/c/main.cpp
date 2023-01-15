#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long x = a[i] + a[j];
            if (x % 2 == 0) {
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}