#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n-1; i >= 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            long long x = a[i] + a[j];
            if (x % 2 == 0) {
                cout << x << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}