#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long x = (long long)1 << 31;
    if ((-x <= n) && (n < x)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}