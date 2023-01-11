#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n);
    vector<int> b(n);
    vector<bool> c(n, false);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < x; i++) {
        int m = -1;
        int idx;
        for (int j = 0; j < n; j++) {
            if (a[j] > m && !c[j]) {
                m = a[j];
                idx = j;
            }
        }
        c[idx] = true;
    }

    for (int i = 0; i < y; i++) {
        int m = -1;
        int idx;
        for (int j = 0; j < n; j++) {
            if (b[j] > m && !c[j]) {
                m = b[j];
                idx = j;
            }
        }
        c[idx] = true;
    }

    for (int i = 0; i < z; i++) {
        int m = -1;
        int idx;
        for (int j = 0; j < n; j++) {
            if (a[j] + b[j] > m && !c[j]) {
                m = a[j] + b[j];
                idx = j;
            }
        }
        c[idx] = true;
    }

    for (int i = 0; i < n; i++) {
        if (c[i]) {
            cout << i+1 << endl;
        }
    }
    return 0;
}