#include<bits/stdc++.h>

using namespace std;

int main() {
    long double x;
    cin >> x;
    long double sinx = 0.0;
    long double add = 1;
    for (int i = 1; i <= 10000000; i++) {
        add = add * x / i;
        // x ^ i / i!
        if (i % 4 == 1)
            sinx += add;
        else if (i % 4 == 3) {
            sinx -= add;
        }
    }
    cout << fixed << setprecision(6) << sinx;
    return 0;
}
