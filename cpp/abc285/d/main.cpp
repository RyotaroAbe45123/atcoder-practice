#include <bits/stdc++.h>
using namespace std;

vector<bool> done;

bool can(int x, vector<string> s, vector<string> t) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (x == i) continue;
        if (t[x] == s[i]) {
            return false;
        }
    }
    return true;
}

void do(int x, vector<string> s, vector<string> t) {
    for (int i = 0; i < (int)s.size(); i++) {
        if (can(i, s, t)) {
            done[i] = true;
        }
        else continue;
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<string> t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
        done[i] = false;
    }

    int ans;
    for (int i = 0; i < n; i++) {
        
    }
    cout << "Yes" << endl;
    return 0;
}