#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int a[202];
    for (int i = 1; i <= k; i++) cin >> a[i];
    a[k+1] = n + 1;

    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        if (a[l] + 1 < a[l+1]) a[l]++;
    }
    for (int i = 1; i <= k; i++) cout << a[i] << (i == k ? "\n" : " ");
    return 0;
}