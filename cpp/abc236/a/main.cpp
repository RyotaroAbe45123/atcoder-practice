#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int a, b;
    cin >> s >> a >> b;
    for (int i = 0; i < s.size(); i++) {
        if (i == a - 1) {
            cout << s[b-1];
        }
        else if (i == b - 1) {
            cout << s[a-1];
        }
        else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}