#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> G(n, 0);
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        G[a]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << G[i] << endl;
    }
    return 0;
}