#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (auto& x : a[i]) cin >> x;
    }
    int ans = 0;
    for (int b = 0; b < (1 << m); b++) {
        set<int> s;
        for (int i = 0; i < m; i++) {
        if ((b >> i) & 1) {
            for (auto& x : a[i]) s.insert(x);
        }
        }
        ans += (int)s.size() == n;
    }
    cout << ans << "\n";
    return 0;
}