#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> dp(n);
    for (int i = 1; i < n; i++) {
        dp[i] = dp[p[i]] + 1;
    }
    cout << dp[n-1] << endl;
    return 0;
}