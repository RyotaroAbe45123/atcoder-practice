#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a = N / 16, b = N % 16;
    if (a < 10) {
        cout << a;
    }
    else {
        cout << (char)('A' + a - 10);
    }
    if (b < 10) {
        cout << b << endl;
    }
    else {
        cout << (char)('A' + b - 10) << endl;
    }
    return 0;
}
