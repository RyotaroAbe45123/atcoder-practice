#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;
        if (h > ans) {
            ans = h;
        }
        else {
            break;
        }
    }
    cout << ans << endl;
}