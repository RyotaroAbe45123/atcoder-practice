#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int ma = 0;
    string name;
    for (int i = 0; i < n; i++) {
        string k = s[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == k) {
                cnt++;
            }
        }
        if (cnt > ma) {
            ma = cnt;
            name = k;
        }
    }
    cout << name << endl;
}