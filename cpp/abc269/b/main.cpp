#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(10);
    for (int i = 0; i < 10; i++) cin >> s[i];

    int a = 1e9, b = -1e9;
    int c = 1e9, d = -1e9;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (s[i][j] == '#') {
                a = min(a, i+1);
                b = max(b, i+1);
                c = min(c, j+1);
                d = max(d, j+1);
            }
        }
    }
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    return 0;
}