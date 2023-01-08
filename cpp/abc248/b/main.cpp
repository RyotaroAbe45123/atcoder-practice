#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    if (a >= b) {
        cout << 0 << endl;
        return 0;
    }
    long long total = a;
    long long ans = 0;
    while (total < b) {
        total *= k;
        ans++;
    }
    cout << ans << endl;
    return 0;
}