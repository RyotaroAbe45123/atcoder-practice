#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;

    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, false);
    dfs(G, 0);
    return 0;
}