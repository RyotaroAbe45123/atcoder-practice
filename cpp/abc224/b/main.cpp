#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    long long a[h][w];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> a[i][j];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int k = i+1; k < h; k++) {
                for (int l = j+1; l < w; l++) {
                    if (a[i][j] + a[k][l] > a[k][j] + a[i][l]) {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}