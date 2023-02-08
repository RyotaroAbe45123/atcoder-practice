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
    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return 0;
}