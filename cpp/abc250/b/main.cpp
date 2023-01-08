#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<string> tiles(n, string(n, '-'));
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                if (j % 2 == 0) tiles[i][j] = '.';
                else tiles[i][j] = '#';
            }
        }
        else {
            for (int j = 0; j < n; j++) {
                if (j % 2 == 0) tiles[i][j] = '#';
                else tiles[i][j] = '.';
            }
        }
    }

    vector<string> s(a*n, string(b*n, '-'));
    for (int i = 0; i < a * n; i++) {
        for (int j = 0; j < b * n; j++) {
            s[i][j] = tiles[i/a][j/b];
        }
    }
    for (int i = 0; i < a * n; i++) {
        cout << s[i] << endl;
    }
    return 0;
}