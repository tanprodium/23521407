#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pw(ll a, ll mu, ll Mod) { // a^mu % Mod
    ll ans = 1;
    for (; mu > 0; mu /= 2) {
        if (mu % 2 == 1) ans = (ans * a) % Mod;
        a = (a * a) % Mod;
    }
    return ans;
}

struct HashArray {
    vector<ll> a;
    vector<ll> hashA;
    ll Mod, base;
    int n;

    HashArray(int n, ll base = 137, ll Mod = 1e9 + 7) : n(n), Mod(Mod), base(base) {}

    void Input() {
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }

        // Tính toán hash array
        hashA.resize(n);
        hashA[0] = a[0] % Mod;
        for (int i = 1; i < n; i++) {
            hashA[i] = (hashA[i - 1] * base + a[i]) % Mod;
        }
    }

    ll GetHash(int l, int r) {
        if (l == 0) return hashA[r];
        return (hashA[r] - hashA[l - 1] * pw(base, r - l + 1, Mod) + Mod * Mod) % Mod;
    }
};

int main() {
    int na, nb; cin >> na >> nb;
    HashArray a(na), b(nb);
    a.Input();
    b.Input();

    int dem = 0;
    vector<int> index;
    for (int i = 0; i <= na - nb; i++) {
        if (a.GetHash(i, i + nb - 1) == b.GetHash(0, nb - 1)) {
            dem++;
            index.push_back(i + 1);
        }
    }

    cout << dem << '\n';
    for (int u : index) cout << u << ' ';
}
