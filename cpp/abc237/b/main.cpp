#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    int a[h][w];
    int b[w][h];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            b[i][j] = a[j][i];
        }
    }
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            cout << b[i][j] << (j != h-1 ? " " : "\n");
        }
    }
}