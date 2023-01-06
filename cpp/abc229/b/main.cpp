#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    while (a > 0 && b > 0) {
        int x = a % 10 + b % 10;
        if (x > 9) {
            cout << "Hard" << endl;
            return 0;
        }
        a /= 10;
        b /= 10;
    }
    cout << "Easy" << endl;
    return 0;
}