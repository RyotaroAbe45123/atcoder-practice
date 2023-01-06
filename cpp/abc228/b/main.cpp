#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<bool> known(n, false);
    for (int i = 0; i < n; i++) cin >> a[i];
    int idx = x;
    known[idx-1] = true;
    while (true) {
        if (known[a[idx-1]-1]) {
            break;
        }
        else {
            known[a[idx-1]-1] = true;
            idx = a[idx-1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (known[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}