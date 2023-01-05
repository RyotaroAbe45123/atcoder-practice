#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < 4 * n - 1; i++) {
        int ai;
        cin >> ai;
        a[ai] += 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 3) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}