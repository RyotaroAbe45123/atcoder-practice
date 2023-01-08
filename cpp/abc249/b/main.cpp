#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a(2, 0);
    vector<int> b(60, 0);

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] - 'A' < 26) a[0]++;
        else a[1]++;
        b[(int)(s[i] - 'A')]++;
    }
    bool ok = true;
    for (int i = 0; i < 2; i++) {
        if (a[i] == 0) ok = false;
    }
    for (int i = 0; i < 60; i++) {
        if (b[i] > 1) ok = false;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
    
}