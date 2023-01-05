#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < 4 * n - 1; i++) {
        int ai;
        cin >> ai;
        a[ai-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != 4) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}