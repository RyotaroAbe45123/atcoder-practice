#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int res = y - x;
    int r = (res / 10) + min(1, res % 10);
    cout << max(0, r) << endl;
}