#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    long long pow = 1;
    for (int i = s.size()-1; i >= 0; i--) {
        ans += (s[i] - 'A' + 1) * pow;
        pow *= 26;
    }
    cout << ans << endl;
    return 0;
}
