#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n -1; i >= 0; i--) {
        cout << s[i] << endl;
    }
    return 0;
}