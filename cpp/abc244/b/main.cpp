#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0;
    int x = 0, y = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'R') d++;
        else {
            if (d % 4 == 0) x++;
            else if (d % 4 == 1) y--;
            else if (d % 4 == 2) x--;
            else if (d % 4 == 3) y++;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}