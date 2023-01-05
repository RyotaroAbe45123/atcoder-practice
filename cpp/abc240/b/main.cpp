#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N);
    int ans = 0;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (a[i] == a[j]) {
                found = true;
            }
        }
        if (!found) ans++;
    }
    cout << ans << endl;
}