#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    if (N < 10) {
        cout << "AGC00" << to_string(N) << endl;
    }
    else if (N < 42) {
        cout << "AGC0" << to_string(N) << endl;
    }
    else {
        cout << "AGC0" << to_string(N+1) << endl;
    }
    return 0;
}