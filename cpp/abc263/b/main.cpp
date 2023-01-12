#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) cin >> p[i];
    int ans = 0;
    int idx = n;
    while (idx > 1) {
        idx = p[idx-1];
        ans++;
    }
    cout << ans << endl;
    return 0;
}