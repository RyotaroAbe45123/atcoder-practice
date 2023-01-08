#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<long long> d(n, 1e15);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (i != a[j]-1) {
                long long X = (x[i] - x[a[j]-1]) * (x[i] - x[a[j]-1]);
                long long Y = (y[i] - y[a[j]-1]) * (y[i] - y[a[j]-1]);
                d[i] = min(d[i], X+Y);
            }
            else d[i] = 0;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, d[i]);
    }
    cout << fixed << setprecision(15) << (double)sqrt(ans) << endl;
    return 0;
}

