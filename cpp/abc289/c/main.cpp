#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for (auto& x : a[i]) cin >> x;
      }
    return 0;
}