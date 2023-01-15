#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<bool> x(n-1, false);
    for (int i = 0; i < n-1; i++) {
        bool f = true;
        for (int j = 1; j < n; j++) {
            if (s[i-1] == s[i+j-1]) f = false;
        }
        if (f) x[i] = true;

    }
    for (int i = 1; i < n; i++) {
        int ans = 0;
        for (int l = n-i; l > 0; l--) {
            bool f = true;
            for (int k = 1; k <= l; k++) {
                if (s[k-1] == s[k+i-1]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ans = l;
                break;
            };
        }
        cout << ans << endl;
    }
    return 0;
}