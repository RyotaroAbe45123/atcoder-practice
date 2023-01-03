#include <bits/stdc++.h>
using namespace std;

int main() {
    int abc;
    cin >> abc;
    int a = abc / 100;
    int b = (abc % 100) / 10;
    int c = abc % 10;
    int bca = b * 100 + c * 10 + a;
    int cab = c * 100 + a * 10 + b;
    cout << abc + bca + cab << endl;
}