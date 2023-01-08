#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool big = false, small = false;
    for (int i = 0; i < (int)s.size(); i++) {
        if (isupper(s[i])) big = true;
        else small = true;
    }
    bool diff = true;
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i + 1; j < (int)s.size(); j++) {
            if (s[i] == s[j]) diff = false;
        }
    }
    if (big && small && diff) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}