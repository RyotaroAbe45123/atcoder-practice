#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> vol(n+2, false);
    vector<long long> a(n);

    int sold = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= vol.size()) sold++;
        else if (vol[a[i]]) sold++;
        else vol[a[i]] = true;
    }

    int L = 1;
    int R = n + 1;
    while (true) {
        while (vol[L]) {
            L++;
        }
        while (R != 0 && !vol[R]) {
            R--;
        }
        if (sold >= 2) {
            sold -= 2;
            vol[L] = true;
        }
        else {
            if (L >= R) break;
            vol[R] = false;
            sold++;
        }
    }

    cout << L - 1 << endl;
    return 0;
}