#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool solved = false;
        for (int a = 1; a <= s[i]; a++) {
            for (int b = 1; b <= s[i]; b++) {
                int x = 4*a*b + 3*a + 3*b;
                if (x == s[i]) {
                    solved = true;
                    break;
                }
            }
        }
        if (!solved) ans++;
    }
    cout << ans << endl;
    return 0;
}