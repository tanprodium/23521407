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
    Phanso a, b;
    cout << "Hay nhap vao phan so thu nhat: "; cin >> a.tu >> a.mau;
    cout << "Hay nhap vao phan so thu hai: "; cin >> b.tu >> b.mau;
    if (a.mau == 0 || b.mau == 0) {
        cout << "Mau so khong the bang 0";
        return 0;
    }
    // a/b > x/y <=> a * y > b * x
    int u = a.tu * b.mau;
    int v = a.mau * b.tu;
    if (u > v) {
        cout << "Phan so a lon hon phan so b";
    } else {
        if (u < v) {
            cout << "Phan so a nho hon phan so b";
        } else {
            cout << "Phan so a bang phan so b";
        }
    }
    return 0;
}
