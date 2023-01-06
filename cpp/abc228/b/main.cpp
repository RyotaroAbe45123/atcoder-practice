#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[100001];
    bool b[100001];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int idx = x;
    do {
        b[idx] = true;
        idx = a[idx];
    }
    while (!b[idx]);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}