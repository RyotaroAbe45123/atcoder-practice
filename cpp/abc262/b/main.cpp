#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> uv(n, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        uv[u][v] = uv[v][u] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (uv[i][j] && uv[j][k] && uv[k][i]) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}