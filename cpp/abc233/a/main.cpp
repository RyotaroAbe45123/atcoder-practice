#include <bits/stdc++.h>
using namespace std;

int ceil(int a, int b) {
    return (a + b -1) / b;
}

int main() {
    int x, y;
    cin >> x >> y;
    if (x >= y) {
        cout << '0' << endl;
        return 0;
    }
    else {
        cout << ceil(y - x, 10) << endl;
    }
}