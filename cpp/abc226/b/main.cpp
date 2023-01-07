#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> v(l);
        for (int j = 0; j < l; j++) cin >> v[j];
        st.insert(v);
    }
    cout << st.size() << endl;
    return 0;
}