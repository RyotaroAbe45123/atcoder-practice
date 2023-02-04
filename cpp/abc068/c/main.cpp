#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    string ans = "IMPOSSIBLE";
    for (auto i: G[0]) {
        for (int j = 0; j < (int)G[i].size(); j++) {
            if (G[i][j] == n-1) {
                ans = "POSSIBLE";
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}