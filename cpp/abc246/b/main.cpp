#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    double xy = sqrt(a*a + b*b);
    double x = a / xy, y = b / xy;
    cout << fixed << setprecision(12) << x << " " << y << endl;
    return 0;
}