#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < s.size(); j++) {
            s[j] = char('a' + ((s[j] - 'a') + i) % 26);
        }
        if (s == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}