#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h[100010];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int pos = 0;
    while (pos + 1 < n && h[pos] < h[pos+1]) {
        pos++;
    }
    cout << h[pos] << endl;
}