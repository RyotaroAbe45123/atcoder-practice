#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

int main() {
    long long n;
    cin >> n;
    n %= mod;
    if (n < 0) n += mod;
    cout << n << endl;
    return 0;
}