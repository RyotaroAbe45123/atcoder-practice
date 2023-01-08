#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long w;
    cin >> n >> w;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> f(w+1, false);
    for (int i = 0; i < n; i++) {
        if (a[i] <= w) f[a[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long s = a[i] + a[j];
            if (s <= w) f[s] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j +1; k < n; k++) {
                long long s = a[i] + a[j] + a[k];
                if (s <= w) f[s] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= w; i++) {
        if (f[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}