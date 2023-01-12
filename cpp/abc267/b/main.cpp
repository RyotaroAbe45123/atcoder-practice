#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> s(10);
    for (int i = 0; i < 10; i++) cin >> s[i];
    if (s[0] == '1') {
        cout << "No" << endl;
        return 0;
    }
    else {
        vector<bool> column(7, false);
        column[0] = (s[6] == '1');
        column[1] = (s[3] == '1');
        column[2] = (s[1] == '1' || s[7] == '1');
        column[3] = (s[4] == '1');
        column[4] = (s[2] == '1' || s[8] == '1');
        column[5] = (s[5] == '1');
        column[6] = (s[9] == '1');
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < i; j++) {
                if (column[i] && column[j]) {
                    for (int k = j + 1; k < i; k++) {
                        if (!column[k]) {
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}