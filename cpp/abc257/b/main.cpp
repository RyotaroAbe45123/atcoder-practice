#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        if (a[l-1] == n) continue;
        else if (l != k && a[l-1] == a[l] - 1) continue;
        else a[l-1]++;
    }
    for (int i = 0; i < k; i++) cout << a[i] << (i == k-1 ? "\n" : " ");
    return 0;
}