#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];
    if (n == k) {
        cout << "Yes" << endl;
        return 0;
    }
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma = max(ma, a[i]);
    }
    for (int i = 0; i < k; i++) {
        if (a[b[i]-1] == ma) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}