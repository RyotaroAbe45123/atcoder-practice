#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> re(n+1);
    for (auto& x : a) re[x] = 1;
    vector<int> ans;
    for (int i = 1, j = 1; i <= n; i = j++) {
        while (re[j]) j++;
        for (int k = j; k >= i; k--) ans.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
    return 0;
}