#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<bool> used(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        used[i] = false;
    }
    for (int i = 0; i < m; i++) {
        long long b;
        cin >> b;
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (b == a[j] && !used[j]) {
                found = true;
                used[j] = true;
            }
        }
        if (!found) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}