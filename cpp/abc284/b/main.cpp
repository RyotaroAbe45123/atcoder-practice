#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            long long ai;
            cin >> ai;
            if (ai % 2 == 1) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}