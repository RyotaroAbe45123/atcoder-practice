#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<bool> cut(360, false);
    cut[0] = true;
    int current = 0;
    for (int i = 0; i < N; i++) {
        current = (current + a[i]) % 360;
        a[current] = true;
    }
    int ans = 0;
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (a[i]) {
            ans = max(ans, c);
            c = 0;
        }
        else {
            c++;
        }
    }
    cout << c << endl;
}