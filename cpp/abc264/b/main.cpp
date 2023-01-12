#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    if (r % 2 == 0) {
        if (r <= c || c <= 15-r) {
            cout << "white" << endl;
        }
        else {
            cout << (c % 2 == 0 ? "white" : "black") << endl;
        }
    }
    else {
        if (r <= c || c <= 15-r) {
            cout << "black" << endl;
        }
        else {
            cout << (c % 2 == 0 ? "black" : "white") << endl;
        }
    }
    return 0;
}