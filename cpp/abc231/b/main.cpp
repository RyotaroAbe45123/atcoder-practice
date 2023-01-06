#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<string, int> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        m[s[i]]++;
    }
    int ans = 0;
    string name;
    for (int i = 0; i < n; i++) {
        if (m[s[i]] > ans) {
            ans = m[s[i]];
            name = s[i];
        }
    }
    cout << name << endl;
}