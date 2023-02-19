#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (i != s.size() -1 && s[i] == 'n' && s[i+1] == 'a') {
            cout << "nya";
            i++;
        } else {
            cout << s[i];
        }
    }
    return 0;
}