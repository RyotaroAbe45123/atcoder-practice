#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) ok = false;
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}