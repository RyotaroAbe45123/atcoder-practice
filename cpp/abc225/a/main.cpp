#include <bits/stdc++.h>
using namespace std;

int main() {
    char a, b, c;
    cin >> a >> b >> c;
    if (a != b && a != c && b != c) {
        cout << 6 << endl;
    }
    else if (a == b && a == c) {
        cout << 1 << endl;
    }
    else {
        cout << 3 << endl;
    }
    return 0;
}