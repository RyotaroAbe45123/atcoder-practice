#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> x(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int j = 0; j < k; j++) {
            int l;
            cin >> l;
            l--;
            a[j] = l;
        }
        for (int j = 0; j < a.size() - 1; j++) {
            for (int k = j + 1; k < a.size(); k++) {
                x[a[j]][a[k]] = true;
            }
        }
    }
    bool ans = true;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans &= x[i][j];
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}