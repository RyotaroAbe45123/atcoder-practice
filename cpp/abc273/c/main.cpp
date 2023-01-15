#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    };
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        m[a[i]]++;
    };

    for (auto it = m.rbegin(); it != m.rend(); it++) {
        cout << it->second << endl;
    }
    for (int i = 0; i < n - m.size(); i++) {
        cout << "0" << endl;
    }
    return 0;
}