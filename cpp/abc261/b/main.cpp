#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (a[i][j] == 'W') {
                if (a[j][i] != 'L') {
                    cout << "incorrect" << endl;
                    return 0;
                }
                else continue;
            }
            else if (a[i][j] == 'L') {
                if (a[j][i] != 'W') {
                    cout << "incorrect" << endl;
                    return 0;
                }
                else continue;
            }
            else if (a[i][j] == 'D') {
                if (a[j][i] != 'D') {
                    cout << "incorrect" << endl;
                    return 0;
                }
                else continue;
            }
        }
    }
    cout << "correct" << endl;
    return 0;
}