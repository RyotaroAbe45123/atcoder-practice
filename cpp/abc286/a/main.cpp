#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (i < p) {
            cout << a[i] << " ";
        }
        else if (p <= i && i <= q) {
            cout << a[i-p+r] << " ";
        }
        else if (r <= i && i <= s) {
            cout << a[i-r+p] << " ";
        }
        else {
            cout << a[i] << (i == n ? "\n" : " ");
        }
    }
    cout << endl;
    return 0;
}