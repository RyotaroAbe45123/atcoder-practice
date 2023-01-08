#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    bool all_ok = true;
    for (int i = 0; i < n; i++) {
        bool each_ok = false;
        string a[2] = {s[i], t[i]};
        for (string ai : a) {
            bool s_ok = true;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (s[j] == ai || t[j] == ai) s_ok = false;
                }
            }
            if (s_ok) each_ok = true;
        }
        if (!each_ok) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}