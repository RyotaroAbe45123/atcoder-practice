#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;
    cout << (x / 10) - (x % 10 < 0) << endl;
}