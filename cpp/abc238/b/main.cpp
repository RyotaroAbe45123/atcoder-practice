#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> cut(360, false);
    cut[0] = true;
    int p = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        p += a; p %= 360;
        cut[p] = true;
    }
    int ans = 0, cur = 0;
    for (int i = 0; i <= 360; i++) {
        if (cut[i%360]) {
            ans = max(ans, cur);
            cur = 0;
        }
        cur++;
    }
    cout << ans << endl;
}
