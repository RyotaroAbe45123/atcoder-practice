#include <bits/stdc++.h>
using namespace std;

long long f(long long x) {
    return pow(x, 2) + (2 * x) + 3;
}

int main() {
    int t;
    cin >> t;
    long long res;
    res = f(f(f(t) + t) + f(f(t)));
    cout << res << endl;
}