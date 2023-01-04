#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x * y < 0) {
        cout << abs(x) << endl;
    }
    else {
        if (abs(z) > abs(y)) {
            cout << -1 << endl;
        }
        else {
            cout << abs(z) + abs(x - z) << endl;
        }
    }
    return 0;
}