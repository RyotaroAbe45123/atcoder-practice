#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> G(n, 0);
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        a--;
        G[a]++;
    }
    for (int i = 0; i < n; i++) {
        cout << G[i] << endl;
    }
    return 0;
}