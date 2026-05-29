#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, t, x;
    cin >> s >> t >> x;
    if (t > s) {
        cout << (s <= x && x < t ? "Yes": "No") << endl;
    }
    else {
        cout << (x < t || s <= x ? "Yes": "No") << endl;
    }
    return 0;
}