#include <bits/stdc++.h>
using namespace std;

int f(int x) {
    return x * x + 2 * x + 3;
}

int main() {
    int t;
    cin >> t;
    long long res;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
}