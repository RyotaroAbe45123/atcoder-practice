#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        if (i < p-1) {
            cout << a[i] << endl;
        }
        else if (p-1 < i < q-1) {
            cout << a[i-p+r-1] << " ";
        }
        else if (r-1 < i < s-1) {
            cout << a[i-r+p-1] << " ";
        }
        else {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    return 0;
}