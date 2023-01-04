#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int ans = 3;
    if (s[0] == s[1] && s[1] == s[2]) ans = 1;
    else if (s[0] != s[1] && s[1] != s[2] && s[2] != s[0]) ans = 6;
    cout << ans << endl;
    return 0;
}