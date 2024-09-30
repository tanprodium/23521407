#include<bits/stdc++.h>

using namespace std;

struct Phanso {
    int tu, mau;
    Phanso() {}
    Phanso(int _tu, int _mau): tu(_tu), mau(_mau) {}
};

int gcd(int x, int y) {
    while (y) {
        int r = x % y;
        x = y;
        y = r;
    }
    return (x);
}

void Rutgon(Phanso &x) {
    int ucln = gcd(x.tu, x.mau);
    // rut gon nhan tu chung
    x.tu /= ucln;
    x.mau /= ucln;
    if (x.mau < 0) {
        x.tu *= -1;
        x.mau *= -1;
    }
}

int main() {
    Phanso a;
    cout << "Hay nhap vao phan so: ";
    cin >> a.tu >> a.mau;
    if (a.mau == 0) {
        cout << "Mau so khong the bang 0";
        return 0;
    }
    Rutgon(a);
    cout << "Phan so toi gian: " << a.tu << '/' << a.mau;
    return 0;
}
