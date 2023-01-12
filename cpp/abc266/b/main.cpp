#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < 998244353; i++) {
        if ((n - i) % 998244353 == 0) {
            cout << i << endl;
            return 0;
        }
    }
}