#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<string> s(a*n, string(b*n, '-'));
    for (int i = 0; i < a * n; i++) {
        for (int j = 0; j < b * n; j++) {
            if ((i/a)%2 == 0) {
                if ((j/b)%2 == 0) s[i][j]= '.';
                else s[i][j] = '#';
            }
            else {
                if ((j/b)%2 == 0) s[i][j]= '#';
                else s[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < a * n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}