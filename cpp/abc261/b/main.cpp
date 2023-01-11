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
                if (a[i][j] != 'L') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
            else if (a[i][j] == 'L') {
                if (a[i][j] != 'W') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
            else if (a[i][j] == 'D') {
                if (a[i][j] != 'D') {
                    cout << "incorrect" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "correct" << endl;
    return 0;
}