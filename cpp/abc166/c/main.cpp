#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<long long> H(n);
    vector<vector<int>> G(n);

    for (int i = 0; i < n; i++) cin >> H[i];

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (G[i].size() == 1) ans++;
        else {
            bool flag = true;
            for (int j = 0; j < G[i].size(); j++) {
                if (H[G[i][j]] > H[i]) flag = false;
            }
            if (!flag) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}