#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    int a[n][n];
    vector<int> c(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> l[i];
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (l[i] == l[j]) {
                bool same = true;
                for (int k = 0; k < l[i]; k++) {
                    if (a[i][k] != a[j][k]) {
                        same = false;
                        break;
                    }
                }
                if (same) found = true;
            }
        }
        if (!found) c[i]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += c[i];
    cout << ans << endl;
    return 0;
}