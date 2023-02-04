#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<pair<int, int>> E;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E.insert({ a, b });
        E.insert({ b, a });
    }

    string ans = "IMPOSSIBLE";
    for (int i = 1; i < n-1; i++) {
        if (E.count({ 0, i }) && E.count({ i, n-1})) ans = "POSSIBLE";
    }
    cout << ans << endl;
    return 0;
}