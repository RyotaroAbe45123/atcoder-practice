#include <bits/stdc++.h>
using namespace std;

vector<int> isPassed(101010, false);
vector<vector<int>> graph(101010);


bool dfs(const int current, const int before) {
    isPassed[current] = true;
    for(int i = 0; i < graph[current].size(); i++) {
        if(graph[current][i] == before) {
            // 前のノードに戻る場合
            continue;
        }
        if(isPassed[ graph[current][i] ]) {
            // 次に行くノードがかこに通ったことがある場合
            // for (int k = 0; k < (int)graph[current].size(); k++) cout << graph[current][k] << " ";
            // cout << endl;
            remove(graph[current].begin(), graph[current].end(), graph[current][i]-1);
            // for (int k = 0; k < (int)graph[current].size(); k++) cout << graph[current][k] << " ";
            // cout << endl;

            remove(graph[graph[current][i]-1].begin(), graph[graph[current][i]-1].end(), current-1);
            return true;
        }
        dfs(graph[current][i], current);
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        bool hasLoop = dfs(0, -1);
        // cout << (bool)hasLoop << endl;
        if (!hasLoop) {
            cout << ans << endl;
            return 0;
        }
        else {
            ans++;
            fill(isPassed.begin(), isPassed.end(), false);
        }
    }
    // while (hasLoop) {
    //     ans++;
    //     hasLoop = dfs(0, -1);
    // }
    cout << ans << endl;
    return 0;
}