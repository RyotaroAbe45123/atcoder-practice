#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (i != n -1 && s[i] == 'n' && s[i+1] == 'a') {
            cout << "nya";
            i++;
        } else {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}