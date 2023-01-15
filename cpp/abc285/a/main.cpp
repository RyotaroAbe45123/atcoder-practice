#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string ans = "No";
    if (a == 1 && (b == 2 || b == 3)) {
        ans = "Yes";
    }
    else if (a == 2 && (b == 4 || b == 5)) {
        ans = "Yes";
    }
    else if (a == 3 && (b == 6 || b == 7)) {
        ans = "Yes";
    }
    else if (a == 4 && (b == 8 || b == 9)) {
        ans = "Yes";
    }
    else if (a == 5 && (b == 10 || b == 11)) {
        ans = "Yes";
    }
    else if (a == 6 && (b == 12 || b == 13)) {
        ans = "Yes";
    }
    else if (a == 7 && (b == 14 || b == 15)) {
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}