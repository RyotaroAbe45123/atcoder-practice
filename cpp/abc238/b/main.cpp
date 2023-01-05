#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> cut(360, false);
    vector<int> a(n);
    cut[0] = true;
    int p = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p = (p + a[i]) % 360;
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
