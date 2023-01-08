#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    int x_1 = -1, y_1 = -1;
    int x_2 = -1, y_2 = -1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'o') {
                if (x_1 < 0) x_1 = i, y_1 = j;
                else x_2 = i, y_2 = j;
            }
        }
    }
    int d = abs(x_2 - x_1) + abs(y_2 - y_1);
    cout << d << endl;
    return 0;
}