#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    vector<int> b(4, 0);
    for (int i = 0; i < n; i++) {
        vector<int> nb(4, 0);
        b[0] = 1;
        for (int j = 0; j < 4; j++) {
            if (b[j] == 1) {
                int x = j + a[i];
                if (x > 3) {
                    ans++;
                }
                else {
                    nb[x] = 1;
                }
            }
        }
        b = nb;
    }
    cout << ans << endl;
    return 0;
}