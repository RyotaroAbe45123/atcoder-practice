#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(2);
    for (int i = 0; i < 2; i++) cin >> s[i];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (s[i][j] == '#') {
                if ((s[(i+1)%2][j] != '#') && (s[i][(j+1)%2] != '#')) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}