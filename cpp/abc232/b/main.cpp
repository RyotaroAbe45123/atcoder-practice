#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    for (int k = 0; k < 26; k++) {
        string s2 = s;
        for (int j = 0; j < (int)s.size(); j++) {
            s2[j] = ((s2[j] - 'a') + k) % 26 + 'a';
        }
        if (s2 == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}