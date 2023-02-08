#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2000;

vector<vector<int>> G;
bool tmp[MAX_N];
void dfs(int v) {
    if (tmp[v]) return;
    tmp[v] = true;
    for (auto vv : G[v]) dfs(vv);
}

int main() {
    int n, m;
    cin >> n >> m;
    G.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[j] = false;
        }
        dfs(i);
        for (int j = 0; j < n; j++) {
            if (tmp[j]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}