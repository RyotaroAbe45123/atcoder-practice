#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    bool found = false;
    while (!found) {
        bool f = true;
        for (int i = 0; i < n; i++) {
            if (a[i] == ans) {
                ans++;
                f = false;
                break;
            }   
        }
        if (f) found = true;
    }
    cout << ans << endl;
    return 0;
}